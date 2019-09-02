// C++ program for expression tree 
#include<bits/stdc++.h>
#include <algorithm> 
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
                    while (postfix[i] != ' ')
                    {
                        i++;
                        cout << "check : " << i << endl;
                    }
                    
                    if (postfix[i] != ' ')
                    {
                        t = newNode(postfix[i], 2, 1); 
                        st.push(t);
                    }

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
                        
                        if (postfix[i] == 'H')
                        {
                            t->height = t1->height + t2->height;
                            t->width = std::max(t1->width, t2->width);
                            
                            
                        }
                        
                        if (postfix[i] == 'V')
                        {
                            
                            t->width = t1->width + t2->width;
                            t->height = std::max(t1->height, t2->height);
                            
                        }

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
	char postfix[] = "23 15 V 29 V 4 V 5 V 14 H 21 V 8 V 9 V 25 H 13 11 H 20 19 H V V 26 H 6 V 28 H 18 V 16 22 V H 30 V 12 V 3 H 1 H 17 H 7 27 V 2 10 24 V V V"; 
	et* r = constructTree(postfix); 
	printf("infix expression is \n"); 
	inorder(r); 
        
        cout << endl << endl;
        
        cout << "height : " << r->height << " width : " << r->width << endl;
        
	return 0; 
} 
