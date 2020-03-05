#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

#include "bst.h"

using namespace std;

void tree::read_data(tree *&root)
{
    vector <string> temp;
    string input_file, in_data;

    cout << "Enter the file you would like to put in tree: ";
    cin >> input_file;

    fstream input;
    input.open(input_file,ios::in);

    if(!input)
    {
        cout<<  endl << "Error opening file." << endl << endl;
        return;
    }
    while(!input.eof())
    {
        getline(input, in_data, ' ');
        //Using modified Algo on geeksforgeeks to remove punctuation        
        for (int i = 0, len = in_data.size(); i < len; i++) 
        {  
            if (ispunct(in_data[i]) && in_data[i] != '-') 
            { 
                in_data.erase(i--, 1); 
                len = in_data.size(); 
            } 
        }
        //Removing Blank spaces
        in_data.erase(remove_if(in_data.begin(), in_data.end(), ::isspace), in_data.end()); 
        in_data[0] = toupper(in_data[0]);
        temp.push_back(in_data);
    }

    for(int i = 0; i< temp.size(); i++)
    {
        if(temp[i].size()!= 0)
        {
            insert_node(root, temp[i]);
        }
    }
    input.close();
}

void tree::createtree(tree *& root)
{
  root = new tree;
  root -> word = "";
  root -> count = 1;
  root -> left = NULL;
  root -> right = NULL;
}

void tree::insert_node(tree *root, string in)
{
  tree *knew, *c, *parent;
    
    if(!emptytree(root))
    {
        knew = new tree;
        knew -> word = in;
        knew -> count = 1;
        knew -> left = NULL;
        knew -> right = NULL;
        c = root;
        parent = NULL;

        while(c != NULL)
        {
            parent = c;
            if(knew -> word == c -> word) 
            {
                c->count++;
                return;
            }
            if(knew -> word < c -> word) c = c -> left;
            else c = c -> right;
        }
        if(knew -> word < parent -> word) parent -> left = knew;
        else parent -> right = knew;
    }
    else root -> word = in;
}

void tree::print_inorder(tree *c)
{
    if(c!=NULL)
  {
    print_inorder(c->left);
    cout << c->count << " " << c->word << endl;
    print_inorder(c->right);
  }
}

void tree::print_preorder(tree *c)
{
     if(c!=NULL)
     {
        cout << c->count << " " << c->word << endl;
        print_preorder(c->left);
        print_preorder(c->right);
    }   
}

void tree::print_postorder(tree *c)
{
     if(c!=NULL)
     {
        print_postorder(c->left);
        print_postorder(c->right);
        cout << c->count << " " << c->word << endl;
    }   
}

void tree::delete_tree(tree *root){
    if(root==NULL) return;
    if(root -> left != NULL) delete_tree(root->left);
    if(root -> right != NULL) delete_tree(root->right);
    delete root;
}

int tree::search_tree(tree *c, string word)
{
    if(c != NULL)
    {
        if(c -> word == word) return c -> count;

        if(c -> word < word) return search_tree(c -> left, word);
        else return search_tree(c -> right, word);
    }
    else return 0;
}