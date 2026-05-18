#include <stdio.h>
#include <stdlib.h>

#include "../dymeman.h"
#include "stringbuilder.h"

int main( void )
{
	StringBuilder* sb = sb_new_capacity_of( 1 );
	sb_appends( sb, "Goodbye my past - here comes a vague taste!" );
	sb_appends( sb, "Hello, World!" );
	sb_appendf( sb, 3.14 );
	sb_appendi( sb, 69 );

	sb_appends( sb, "Goodbye my past - here comes a vague taste!" );
	sb_appends( sb, "Hello, World!" );
	sb_appendf( sb, 3.14 );
	sb_appendi( sb, 69 );

	sb_appends( sb, "Goodbye my past - here comes a vague taste!" );
	sb_appends( sb, "Hello, World!" );
	sb_appendf( sb, 3.14 );
	sb_appendi( sb, 69 );

	sb_free( sb );
	free( sb );

	return 0;
}