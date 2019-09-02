#include <iostream> 
#include<bits/stdc++.h> 
using namespace std; 
  
  
  
  struct TreeNode {
              // An object of type TreeNode represents one node
              // in a binary tree of strings.

         char item;      // The data in this node.
         TreeNode left;    // Pointer to left subtree.
         TreeNode right;   // Pointer to right subtree.

         TreeNode(char str) {
                // Constructor.  Make a node containing str.
            item = str;
            left = NULL;
            right = NULL;
         }

      };  // end struct Treenode
      
void treeInsert(TreeNode *&root, char newItem) {
              // Add the item to the binary sort tree to which the parameter
              // "root" refers.  Note that root is passed by reference since
              // its value can change in the case where the tree is empty.
          if ( root == NULL ) {
                 // The tree is empty.  Set root to point to a new node containing
                 // the new item.  This becomes the only node in the tree.
             root = new TreeNode( newItem );
                     // NOTE:  The left and right subtrees of root
                     // are automatically set to NULL by the constructor.
                     // This is important!
             return;
          }
          else if ( newItem < root->item ) {
             treeInsert( root->left, newItem );
          }
          else {
             treeInsert( root->right, newItem );
          }
       }  // end treeInsert()
