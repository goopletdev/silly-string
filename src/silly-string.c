#include "silly-string.h"

#define SUBTREES_LEN 128

typedef struct silly__nodeT silly_node;
struct silly__nodeT {
    void* value;
    struct silly__nodeT** subtrees;
};

void silly_string_free(silly_string* root) {
    if (!root) {
        return;
    }
    for (int i = 0; i < SUBTREES_LEN; i++) {
        silly_string_free(root->subtrees[i]);
    }
    free(root->subtrees);
    free(root);
}

silly_node* silly_string_init(void) {
    silly_node* node = (silly_node*)malloc(sizeof(silly_node));
    node->value = NULL;
    node->subtrees = (silly_node**)calloc(SUBTREES_LEN, sizeof(silly_node*));
    return node;
}

void* silly_string_get(silly_string* root, char* key) {
    silly_string* current = root;
    char c;
    while ((c = *(key++))) {
        current = current->subtrees[(int)c];
        if (current == NULL) {
            return NULL;
        }
    }
    return current->value;
}

void* silly_string_get_caps(silly_string* root, char* key) {
    silly_string* current = root;
    char c;
    while ((c = *(key++))) {
        if (c >= 'a' && c <= 'z') {
            c -= 32;
        }
        current = current->subtrees[(int)c];
        if (current == NULL) {
            return NULL;
        }
    }
    return current->value;
}

void silly_string_insert(silly_string* root, char* key, void* value) {
    silly_string* current = root;
    char c;
    while ((c = *(key++))) {
        if (!current->subtrees[(int)c]) {
            current->subtrees[(int)c] = silly_string_init();
        }
        current = current->subtrees[(int)c];
    }
    current->value = value;
}

void silly_string_insert_caps(silly_string* root, char* key, void* value) {
    silly_string* current = root;
    char c;
    while ((c = *(key++))) {
        if (c >= 'a' && c <= 'z') {
            c -= 32;
        }
        if (!current->subtrees[(int)c]) {
            current->subtrees[(int)c] = silly_string_init();
        }
        current = current->subtrees[(int)c];
    }
    current->value = value;
}

void* silly_string_get_case_insensitive(silly_string* root, char* key) {
    char c = *(key++);
    if (!c) {
        return root->value;
    }
    silly_string* current = root->subtrees[(int)c];
    if (!current) {
        if (c >= 'A' && c <= 'Z') {
            current = root->subtrees[c + 32];
            if (!current) {
                return NULL;
            } else {
                return silly_string_get_case_insensitive(current, key);
            }
        } else if (c >= 'a' && c <= 'z') {
            current = root->subtrees[c - 32];
            if (!current) {
                return NULL;
            } else {
                return silly_string_get_case_insensitive(current, key);
            }
        } else {
            return NULL;
        }
    }
    void* value = silly_string_get_case_insensitive(current, key); 
    if (value) {
        return value;
    } else if (c >= 'A' && c <= 'Z') {
        current = root->subtrees[c + 32];
        if (!current) {
            return NULL;
        } else {
            return silly_string_get_case_insensitive(current, key);
        }
    } else if (c >= 'a' && c <= 'z') {
        current = root->subtrees[c - 32];
        if (!current) {
            return NULL;
        } else {
            return silly_string_get_case_insensitive(current, key);
        }
    } else {
        return NULL;
    }
}

