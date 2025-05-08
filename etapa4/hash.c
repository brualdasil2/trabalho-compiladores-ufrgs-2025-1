#include "hash.h"
#include <string.h>

unsigned int hash(char* string, int max_hash) {
    unsigned int hash_val = HASH_INICIAL;
    for (int i = 0; i < strlen(string); i++) {
        hash_val = (hash_val ^ string[i])*MULTIPLICADOR_HASH;
    }
    return hash_val % max_hash;
}