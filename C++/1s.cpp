// C++ program for expression tree 
#include<bits/stdc++.h>
#include <algorithm>
#include <sstream>
#include <vector>
#include <string>
using namespace std; 


// An expression tree node 
struct et 
{ 
	int value; 
	et* left, *right; 
        int height;
        int width;
}; 

/*struct valueContainer
{
    int tall;
    int wide;
};*/

// A utility function to check if 'c' 
// is an operator 
bool isOperator(int c) 
{ 
	if (c == 500 || c == 501 ) 
		return true; 
	return false; 
} 

// Utility function to do inorder traversal 
void inorder(et *t) 
{ 
	if(t) 
	{ 
		inorder(t->left); 
		cout << t->value << " "; 
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

vector<int> parse(char postfix[])
{
    
   vector<int> output;
   
   string line(postfix);
   
   //cout << "LINE HERE: " << line << endl;
   
   
    istringstream iss(line);
    int num;
    
    line = "";
    
     
    string temp; 
               
                
                while(!iss.eof() )
                {
                    iss >> temp;
                    
                    if( temp == "H")
                    {
                        temp = "500";
                    }
                    
                    if( temp == "V")
                    {
                        temp = "501";
                    }
                    
                   line = line + " " + temp; 
                    //output.push_back(num);
                }
                
                //cout << "LINE HERE: " << line << endl;
                
               stringstream ss(line);
                
                 while(ss >> num )
                {
                    //cout << "NUM HERE: " << num << endl;
                    output.push_back(num);
                }
    
    return output;
    
}

// Returns root of constructed tree for given 
// postfix expression 
et* constructTree(vector<int> Z, vector<int> Tall, vector<int> Wide ) 
{ 
	stack<et *> st; 
	et *t, *t1, *t2; 
        
        //int followValue = 1;

	// Traverse through every character of 
	// input expression 
	for (unsigned int i = 0; i < Z.size(); i++) 
	{ 
		// If operand, simply push into stack 
		if (!isOperator(Z[i])) 
		{ 
                  
                    
                    //cout << "T : " << Tall[followValue] << " W : " << Wide[followValue] << endl << endl;
                    
                        t = newNode(Z[i], Tall[Z[i]], Wide[Z[i]]); 
                        st.push(t);
                        
                        //followValue++;

		} 
		else // operator 
		{ 
			t = newNode(Z[i], 0, 0); 

			// Pop two top nodes 
			t1 = st.top(); // Store top 
			st.pop();	 // Remove top 
			t2 = st.top(); 
			st.pop(); 

			// make them children 
			t->right = t1; 
			t->left = t2; 
                        
                        if (Z[i] == 500)
                        {
                            t->height = t1->height + t2->height;
                            t->width = std::max(t1->width, t2->width);
                            
                            
                        }
                        
                        if (Z[i] == 501)
                        {
                            
                            t->width = t1->width + t2->width;
                            t->height = std::max(t1->height, t2->height);
                            
                        }
                        
			// Add this subexpression to stack 
			st.push(t); 
		} 
                    cout << "Height  : " <<  t->height << " Width : " << t->width << endl << endl;
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
        vector<int> Z;
        
        vector<int> Tall;
        
        vector<int> Wide;
        
        Tall.push_back(0);
        Tall.push_back(3);
        Tall.push_back(4);
        Tall.push_back(2);
        Tall.push_back(3);
        Tall.push_back(3);
        Tall.push_back(2);
        Tall.push_back(4);
        Tall.push_back(4);
        Tall.push_back(4);
        Tall.push_back(4);
        Tall.push_back(4);
        Tall.push_back(4);
        Tall.push_back(2);
        
        Wide.push_back(0);
        Wide.push_back(2);
        Wide.push_back(3);
        Wide.push_back(4);
        Wide.push_back(3);
        Wide.push_back(3);
        Wide.push_back(1);
        Wide.push_back(2);
        Wide.push_back(2);
        Wide.push_back(2);
        Wide.push_back(2);
        Wide.push_back(2);
        Wide.push_back(2);
        Wide.push_back(2);
        
    
    
	char postfix[] = "1 6 H 2 V 7 3 V H 5 4 H V"; 
	
        Z = parse(postfix);
        et* r = constructTree(Z, Tall, Wide);
	//printf("infix expression is \n"); 
	inorder(r); 
        
        /*for (auto i = Z.begin(); i != Z.end(); ++i) 
        cout << *i << " "; 
        
        cout << endl << endl;*/
        
        cout << "height : " << r->height << " width : " << r->width << endl;
        
	return 0; 
} 
