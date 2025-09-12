# silly-string.h
Simple single-header trie data structure that allows for case-sensitive and case-insensitive lookup of both case-sensitive and case-insensitive key-value insertions. 
## Usage
Simply initialize a root `silly_string` node with `silly_init()`.

From there, insert key-value pairs with `silly_insert(root, key, val)`.

Case-sensitive entries can be retrieved with `silly_get(root, key)`, and case-insensitive lookups can be performed with the recursive search `silly_get_ci_from_case_sensitive(root, key)`. Case-insensitive lookups using this function will prefer keys that match the casing of the lookup string.

If you know that a key will only be used for case-insensitive lookups, instead insert the key-value pair with `silly_insert_ci(root, key, value)` and fetch it with `silly_get_ci(root, key)`.
## Tests
Tests use the [Unity testing library from ThrowTheSwitch](https://github.com/ThrowTheSwitch/Unity).
If you clone that repo into `tests/`, running `make` in the tests directory will build `silly-string-test`.
## Todo:
- Add prefix check
- separate case-insensitive insertions and lookups into separate file using smaller subtrees array
