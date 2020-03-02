//Chris Stromberg
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct tree
{
    string word;
    int count;
    tree *left, *right;
};

void createtree(tree *& root);
void insert_node(tree *root, string in);
char us_menu(char &menu);
void print_node(tree *c);
void read_data(tree *& root);
void delete_tree(tree *root);
bool emptytree(tree *root) {return root -> word == "";}


int main()
{
    tree *root;
    char menu;
    
    createtree(root);
    do
    {

        us_menu(menu);
        switch (menu)
        {
            case 'C':
                if(emptytree(root))
                {
                    read_data(root);
                }
                else cout << endl << endl << "Previous tree needs to be deleted first." << endl << endl;
                break;
            case 'P':
                if(!emptytree(root))
                {
                    cout << endl << endl << "Contents of tree are\n" << "#  word\n";
                    print_node(root);
                    cout << endl << endl;
                }
                else cout << endl << endl << "The tree is empty!"<< endl << endl;
                break;
            case 'D':
                if(!emptytree(root)) 
                {
                    delete_tree(root);
                    createtree(root);
                }
                else cout << endl << endl << "The tree is already empty." << endl << endl;
                break;
            case 'E':
                break;
            default:
                cout << endl << "Invalid Selction!" << endl << endl;
                break;
        }
    }while(menu != 'E');

    return 0;
}

char us_menu(char &menu)
{
    cout << "Please enter your choice\n" << "Enter C to create tree\n" <<"Enter P to print tree\n"
     << "Enter D to delete tree\n" << "Enter E to exit\n";
     cin >> menu;
     menu = toupper(menu);
     return menu;
}

void read_data(tree *&root)
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

void createtree(tree *& root)
{
  root = new tree;
  root -> word = "";
  root -> count = 1;
  root -> left = NULL;
  root -> right = NULL;
}

void insert_node(tree *root, string in)
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

void print_node(tree *c)
{
    if(c!=NULL)
  {
    print_node(c->left);
    cout << c->count << " " << c->word << endl;
    print_node(c->right);
  }
}

void delete_tree(tree *root){
    if(root==NULL) return;
    if(root -> left != NULL) delete_tree(root->left);
    if(root -> right != NULL) delete_tree(root->right);
    delete root;
}