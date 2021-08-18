#include <malloc.h>
#include <string.h>
#include "hash.h"

struct Pair
{
	size_t key_size;
	char key_value[0];
};

static struct Pair* pair_create(const char* key, const char* value)
{
	size_t key_size = strlen(key) + 1;
	size_t value_size = strlen(value) + 1;

	struct Pair* result = (struct Pair*)malloc(sizeof(size_t) + key_size + value_size);
	if (result == 0)
		return 0;

	result->key_size = key_size;
	strcpy_s(result->key_value, key_size, key);
	strcpy_s(result->key_value + result->key_size, value_size, value);

	return result;
}

inline static size_t pair_size(const struct Pair* pair)
{
	return pair->key_size + strlen(pair->key_value + pair->key_size);
}

inline static const char* pair_key(const struct Pair* pair)
{
	return pair->key_value;
}

inline static const char* pair_value(const struct Pair* pair)
{
	return pair->key_value + pair->key_size;
}

inline static void pair_free(struct Pair* pair)
{
	free(pair);
}

static struct ListNode* create_node_pair(const void* value)
{
	size_t buffer_size = pair_size(value);
	struct ListNode* result = malloc(sizeof(struct ListNode) + buffer_size);
	if (result == 0)
		return 0;

	memcpy(result->value, value, buffer_size);

	return result;
}

static int compare_pair(const void* a, const void* b)
{
	return strcmp(pair_key(a), pair_key(b));
}

struct Hash* hash_create_string()
{
	const size_t initial_size = 128;
	struct Hash* result = (struct Hash*)malloc(sizeof(struct Hash) + initial_size * sizeof(struct List));

	if (result == 0)
		return 0;

	result->capacity = initial_size;
	result->size = 0;

	for (size_t i = 0; i < initial_size; i++) {
		result->table[i].head = 0;
		result->table[i].create = create_node_pair;
		result->table[i].compare = compare_pair;
	}

	return result;
}

static size_t compute_hash(const char* string)
{
	size_t result = 16769023;
	size_t power = 1;

	while (*string != '\0')
		result += (power *= 53) * *string++;

	return result;
}

static void insert_or_update_pair(struct List* list, struct Pair* pair)
{
	struct ListNode* old_node;
	if (list_try_find(list, pair_key(pair), &old_node)) {
		struct ListNode* new_node = create_node_pair(pair);
		list_change_node(list, old_node, new_node);
		free(old_node);
	}
	else {
		list_add(list, pair);
	}
}

void hash_set(struct Hash* hash, const char* key, const void* value)
{
	if (hash == 0 || key == 0 || value == 0)
		return;

	size_t index = compute_hash(key) % hash->capacity;
	struct List* list = hash->table + index;

	struct Pair* pair = pair_create(key, value);
	insert_or_update_pair(list, pair);
	pair_free(pair);
}

int hash_try_get(struct Hash* hash, const char* key, void* value);
void hash_for_each(struct Hash* hash, void (*proc)(const void* key, const void* value));
void hash_free();


