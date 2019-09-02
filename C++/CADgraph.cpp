

#include <bits/stdc++.h> 
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <vector> 
using namespace std; 
  
// To add an edge 
void addEdge(vector <pair<int, float> > adj[], int u, 
                                     int v, float wt) 
{ 
    adj[u].push_back(make_pair(v, wt)); 
    adj[v].push_back(make_pair(u, wt)); 
} 
  
// Print adjacency list representaion ot graph 
void printGraph(vector<pair<int,float> > adj[], int V) 
{ 
    int v; 
    
    float w; 
    
    for (int u = 0; u < V; u++) 
    { 
        cout << "Node " << u << " makes an edge with \n"; 
        for (::std::vector<pair<int,float>>::iterator it  = adj[u].begin(); it!=adj[u].end(); it++) 
        { 
            v = it->first; 
            w = it->second; 
            cout << "\tNode " << v << " with edge weight ="
                 << w << "\n"; 
        } 
        cout << "\n"; 
    } 
} 


//int calWeight
  
// Driver code 
int main(int argc, char *argv[]) 
{ 
    int nets;
    int V ; 
    
    vector<int> Z; 
    
   
    string filename = argv[1];
    
  
    
    ifstream inFile;
    inFile.open(filename.c_str());
	
	
    inFile >> nets >> V ;
		
    inFile.ignore();
    
  
            
    
    
    
   
       
    vector<pair<int, float> > adj[V+1]; 
    
       
    
    string line;
            
        while(getline(inFile, line))
            {
                istringstream iss(line);
                int num;
               // int counter;
                
                while(iss >> num )
                {
                    Z.push_back(num);
                    
                    
                }
                
                cout << "CHECK SIZE : " << Z.size() << endl << endl;
                
                float weight = (1.0/(float(Z.size()) - 1.0));
                
                cout << "CHECK WEIGHT : " << weight << endl << endl; 
                
                while(Z.size() > 1)
                {
                    
                    int j = 1;
                    
                    for (int i = 0; i < (Z.size()- 1); i++)
                    {
                        
                        addEdge(adj, Z[0], Z[j], weight);
                        //cout << "J :" << Z[j] << endl << endl;
                        j++;
                        //printGraph(adj, V);
                        //cout << endl << endl;
                    }
                    
                    //cout << "Before :" << Z.size() << endl << endl;
                    Z.erase(Z.begin());
                    //cout << "After :" << Z[0] << endl << endl;
                }
                
                cout << "line : " << line << endl << endl;
                
                Z.clear();
            }
    
    
    
    
        printGraph(adj, V);
   
    

     
    return 0; 
} 
