#ifndef HASH_H
#define HASH_H

#define HASH_INICIAL 2166136261
#define MULTIPLICADOR_HASH 16777619

unsigned int hash(char* string, int max_hash);

#endif // HASH_H