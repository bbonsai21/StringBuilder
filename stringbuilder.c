#include <limits.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stringbuilder.h"

/* SETUP */

#define lengthof( arr ) ( sizeof( arr ) / sizeof( ( arr )[0] ) )

#define DEFAULT_CAPACITY 10

typedef enum
{
	SB_STRING,
	SB_FLOAT,
	SB_INT
} sb_types_t;

typedef struct
{
	union
	{
		char* strval;
		int ival;
		float fval;
	} value;
	sb_types_t type;
} sb_elem_t;

typedef struct StringBuilder
{
	size_t size;
	size_t capacity;
	sb_elem_t** pool;
} StringBuilder;

/* MAIN */

StringBuilder* sb_new( void )
{
	StringBuilder* sb = malloc( sizeof( StringBuilder ) );
	if ( !sb )
		return nullptr;

	sb->pool = malloc( DEFAULT_CAPACITY * sizeof( sb_elem_t* ) );
	if ( !sb->pool )
		return nullptr;

	sb->size = 0;
	sb->capacity = DEFAULT_CAPACITY;

	return sb;
}

StringBuilder* sb_new_capacity_of( size_t capacity )
{
	if ( capacity <= 0 )
		return nullptr;

	StringBuilder* sb = malloc( sizeof( StringBuilder ) );
	if ( !sb )
		return nullptr;

	sb->pool = malloc( capacity * sizeof( sb_elem_t* ) );
	if ( !sb->pool )
		return nullptr;

	sb->size = 0;
	sb->capacity = capacity;

	return sb;
}

#define EXPANSION_FACTOR 2

/**
 * Expands StringBuilder object's capacity according to the expansion flag value.
 * Upon failure returns nullptr, but original object is preserved.
 * @param sb StringBuilder object pointer
 * @return StringBuilder* pointer to the expanded StringBuilder object
 * @see CAPACITY_EXPANSION_FACTOR
 */
StringBuilder* expand_capacity( StringBuilder* sb )
{
	if ( !sb )
		return nullptr;

	size_t newCapacity = ( sb->capacity * 2 );
	sb_elem_t** new_pool = realloc( sb->pool, newCapacity * sizeof( sb_elem_t* ) );
	if ( !new_pool )
		return nullptr;

	sb->pool = new_pool;
	sb->capacity = newCapacity;
	return sb;
}

StringBuilder* sb_appends( StringBuilder* sb, char* str )
{
	if ( !sb || !str )
		return nullptr;

	if ( sb->size >= sb->capacity )
		if ( !expand_capacity( sb ) )
			return nullptr;

	sb_elem_t* new_elem = malloc( sizeof( sb_elem_t ) );
	if ( !new_elem )
		return nullptr;

	new_elem->value.strval = str;
	new_elem->type = SB_STRING;

	sb->pool[sb->size++] = new_elem;

	return sb;
}

StringBuilder* sb_appendf( StringBuilder* sb, float f )
{
	if ( !sb )
		return nullptr;

	if ( sb->size >= sb->capacity )
		if ( !expand_capacity( sb ) )
			return nullptr;

	sb_elem_t* new_elem = malloc( sizeof( sb_elem_t ) );
	if ( !new_elem )
		return nullptr;

	new_elem->type = SB_FLOAT;
	new_elem->value.fval = f;

	sb->pool[sb->size++] = new_elem;

	return sb;
}

StringBuilder* sb_appendi( StringBuilder* sb, int i )
{
	if ( !sb )
		return nullptr;

	if ( sb->size >= sb->capacity )
		if ( !expand_capacity( sb ) )
			return nullptr;

	sb_elem_t* new_elem = malloc( sizeof( sb_elem_t ) );
	if ( !new_elem )
		return nullptr;

	new_elem->type = SB_INT;
	new_elem->value.ival = i;

	sb->pool[sb->size++] = new_elem;

	return sb;
}

void sb_free( StringBuilder* sb )
{
	if ( !sb )
		return;

	for ( int i = 0; i < sb->size; i++ )
		free( sb->pool[i] );

	free( sb->pool );
}

#define LEN_BUFF_SIZE 32
size_t sb_length( StringBuilder* sb )
{
	if ( !sb )
		return 0;

	char len_buff[LEN_BUFF_SIZE];
	sb_elem_t* curr;
	size_t len = 0;
	for ( int i = 0; i < sb->size; i++ )
	{
		curr = sb->pool[i];
		if ( curr->type == SB_STRING )
			len += strlen( curr->value.strval );
		else if ( curr->type == SB_INT )
		{
			snprintf( len_buff, LEN_BUFF_SIZE, "%d", curr->value.ival );
			len += strlen( len_buff );
		}
		else if ( curr->type == SB_FLOAT )
		{
			snprintf( len_buff, LEN_BUFF_SIZE, "%f", curr->value.fval );
			len += strlen( len_buff );
		}
	}

	return len;
}

#define BUILD_DEFAULT_ALLOCATION 100
char *sb_build( StringBuilder* sb )
{
	if ( !sb )
		return nullptr;
		
	char len_buff[LEN_BUFF_SIZE];
	size_t allocated = BUILD_DEFAULT_ALLOCATION;
	char *str = malloc( allocated );
	sb_elem_t* curr;
	size_t curr_length = 0;
	for ( int i = 0; i < sb->size; i++ )
	{
		curr = sb->pool[i];
		if ( curr->type == SB_STRING )
			curr_lenght = strlen( curr->value.strval );
		else if ( curr->type == SB_INT )
		{
			snprintf( len_buff, LEN_BUFF_SIZE, "%d", curr->value.ival );
			curr_len += strlen( len_buff );
		}
		else if ( curr->type == SB_FLOAT )
		{
			snprintf( len_buff, LEN_BUFF_SIZE, "%f", curr->value.fval );
			len += strlen( len_buff );
		}
	}
}




