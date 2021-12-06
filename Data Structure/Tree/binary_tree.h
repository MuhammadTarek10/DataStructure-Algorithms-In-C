#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Tree Tree;
typedef struct TreeNode TreeNode;

struct Tree{
    TreeNode* root;
    int size;
};

struct TreeNode{
    int value;
    TreeNode* left_child;
    TreeNode* right_child;
};

Tree* create_tree(){
    Tree *t = (Tree*)malloc(sizeof(Tree));
    t->root = NULL;
    t->size = 0;
    return t;
}

bool is_empty(Tree* t){
    return (t->size==0);
}

void insert_to_tree(Tree* t, int value){
    TreeNode *newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->right_child = newNode->left_child = NULL;
    newNode->value = value;
    if(is_empty(t)){
        t->root = newNode;
        t->size++;
        return;
    }
    TreeNode *root = t->root;
    while(true){
        if(value<root->value){
            if(root->left_child==NULL){
                root->left_child = newNode;
                t->size++;
                break;
            }
            else
                root = root->left_child;
        }
        else if(value>root->value){
            if(root->right_child==NULL){
                root->right_child = newNode;
                t->size++;
                break;
            }
            else
                root = root->right_child;
        }
        else
            break;
    }
}

void print_tree(TreeNode* root){
    if(root==NULL)
        return;
    
    printf("[%d]\n", root->value);
    print_tree(root->left_child);
    print_tree(root->right_child);
}

