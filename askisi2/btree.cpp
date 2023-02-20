#include "btree.h"
#include "thread.h"
#include <iostream>
#include <string>
using namespace std;

//FUNCTIONS FOR LIST OF POSTS IN EACH TREE NODE

PostList::PostList() {
    head = NULL;
    tail = NULL;
}

void PostList::add_node(post *p) {
    PostNode *tmp = new PostNode;
    tmp->data = p;
    tmp->next = NULL;

    if (head == NULL) {
        head = tmp;
        tail = tmp;
    } else {
        tail->next = tmp;
        tail = tail->next;
    }
}

void PostList::printList() const{
    PostNode *tmp;
    tmp = head;
    while (tmp != NULL) {
        tmp->data->PrintPost();
        tmp = tmp->next;
    }
}

//FUNCTIONS FOR TREE


btree::btree(thread *pThread)
{
    root=NULL;
    pThread->InsertPosts(this);
}

btree::~btree()
{
    destroy_tree();
}

void btree::destroy_tree()
{
    destroy_tree(root);
}

void btree::destroy_tree(BTreeNode *leaf)
{
    if(leaf!=NULL)
    {
        destroy_tree(leaf->left);
        destroy_tree(leaf->right);
        PostNode *tmp = leaf->LeafList.head, *deltmp;
        while(tmp!=NULL){           //this loop only runs when deleting the Creator Tree and not for each individual thread tree, as that would delete PostLists that we still need
            deltmp = tmp;
            tmp = tmp->next;
            delete deltmp;
        }
        delete leaf;
    }
}

void btree::insert(post *p)
{
    if(root!=NULL) {
        insert(p, root);
    }
    else
    {
        root=new BTreeNode;
        root->LeafList.add_node(p);

        root->key_value = p->getCreator();
        root->left=NULL;
        root->right=NULL;
    }
}

void btree::insert(post *p, BTreeNode *leaf)
{
    if(p->getCreator().compare(leaf->key_value) < 0)
    {
        if(leaf->left!=NULL)
            insert(p, leaf->left);
        else
        {
            leaf->left=new BTreeNode;
            leaf->left->LeafList.add_node(p);

            leaf->left->key_value = p->getCreator();
            leaf->left->left=NULL;
            leaf->left->right=NULL;
        }
    }
    else if(p->getCreator().compare(leaf->key_value) > 0)
    {
        if(leaf->right!=NULL)
            insert(p, leaf->right);
        else
        {
            leaf->right=new BTreeNode;

            leaf->right->LeafList.add_node(p);
            leaf->right->key_value = p->getCreator();
            leaf->right->left=NULL;
            leaf->right->right=NULL;
        }
    }
    else
    {
        leaf->LeafList.add_node(p);
    }
}

void btree::inorder_print() const{
    inorder_print(root);
    cout << endl;
}

void btree::inorder_print(BTreeNode *leaf) const{
    if(leaf != NULL){
        inorder_print(leaf->left);
        cout << endl << "-->" << leaf->key_value << " with post(s):" << endl;
        leaf->LeafList.printList();
        inorder_print(leaf->right);
    }
}

void btree::enhance(btree &TTree) {
    if (TTree.root != NULL) {
        BTreeNode *TTreeNode = TTree.root;
        enhance(TTreeNode);
    }
}

void btree::enhance(BTreeNode *TTreeNode) {
    if(TTreeNode != NULL){
        enhance(TTreeNode->left);
        AddLeaf(TTreeNode, root);
        enhance(TTreeNode->right);
    }
}

void btree::AddLeaf(BTreeNode *TTreeNode, BTreeNode *CreatorTreeNode)
{
    if(TTreeNode->key_value.compare(CreatorTreeNode->key_value) < 0)
    {
        if(CreatorTreeNode->left!=NULL)
            AddLeaf(TTreeNode, CreatorTreeNode->left);
        else
        {
            CreatorTreeNode->left = new BTreeNode;
            CreatorTreeNode->left->key_value = TTreeNode->key_value;
            CreatorTreeNode->left->LeafList = TTreeNode->LeafList;
            TTreeNode->LeafList.head =  TTreeNode->LeafList.tail = NULL;        //so that the btree destructor won't delete the PostList that is now part of the creator tree
            CreatorTreeNode->left->left = NULL;
            CreatorTreeNode->left->right = NULL;
        }
    }
    else if(TTreeNode->key_value.compare(CreatorTreeNode->key_value) > 0)
    {
        if(CreatorTreeNode->right!=NULL)
            AddLeaf(TTreeNode, CreatorTreeNode->right);
        else
        {
            CreatorTreeNode->right = new BTreeNode;
            CreatorTreeNode->right->key_value = TTreeNode->key_value;
            CreatorTreeNode->right->LeafList = TTreeNode->LeafList;
            TTreeNode->LeafList.head =  TTreeNode->LeafList.tail = NULL;        //so that the btree destructor won't delete the PostList that is now part of the creator tree
            CreatorTreeNode->right->left = NULL;
            CreatorTreeNode->right->right = NULL;
        }
    }
    else
    {
            CreatorTreeNode->LeafList.tail->next = TTreeNode->LeafList.head;
            CreatorTreeNode->LeafList.tail = TTreeNode->LeafList.tail;
            TTreeNode->LeafList.head =  TTreeNode->LeafList.tail = NULL;        //so that the btree destructor won't delete the PostList that is now part of the creator tree

    }
}