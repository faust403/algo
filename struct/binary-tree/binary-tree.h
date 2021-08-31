#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

struct BTNode
{
	char * value;
	unsigned int key;

	struct BTNode * parent;

	struct BTNode * childLeft;
	struct BTNode * childRight;
};

struct BTree
{
	struct BTNode * root;
};

struct BTNode * create_BTNode(unsigned int key, char * value);
struct BTree * create_BTree();
char * BTfind(struct BTree * btree, unsigned int key);
void add_to_BTree(struct BTree * bt, unsigned int key, char * value);
void remove_from_BTree(struct BTree * bt, unsigned int key);

#endif
