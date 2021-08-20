#ifndef _HASH_H_
#define _HASH_H_

#include <stdlib.h>
#include "list.h"

struct Hash
{
	size_t size;
	size_t capacity;
	struct List table[0];
};

struct Hash* hash_create_string();
void hash_set(struct Hash* hash, const char* key, const void* value);
int hash_try_get(struct Hash* hash, const char* key, const char** value_ref);
void hash_for_each(struct Hash* hash, void (*proc)(const void* key, const void* value));
void hash_free(struct Hash* hash);

#endif
