
//Chris Stromberg
#include <iostream>
#include <string>

#include "bst.h"

using namespace std;

char us_menu(char &menu);

int main()
{
    tree *root, x;
    string word_search;
    int temp;
    int count[10];
    string word[10];
    char menu;
    
    x.createtree(root);
    do
    {

        us_menu(menu);
        switch (menu)
        {
            case 'C':
                if(x.emptytree(root))
                {
                    x.read_data(root);
                    cout << endl << endl;
                }
                else cout << endl << endl << "Previous tree needs to be deleted first." << endl << endl;
                break;
            case 'I':
                if(!x.emptytree(root))
                {
                    cout << endl << endl << "Contents of tree in-order are\n" << "#  word\n";
                    x.print_inorder(root);
                    cout << endl << endl;
                }
                else cout << endl << endl << "The tree is empty!"<< endl << endl;
                break;
            case 'P':
                if(!x.emptytree(root))
                {
                    cout << endl << endl << "Contents of tree in pre-order are\n" << "#  word\n";
                    x.print_preorder(root);
                    cout << endl << endl;
                }
                else cout << endl << endl << "The tree is empty!"<< endl << endl;
                break;
            case 'D':
                if(!x.emptytree(root)) 
                {
                    x.delete_tree(root);
                    x.createtree(root);
                }
                else cout << endl << endl << "The tree is already empty." << endl << endl;
                break;
            case 'R':
                if(!x.emptytree(root))
                {
                    cout << endl << endl << "Contents of tree in post-order are\n" << "#  word\n";
                    x.print_postorder(root);
                    cout << endl << endl;
                }
                else cout << endl << endl << "The tree is empty!"<< endl << endl;
                break;
            case 'E':
                break;
            case 'S':
                    if(!x.emptytree(root))
                    {
                        cout << "Please enter word to search for: \n";
                        cin >> word_search;

                        word_search[0] = toupper(word_search[0]);
                        
                        temp = x.search_tree(root, word_search);
                        if(temp != 0) cout << endl << word_search << " appeared " << temp << " times." << endl << endl;
                        else cout << word_search << " not found\n";
                    }
                    else cout << endl << endl << "The tree is empty!"<< endl << endl;
                break;
            case 'T':
                for(int i = 0; i < 10; i++) { count[i] = 0; }
                x.print_top(root, count, word);
                cout << endl << endl << "The top ten words and the occurrence are: \n";
                for(int i = 0; i < 10; i++) { cout << word[i] << " occured " << count[i] << " times\n"; }
                cout << endl << endl;
                break;
            case 'W':
                cout << endl << "Please enter the word to be deleted:\n";
                cin >> word_search;
                
                word_search[0] = toupper(word_search[0]);

                x.remove_word(root, word_search);
                cout << endl << endl;
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
    cout << "Please enter your choice\n" << "Enter C to create tree\n" <<"Enter P to print tree in pre-order\n"
     << "Enter I to print tree in in-order\n" << "Enter R to print tree in post-order\n" << "Enter T to print the top ten words\ne"
     << "Enter D to delete the entire tree\n" << "Enter S to search for a specific word\n" 
     << "Enter W to delete a word from the tree\n" << "Enter E to exit\n";
     cin >> menu;
     menu = toupper(menu);
     return menu;
}