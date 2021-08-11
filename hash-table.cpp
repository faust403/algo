#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int hash(const char* str)
{
  unsigned int result = 0;
  unsigned int power = 1;

   while (*str != '\0')
     result += (power *= 53) * (unsigned int)*str++;

  return result;
}

struct Node {
  char *key;
  char *value;

  struct Node *next;
};

const int hash_size = 1024;
struct Node *hash_table[hash_size];

void add(const char *key, const char *value)
{
  unsigned int index = hash(key) % hash_size;
  struct Node *node = (struct Node *)malloc(sizeof(struct Node));

  node->key = (char *)malloc(strlen(key) + 1);
  strcpy(node->key, key);

  node->value = (char *)malloc(strlen(value) + 1);
  strcpy(node->value, value);

  node->next = NULL;

  if (hash_table[index] == NULL) {
    hash_table[index] = node;
  }
  else {
    struct Node *current = hash_table[index];
    while (current->next != NULL)
      current = current->next;

    current->next = node;
  }
}

struct Node *find_node(const char *key)
{
  unsigned int index = hash(key) % hash_size;
  struct Node *current = hash_table[index];

  while (current != NULL) {
    if (strcmp(current->key, key) == 0)
      return current;

    current = current->next;
  }

  return NULL;
}

char *find2(const char *key)
{
  struct Node *node = find_node(key);

  if (node == NULL)
    return NULL;

  return node->value;
}

char* find(const char * key)
{
  unsigned int index = hash(key) % hash_size;
  struct Node * current = hash_table[index]; //Найти список в слотах

  while(current!=NULL)
  {
    if(strcmp(key, current->key)==0)return current->value;
    current=current->next;
  }
  return NULL;
}

void removeNode(struct Node * node)
{
  node = NULL;
  free(node);
  while(node != NULL)
  {
    node = node -> next;
  }
}

int main(int arg, char** argv) {
  const char * str1 = "Hello";
  const char * str2 = ", world!";

  add(str1, str2);
  
  printf("%s\n", find(str1));
  printf("%s\n", find2(str1));
  
  printf("%s\n", find2("not existing key"));
  printf("%s\n", find("not existing key"));
  add("str1", "str2");

  removeNode(find_node(str1));
  printf("%s\n", find("str1"));

  return 0;
}


