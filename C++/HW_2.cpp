
#include <bits/stdc++.h> 
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std; 
  
 
void addEdge(vector <pair<int, float> > graph[], int u, 
                                     int v, float wt) 
{ 
    graph[u].push_back(make_pair(v, wt)); 
    graph[v].push_back(make_pair(u, wt)); 
} 
  

void printGraph(vector<pair<int,float> > graph[], int nodes, int nets) 
{ 
    
    int n; 
    
    float w; 
    
    ofstream myfile;
        
    myfile.open ("output.txt");
        
    myfile << " nodes : " << nodes << endl;
    myfile << " nets : " << nets << endl << endl;
        
        
    
    for (int u = 0; u < nodes; u++) 
    { 
        myfile << "Node " << u << " makes an edge with \n"; 
        for (::std::vector<pair<int,float> >::iterator it  = graph[u].begin(); it!=graph[u].end(); it++) 
        { 
            n = it->first; 
            w = it->second; 
            myfile << "\tNode " << n << " with edge weight ="
                 << w << "\n"; 
        } 
        myfile << "\n"; 
    } 
    
    myfile.close();
} 

void printGraph2(vector<pair<int,float> > graph[], int nodes, int nets) 
{ 
    
    int n; 
    
    float w; 
    
   
        
        
    
    for (int u = 0; u < nodes; u++) 
    { 
        cout << "Node " << u << " makes an edge with \n"; 
        for (::std::vector<pair<int,float> >::iterator it  = graph[u].begin(); it!=graph[u].end(); it++) 
        { 
            n = it->first; 
            w = it->second; 
            cout << "\tNode " << n << " with edge weight ="
                 << w << "\n"; 
        } 
       cout << "\n"; 
    } 
    
    
}


 
int main(int argc, char *argv[]) 
{ 
   
    
    int nets;
    int nodes ; 
    int numPas;
    
    vector<int> Z; 
    
   
    string filename = argv[1];
    
    string passes = argv[2];
    
    string optFile = argv[3];
    
    stringstream P(passes);
    
    P >> numPas;
    
   
    
    ifstream inFile;
    inFile.open(filename.c_str());
	
	
    inFile >> nets >> nodes ;
		
    inFile.ignore();
    
    vector<pair<int, float> > graph[nodes+1]; 
    
    string line;
            
        
        while(getline(inFile, line))
            {
                istringstream iss(line);
                int num;
               
                
                while(iss >> num )
                {
                    Z.push_back(num);
                }
                
                
                float weight = (1.0/(float(Z.size()) - 1.0));
                
                 
                
                while(Z.size() > 1)
                {
                    
                    int j = 1;
                    
                    for ( unsigned int i = 0; i < (Z.size()- 1); i++)
                    {
                        
                        addEdge(graph, Z[0], Z[j], weight);
                        j++;
                        
                        
                    }
                    
                    
                    Z.erase(Z.begin());
                    
                }
                
                
                
                Z.clear();
            }
    
    
    /*int q; 
    int x;
    
    float p; 
    
    int cheat = 1;
    
    for (int u = 0; u < nodes; u++) 
    { 
        
        int cheat = 0;
        
        for (::std::vector<pair<int,float> >::iterator it  = graph[u].begin(); it!=graph[u].end(); it++) 
        { 
            
            cheat++;
            q = it->first; 
            
            
            ::std::vector<pair<int,float> >::iterator it2 = next(it, 1);
            
            x = it2->first;
            
            q = it->first; 
           
            
         
            
               
               if (q == x)
               {
                   
                   graph[u].erase(graph[u].begin() + cheat); 
                   break;
               }
               
               
          
             
        } 
        
    } */
    
        
        
         /*unsigned int countdown = nodes/2; 
         unsigned int countdown2 = nodes/2;
        
        srand( time(NULL) ); */
        
        
   
   /* for (int i = 1; i < (nodes + 1); i++)
    {
        
	int randNum = rand() % 2; 
        
        //cout <<" LOOKKKKKK : " << randNum << endl << endl;
        if (randNum == 1)
        {
            if ( countdown > 0)
            {
                countdown--; 
            }
            
        }
        else if (randNum == 0)
        {
            if ( countdown2 > 0)
            {
                countdown2--; 
            }
            
        }
        
        if (countdown == 0)
        {
        
            randNum = 0;
        }
        
        if (countdown2 == 0)
        {
            randNum = 1;
        }
        
         
         cout <<" RAND : " << randNum << endl << endl;
        
    }*/
        
      printGraph(graph, nodes, nets);  
      printGraph2(graph, nodes, nets);
     
    return 0; 
} 
