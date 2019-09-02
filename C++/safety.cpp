// C++ program for expression tree 
#include<bits/stdc++.h> 
using namespace std; 

// An expression tree node 
struct et 
{ 
	char value; 
	et* left, *right; 
        int height;
        int width;
}; 

// A utility function to check if 'c' 
// is an operator 
bool isOperator(char c) 
{ 
	if (c == 'H' || c == 'V' ) 
		return true; 
	return false; 
} 

// Utility function to do inorder traversal 
void inorder(et *t) 
{ 
	if(t) 
	{ 
		inorder(t->left); 
		printf("%c ", t->value); 
		inorder(t->right); 
	} 
} 

// A utility function to create a new node 
et* newNode(int v, int h, int w) 
{ 
	et *temp = new et; 
	temp->left = temp->right = NULL; 
	temp->value = v;
        temp->height = h;
        temp->width = w;
	return temp; 
}; 

// Returns root of constructed tree for given 
// postfix expression 
et* constructTree(char postfix[]) 
{ 
	stack<et *> st; 
	et *t, *t1, *t2; 
        
        

	// Traverse through every character of 
	// input expression 
	for (int i=0; i<strlen(postfix); i++) 
	{ 
		// If operand, simply push into stack 
		if (!isOperator(postfix[i])) 
		{ 
			t = newNode(postfix[i], 2, 1); 
			st.push(t); 
		} 
		else // operator 
		{ 
			t = newNode(postfix[i], 0, 0); 

			// Pop two top nodes 
			t1 = st.top(); // Store top 
			st.pop();	 // Remove top 
			t2 = st.top(); 
			st.pop(); 

			// make them children 
			t->right = t1; 
			t->left = t2; 
                        
                        //if (postfix[i] == 'H')

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

// Driver program to test above 
int main() 
{ 
	char postfix[] = "16H2V75VH34HV"; 
	et* r = constructTree(postfix); 
	printf("infix expression is \n"); 
	inorder(r); 
	return 0; 
} 
