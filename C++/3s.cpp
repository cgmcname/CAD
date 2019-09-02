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

string removeSpaces(string str)  
{ 
    str.erase(remove(str.begin(), str.end(), ' '), str.end()); 
    return str; 
} 

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

bool normalCheck(vector<int> Z)
{
    
    int operands = 0;
    int operaters = 0;
    
    bool hold = true;
    
    for (unsigned int i = 0; i < Z.size(); i++)
    {
        
        if(operaters > operands)
        {
            return false;
        }
        
        if(Z[i] == 500 || Z[i] == 501)
        {
           operaters++; 
        }
        else if (Z[i] == 0)
        {
            hold = false;
        }
        else
        {
           operands++; 
        }
        
        if (Z[i] == Z[i+1])
        {
            return false;
        }
        
        
        
    }
    
    return true;
    
    
}

int normalCheckfault(vector<int> Z)
{
    
    int operands = 0;
    int operaters = 0;
    
    bool hold = true;
    
    for (unsigned int i = 0; i < Z.size(); i++)
    {
        
        if(operaters > operands)
        {
           return i;
        }
        
        if(Z[i] == 500 || Z[i] == 501)
        {
           operaters++; 
        }
        else if (Z[i] == 0)
        {
            hold = false;
        }
        else
        {
           operands++; 
        }
        
        if (Z[i] == Z[i+1])
        {
            return i+1;
        }
        
        
        
    }
    
    return 1;
    
    
} 
    
    
    
    

vector<int> parse(string postfix)
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
                  
                    
                   // cout << "T : " << Tall[Z[i]] << " W : " << Wide[Z[i]] << endl << endl;
                    
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
                    //cout << "Height  : " <<  t->height << " Width : " << t->width << endl << endl;
	} 

	// only element will be root of expression 
	// tree 
	t = st.top(); 
	st.pop(); 

	return t; 
} 

// Driver program to test above 
int main(int argc, char *argv[]) 
{ 
    
   
    
    
        string filename = argv[1];
    
        string pExpression = argv[2];
        
        ifstream inFile;
        inFile.open(filename.c_str());
        
        ifstream inFile2;
        inFile2.open(pExpression.c_str());
        
        
        
        //inFile >> wideInt >> tallInt;
        
        vector<int> Z;
        
        vector<int> Tall;
        
        vector<int> Wide;
        
        Wide.push_back(0);
        Tall.push_back(0);
        
        string line;
        
        
        while(getline(inFile, line))
            {
                istringstream iss(line);
                int tallInt ;
                int wideInt ;
                
               //cout << "line : " << line << endl << endl;
                
                while(iss >> wideInt >> tallInt)
                {
                    //cout << "WI : " << wideInt << endl << endl;
                    Wide.push_back(wideInt);
                    //cout << "TI : " << tallInt << endl << endl;
                    Tall.push_back(tallInt);
                }
                
            }
            
             inFile.close();
             
            // cout << "line : " << line << endl << endl;
        getline(inFile2, line);
        
        //istringstream iss2(line);
        
        
            //inFile2.close();
        
        bool normal;
    
	string postfix = line; 
        
        //string spaceRemove = postfix;
        
        int counter = 1;
        
        //spaceRemove = removeSpaces(spaceRemove);
    while (getline(inFile2, line))
    {
       // does the line have a semi-colon?
       size_t pos = line.find(';');
        pos = line.find('-');
       if (pos != string::npos)
       {
           // get everything after the comma
           line = line.substr(pos + 1);
           // store the string
           
       }
       // does the line have a comma?
       pos = line.find('+');
       if (pos != string::npos)
       {
           // get everything after the comma
           line = line.substr(pos + 1);
           // store the string
           
       }
       
       postfix = line;
       
        //cout << "line : " << line << endl << endl;
    
        
        Z = parse(postfix);
        
        normal = normalCheck(Z);
        
        if (normal == 1)
        {
            et* r = constructTree(Z, Tall, Wide);
	 
	//inorder(r); 
            
            cout <<"Chip size for PE # " << counter << ": " << endl;
            cout << "Width : "  << r->width << " Height : " << r->height << endl << endl;
        }
        else if (normal == 0)
        {
            int tellTale = 0;
            tellTale = normalCheckfault(Z);
            cout <<"For PE " << counter << " expression is not normalised. Violation at " << tellTale << "th char. "  << endl;
            break;
        }
        
        
        
        counter++;
        
    }
        
	
      /*  Z = parse(postfix);
        
        normal = normalCheck(Z);
        
        if (normal == 1)
        {
            et* r = constructTree(Z, Tall, Wide);
	 
	//inorder(r); 
            
            cout << "height : " << r->height << " width : " << r->width << endl << endl;
        }
        else if (normal == 0)
        {
            
            cout << "Expression is not normalised. Please input valid expression." << endl;
            
        }*/
         
        //cout << normal << endl; 
        
       
        
       
        
	return 0; 
} 
