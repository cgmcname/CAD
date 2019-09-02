// C program for different tree traversals 
#include <iostream> 
#include<bits/stdc++.h> 
using namespace std; 

/* A binary tree node has data, pointer to left child 
and a pointer to right child */
struct Node 
{ 
	char data; 
	struct Node* left, *right, *start; 
	Node(char data) 
	{ 
		this->data = data; 
		left = right = NULL; 
	} 
}; 

/* Given a binary tree, print its nodes according to the 
"bottom-up" postorder traversal. */
void printPostorder(struct Node* node) 
{ 
	if (node == NULL) 
		return; 

	// first recur on left subtree 
	printPostorder(node->right); 

	// then recur on right subtree 
	printPostorder(node->left); 

	// now deal with the node 
	cout << node->data << " "; 
} 

bool isOperator(char c) 
{ 
	if (c == 'H' || c == 'V' ) 
		return true; 
	return false; 
} 

Node* constructTree(char postfix[]) 
{ 
	stack<Node *> st; 
	Node *t, *t1, *t2; 
        
        

	// Traverse through every character of 
	// input expression 
	for (int i=0; i<strlen(postfix); i++) 
	{ 
		// If operand, simply push into stack 
		if (!isOperator(postfix[i])) 
		{ 
                    if (t->right != *start)
			t = new Node(postfix[i]); 
			//st.push(t); 
		} 
		else // operator 
		{ 
			t = new Node(postfix[i]); 

			// Pop two top nodes 
			t1 = st.top(); // Store top 
			st.pop();	 // Remove top 
			t2 = st.top(); 
			st.pop(); 

			// make them children 
			t->right = t1; 
			t->left = t2; 

			// Add this subexpression to stack 
			st.push(t); 
		} 
	} 

	// only element will be root of expression 
	// tree 
	t = st.top(); 
	st.pop(); 

	return t; 
}

/* Driver program to test above functions*/
int main() 
{ 
	
        char postfix[] = "1 6 H 2 V 7 5 V H 3 4 H V"; 
	Node* r = constructTree(postfix);
    
    
    /*struct Node *root = new Node(1); 
	root->left			 = new Node(2); 
	root->right		 = new Node(3); 
	root->left->left	 = new Node(4); 
	root->left->right = new Node(5); 

	 

	cout << "\nPostorder traversal of binary tree is \n";*/ 
	printPostorder(r); 

	return 0; 
} 
