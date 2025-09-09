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
void silly_string_free(silly_string* root);

/**
 * Initialize the root node of a silly_string
 */
silly_string* silly_string_init();

/**
 * Insert a [key, val] pair into a silly_string
 */
void silly_string_insert(silly_string* root, char* key, void* value);

/**
 * Insert a [key, val] pair for case-insensitive lookup.
 * Sets all lowercase letters to uppercase
 */
void silly_string_insert_caps(silly_string* root, char* key, void* value);

/**
 * Look up value at a given key, or return NULL if key doesn't exist
 */
void* silly_string_get(silly_string* root, char* key);

/**
 * Look up value at a given key set to uppercase;
 * for use with case-insensitive insertions
 */
void* silly_string_get_caps(silly_string* root, char* key);

/**
 * Look up value at a case-insensitive key, or NULL if it doesn't exist
 */
void* silly_string_get_case_insensitive(silly_string* root, char* key);

#endif // SILLY_STRING_H
