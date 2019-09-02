// Polish.cpp
#include<bits/stdc++.h>
#include <algorithm>
#include <sstream>
#include <vector>
#include <string>
#include <time.h>
using namespace std; 

string infix = "";


// An expression tree node 
struct et 
{ 
	int value; 
	et* left, *right; 
        int height;
        int width;
}; 



//  function to check if a int is valued as an operator 

bool isOperator(int c) 
{ 
	if (c == 500 || c == 501 ) 
		return true; 
	return false; 
} 



// function to create a new node 
et* newNode(int v, int h, int w) 
{ 
	et *temp = new et; 
	temp->left = temp->right = NULL; 
	temp->value = v;
        temp->height = h;
        temp->width = w;
	return temp; 
}; 


// function to check if expression is normalised
bool normalCheck(vector<int> Z)
{
    
    int operands = 0;
    int operaters = 0;
    
    //int hold = Z.size();
    
    for (unsigned int i = 0; i < Z.size(); i++)
    {
        
        if(operaters > operands) //if more operaters obviously false (may still need to check an edge case)
        {
            //cout << "flag1 " << endl;
            return false;
            
            
        }
        
        if(Z[i] == 500 || Z[i] == 501)
        {
           operaters++; 
        }
        else if (Z[i] == 0)
        {
           // hold = false;
        }
        else
        {
           operands++; 
        }
        
        if (Z[i] == Z[i+1]) // if two seq values are same reject as they could only be operaters (at 500 and 501) 
        {
            //cout << "hold : " << hold << endl; 
            //cout << "i : " << i << " i + 1 : " << Z[i+1] << endl << endl;
            
            //cout << "flag2 " << endl;
            return false;
        }
        
        
        
    }
    
    return true;
    
    
}




// copy and paste function to check where expression is not normalised
int normalCheckFault(vector<int> Z)
{
    
    int operands = 0;
    int operaters = 0;
    
   // bool hold = true;
    
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
           // hold = false;
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
    
 void inorder(et *t) 
{ 
    
        //stringstream ss(line);
    
    
	if(t) 
	{ 
		inorder(t->left); 
		infix += std::to_string(t->value) + " "; 
		inorder(t->right); 
	} 
}    
    
    
//function to parse input into int vector that can be put into tree 
vector<int> parse(string postfix)
{
    
    vector<int> output;
   
    string line(postfix);
    istringstream iss(line);
    int num;
    
    line = "";
    
     
    string temp; 
               
                //!iss.eof()
                while(iss >> temp)
                {
                    //iss >> temp;
                    
                    if( temp == "H")
                    {
                        temp = "500"; //token value to denote operator 
                    }
                    
                    if( temp == "V")
                    {
                        temp = "501";
                    }
                    
                   line = line + " " + temp; 
                    
                }
                
                //cout << "Line parse :" << line << endl << endl;
                
                stringstream ss(line);
                
                while(ss >> num )
                {
                    
                    output.push_back(num);
                }
    
    return output;
    
}


vector<int> locationX(vector<int> Z, vector<int> Tall, vector<int> Wide) 
{
    int x = 0;
    int xpostion = 0;
    int newwide = 0;
    
    int y = 0;
    int ypostion = 0;
    int newhigh = 0;
    
    
    
    int maxX = 0;
    int maxY = 0;
    
    stack<int> xst;
    stack<int> yst;
    
    stack<int> Zst;
   
    
    /*yst.push(Tall[0]);
    xst.push(Wide[0]);*/
    
    vector<int> outputX;
    vector<int> outputY;
    
    outputX.push_back(0);
    outputY.push_back(0);
    
    Zst.push(0);
    
    yst.push(Tall[0]);
    xst.push(Wide[0]);
    
    
    
    for (unsigned int i = 0; i < Z.size(); i++) 
	{
                        
                      
                       
                        
                        
            if (!isOperator(Z[i])) 
		{ 
                    
                    
                            
                            
                            
                    
                        
                        if(Zst.top() == 500) // H node 
                        {
                            
                           
                            x = xst.top();
                            
                            //cout << xst.top() << "  Xs : " << endl; 
                            
                            xst.pop();
                            
                            xpostion = newwide;
                            
                            //cout << xpostion << " XPOS : " << endl;
                            
                            outputX.push_back(xpostion);
                            
                            maxX = std::max(x,Wide[Z[i]]);
                            
                            
                            
                            xpostion = maxX;
                            
                            
                            
                            
                            y = yst.top();
                            yst.pop();
                            
                            outputY.push_back(ypostion);
                            
                            y = ypostion + Tall[Z[i]];
                            //yst.push(y);
                            
                            newhigh = y;
                            
                            //ypostion = 0;
                            
                            Zst.pop();
                        }
                        
                        if(Zst.top() == 501) // V node 
                        {
                            y = yst.top();
                            yst.pop();
                            
                            ypostion = newhigh;
                            
                            //cout << ypostion << " YPOS : " << endl;
                            
                            outputY.push_back(ypostion);
                            
                            maxY = std::max(y,Tall[Z[i]]);
                            
                            ypostion = maxY;
                            
                            
                            x = xst.top();
                            xst.pop();
                            
                            outputX.push_back(xpostion);
                            
                            x = xpostion + Wide[Z[i]];
                            //xst.push(x);
                            
                            newwide = x;
                            
                            //xpostion = 0;
                            
                            Zst.pop();
                        }
                        
                        
                        
                    
                   //cout << xst.top() << " Xst : " << endl;
                    
                            
                            yst.push(Tall[Z[i]]);
                            xst.push(Wide[Z[i]]);
    
                    
                    
            }
            else
            {
              Zst.push(Z[i]);
              
            }
                            
            
        }
        
        return outputX;
        
}

vector<int> locationY(vector<int> Z, vector<int> Tall, vector<int> Wide) 
{
    int x = 0;
    int xpostion = 0;
    int newwide = 0;
    
    int y = 0;
    int ypostion = 0;
    int newhigh = 0;
    
    
    
    int maxX = 0;
    int maxY = 0;
    
    stack<int> xst;
    stack<int> yst;
    
    stack<int> Zst;
   
    
    /*yst.push(Tall[0]);
    xst.push(Wide[0]);*/
    
    vector<int> outputX;
    vector<int> outputY;
    
    outputX.push_back(0);
    outputY.push_back(0);
    
    Zst.push(0);
    
    yst.push(Tall[0]);
    xst.push(Wide[0]);
    
    
    
    for (unsigned int i = 0; i < Z.size(); i++) 
	{
                        
                      
                       
                        
                        
            if (!isOperator(Z[i])) 
		{ 
                    
                    
                            
                            
                            
                    
                        
                        if(Zst.top() == 500) // H node 
                        {
                            
                           
                            x = xst.top();
                            
                            //cout << xst.top() << "  Xs : " << endl; 
                            
                            xst.pop();
                            
                            xpostion = newwide;
                            
                            //cout << xpostion << " XPOS : " << endl;
                            
                            outputX.push_back(xpostion);
                            
                            maxX = std::max(x,Wide[Z[i]]);
                            
                            xpostion = maxX;
                            
                            
                            
                            
                            y = yst.top();
                            yst.pop();
                            
                            outputY.push_back(y);
                            
                            y = ypostion + Tall[Z[i]];
                            //yst.push(ypostion);
                            
                            //newhigh = maxY;
                            newhigh = y;
                            
                            //ypostion = 0;
                            
                            Zst.pop();
                        }
                        
                        if(Zst.top() == 501) // V node 
                        {
                            y = yst.top();
                            yst.pop();
                            
                            ypostion = newhigh;
                            
                            //cout << ypostion << " YPOS : " << endl;
                            
                            outputY.push_back(ypostion);
                            
                            maxY = std::max(y,Tall[Z[i]]);
                            
                            ypostion = maxY;
                            
                            
                            x = xst.top();
                            xst.pop();
                            
                            outputX.push_back(xpostion);
                            
                            x = xpostion + Wide[Z[i]];
                            //xst.push(x);
                            
                            //newwide = maxX;
                            newwide = x;
                            
                            //xpostion = 0;
                            
                            Zst.pop();
                        }
                        
                        
                        
                    
                   //cout << xst.top() << " Xst : " << endl;
                    
                            
                            yst.push(Tall[Z[i]]);
                            xst.push(Wide[Z[i]]);
    
                    
                    
            }
            else
            {
              Zst.push(Z[i]);
              
            }
                            
            
        }
        
        return outputY;
        
}

// Returns root of constructed tree for given expression 
et* constructTree(vector<int> Z, vector<int> Tall, vector<int> Wide ) 
{ 
	stack<et *> st; 
	et *t, *t1, *t2; 
        
        

	// Go through every value of expression 
	for (unsigned int i = 0; i < Z.size(); i++) 
	{ 
		// If operand push into stack 
		if (!isOperator(Z[i])) 
		{ 
                  
                    
                   
                    
                        t = newNode(Z[i], Tall[Z[i]], Wide[Z[i]]); 
                        st.push(t);
                        
                        

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
                        
                        if (Z[i] == 500) // H node
                        {
                            t->height = t1->height + t2->height;
                            t->width = std::max(t1->width, t2->width);
                            
                            
                        }
                        
                        if (Z[i] == 501) // V node
                        {
                            
                            t->width = t1->width + t2->width;
                            t->height = std::max(t1->height, t2->height);
                            
                        }
                        
			// Add this subexpression to stack 
			st.push(t); 
		} 
                    
	} 

	// Will end with root of expression tree 
	t = st.top(); 
	st.pop(); 

	return t; 
} 

 
int main(int argc, char *argv[]) 
{ 
    
        clock_t start_time = clock();
        
        int counter = 1;
   
        bool normal;
    
        string filename = argv[1];
    
        string pExpression = argv[2];
        
        ifstream inFile;
        inFile.open(filename.c_str());
        
        ifstream inFile2;
        inFile2.open(pExpression.c_str());
        
        vector<int> Z;
        vector<int> Y;
        vector<int> C;
        
        vector<int> Tall;
        
        vector<int> Wide;
        
        Wide.push_back(0);
        Tall.push_back(0);
        
        string line;
        string postfix;
        string finish;
        
        ofstream myfile;
        myfile.open ("PEoutput.txt");
        
        while(getline(inFile, line))
            {
                istringstream iss(line);
                int tallInt ;
                int wideInt ;
                
               
                
                while(iss >> wideInt >> tallInt)
                {
                    
                    Wide.push_back(wideInt);
                    
                    Tall.push_back(tallInt);
                }
                
            }
            
        inFile.close();
             
            
        
        
   //Work around for '+' '-' values for input files     
    while (getline(inFile2, line))
    {
       
       size_t pos = line.find('-');
        pos = line.find('-');
       if (pos != string::npos)
       {
           
           line = line.substr(pos + 1);
           
           
       }
       
       pos = line.find('+');
       if (pos != string::npos)
       {
           
           line = line.substr(pos + 1);
           
           
       }
       
        postfix = line;
        
        //cout << "Line main :" << line << endl << endl;
       
        Z = parse(postfix);
        
        C = Z;
        
        normal = normalCheck(Z);
        
        if (normal == 1)
        {
            et* r = constructTree(Z, Tall, Wide);
	 
            inorder(r);
            
            finish = std::to_string(r->width) + " " + std::to_string(r->height);
            //cout << "Width : "  << r->width << " Height : " << r->height << endl << endl;
            
                C = parse(infix);
                
                infix = "";
                
                
      
                Y = C;
      
                C = locationX(C, Tall, Wide);
                Y = locationY(Y, Tall, Wide);
                
                
      
                for (unsigned int i = 0; i < C.size(); i++) 
                { 
                    finish += " (" + std::to_string(C[i]) + "," + std::to_string(Y[i]) + ")";
            
                }
                
                
                
                myfile << finish << endl;
                
                C.clear();
                Y.clear();
           
        }
        else if (normal == 0)
        {
            int tellTale = 0;
            tellTale = normalCheckFault(Z);
            cout <<"For PE " << counter << " expression is not normalised. Violation at element " << tellTale  << endl;
            finish = "";
            myfile << finish << endl; 
        }
        
        
        
        counter++;
        
    }
    
    
               
        
        
      inFile2.close();
      myfile.close();
      
      
      
     
         
        
      
        
      
     
        
        
        
        
        clock_t end_time = clock();
        cout << "Running time for pass is: " << static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC * 1000 << "ms" << endl<< endl << endl; 
        
       
        
	return 0; 
} 
