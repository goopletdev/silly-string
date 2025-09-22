#ifndef SILLY_STRING_H
#define SILLY_STRING_H

#include <stdio.h>
#include <stdlib.h>

/**
 * Trie data structure
 */
typedef struct silly__nodeT silly_string;

/**
 * Recursively frees silly_string node
 */
void silly_free(silly_string* root);

/**
 * Initialize the root node of a silly_string
 */
silly_string* silly_init();

/**
 * Insert a [key, val] pair into a silly_string
 */
void silly_insert(silly_string* root, const char* key, void* value);

/**
 * Insert a [key, val] pair for case-insensitive lookup.
 * Sets all lowercase letters to uppercase
 */
void silly_insert_ci(silly_string* root, const char* key, void* value);

/**
 * Look up value at a given key, or return NULL if key doesn't exist
 */
void* silly_get(silly_string* root, const char* key);

/**
 * Look up value at a given key set to uppercase;
 * for use with case-insensitive insertions
 */
void* silly_get_ci(silly_string* root, const char* key);

/**
 * Look up value at a case-insensitive key, or NULL if it doesn't exist
 */
void* silly_get_ci_from_case_sensitive(silly_string* root, const char* key);

#endif // SILLY_STRING_H
