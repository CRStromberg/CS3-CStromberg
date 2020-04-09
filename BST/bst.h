#pragma once
#include <string>

using namespace std;

class tree
{
    private:
        string word;
        int count;
        tree *left, *right;
    public:
        void createtree(tree *& root);
        void insert_node(tree *root, string in);
        void print_inorder(tree *c);
        void print_preorder(tree *c);
        void print_postorder(tree *c);
        void print_top(tree *c);
        void read_data(tree *& root);
        void delete_tree(tree *root);
        int search_tree(tree *c, string word);
        bool emptytree(tree *root) {return root -> word == "";}
};
