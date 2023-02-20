#ifndef BTREE_H
#define BTREE_H

#include <iostream>
#include <string>
#include "post.h"
class thread;
using namespace std;

struct PostNode{
    post *data;
    PostNode *next;
};

class PostList
{
public:
    PostNode *head,*tail;
    PostList();
    void add_node(post *);
    void printList() const;
};

struct BTreeNode
{
    string key_value;
    PostList LeafList;
    BTreeNode *left;
    BTreeNode *right;
};

class btree
{
public:
    btree(thread *);
    ~btree();

    void insert(post *);
    void inorder_print() const;
    void destroy_tree();
    void enhance(btree &);
private:
    void inorder_print(BTreeNode *) const;
    void destroy_tree(BTreeNode *);
    void insert(post *, BTreeNode *);
    void enhance(BTreeNode *);
    void AddLeaf(BTreeNode *, BTreeNode *);

    BTreeNode *root;
};

#endif
