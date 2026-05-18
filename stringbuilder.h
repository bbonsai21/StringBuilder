#pragma once
#include <stddef.h>

typedef struct StringBuilder StringBuilder;

/**
 * Creates and returns a new StringBuilder object with a default capacity.
 * @return StringBuilder
 * @see new_capacity_of
 */
extern StringBuilder* sb_new( void );

/**
 * Creates and returns a new StringBuilder object with a set capacity.
 * @param capacity the capacity of the StringBuilder (in bytes)
 * @return StringBuilder
 * @see new
 */
extern StringBuilder* sb_new_capacity_of( size_t capacity );

/**
 * Appends a variable amount of strings to the StringBuilder.
 * @param sb pointer to the StringBuilder object
 * @param ... vararg of strings
 * @see new
 */
extern StringBuilder* sb_appends( StringBuilder* sb, char* s );

/**
 * Appends a variable amount of floats to the StringBuilder.
 * @param sb pointer to the StringBuilder object
 * @param ... vararg of floats
 * @see new
 */
extern StringBuilder* sb_appendf( StringBuilder* sb, float f );

/**
 * Appends a variable amount of integers to the StringBuilder.
 * @param sb pointer to the StringBuilder object
 * @param ... vararg of strings
 * @see new
 */
extern StringBuilder* sb_appendi( StringBuilder* sb, int i );

/**
 * Builds and returns the accumulated string.
 * @param sb pointer to the StringBuilder object
 * @return char* the built string
 * @see new
 */
extern char* sb_build( StringBuilder* sb );

/**
 * Frees StringBuilder object's internal accumulated string. Does not free the StringBuilder object
 * itself.
 * @param sb pointer to the StringBuilder object
 * @see new
 */
extern void sb_free( StringBuilder* sb );

/**
 * Returns the length of the internal accumulated string. Strongly recommended not to use it, given
 * that it does inefficient intermediate memory allocations and de-allocations.
 * @param sb pointer to the StringBuilder object
 * @return size_t length of the built string
 * @see new
 * @see sb_build
 */
extern size_t sb_length( StringBuilder* sb );