
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
        
        
    
    for (int u = 0; u < nodes + 1; u++) 
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
    
   
        
        
    
    for (int u = 0; u < nodes + 1; u++) 
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
    
    int randhold[nodes + 1];
    
    randhold[0] = -1;
            
        
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
    
        printGraph(graph, nodes, nets);
        
         unsigned int countdown = nodes/2; 
         unsigned int countdown2 = nodes/2;
         
         int track0 = 0;
         int track1 = 0;
        
        srand( time(NULL) ); 
        
        int nodetrack = 1;
        
        ofstream myfile;
        
        myfile.open ("Partoutput.txt");
   
    for (int i = 1; i < (nodes + 1); i++)
    {
        
	
        int randNum = rand() % 2; 
        
        if (countdown == 0)
        {
        
            randNum = 0;
        }
        
        if (countdown2 == 0)
        {
            randNum = 1;
        }
        
        
        if (randNum == 1)
        {
            if ( countdown > 0)
            {
                countdown--; 
                //cout <<" LOOKKKKKK countd 1 : " << countdown << endl << endl;
            }
            
            track1++;
        }
        else if (randNum == 0)
        {
            if ( countdown2 > 0)
            {
                countdown2--; 
                //cout <<" LOOKKKKKK countd 2 : " << countdown2 << endl << endl;
            }
            
            track0++;
        }
        
        randhold[nodetrack] = randNum;
        
        myfile  << nodetrack << " " << randNum << endl;
        //myfile << " nets : " << nets << endl << endl;
         
        nodetrack++;
    }
    
    myfile.close(); 
    
    for (int i = 0; i < nodetrack; i++)
    {
        cout <<"randhold @ : " << i << " is " << randhold[i] << endl;
    }
      printGraph2(graph, nodes, nets);
      
    int n = 0;
    
    float w = 0.0;
    float Ex = 0.0;
    float Ix = 0.0;
    
    float weightholdEx[nodes +1];
    float weightholdIx[nodes +1];
    
    //weighthold[0] = -1.0
      
    for (int u = 0; u < nodes + 1; u++) 
    { 
        //cout << "Node " << u << " makes an edge with \n";
        //cout <<"randhold u @ : " << u << " is " << randhold[u] << endl << endl; 
        
        for (::std::vector<pair<int,float> >::iterator it  = graph[u].begin(); it!=graph[u].end(); it++) 
        { 
            n = it->first; 
            w = it->second;
            
            //cout <<"randhold n @ : " << n << " is " << randhold[n] << "  weight here : " << w << endl; 
            
            if(randhold[n] == randhold[u])
            {
                Ix += w;
                //cout << " equal  " << w << endl << endl << endl;
            }
            
            if(randhold[n] != randhold[u])
            {
              
                Ex += w ;
                //cout << " not equal " << w << endl << endl << endl;
            }
            
           
            
          
            
            
        } 
        
            weightholdEx[u] = Ex;
            weightholdIx[u] = Ix;
        
            Ix = 0;
            Ex = 0;
       
        cout << endl;
        //cout <<"Whold Ex u @ : " << u << " is " <<  weightholdEx[u] << endl;
        //cout <<"Whold Ix u @ : " << u << " is " <<  weightholdIx[u] << endl << endl;
    } 
    
    float cutcal[nodes +1];
    
    cutcal[0] = -1.0;
 
    for (int u = 1; u < nodes + 1; u++) 
    { 
        
        cutcal[u] = weightholdEx[u] - weightholdIx[u];
        
        cout <<" cutcal[u] at  " << u << " is " <<  cutcal[u] << endl << endl;
        
      
        
        /*for (::std::vector<pair<int,float> >::iterator it  = graph[u].begin(); it!=graph[u].end(); it++) 
        { 
            n = it->first; 
            w = it->second;
            
            cout <<"randhold n @ : " << n << " is " << randhold[n] << "  weight here : " << w << endl; 
            
            if(randhold[n] == randhold[u])
            {
                Ix += w;
                //cout << " equal  " << w << endl << endl << endl;
            }
            
            if(randhold[n] != randhold[u])
            {
              
                Ex += w;
                //cout << " not equal " << w << endl << endl << endl;
            }
            
           
            
          
            
            
        }*/
        
          
        
    } 
    
    cout << endl << endl;
    
    float tempgain = 0.0;
    
    for(int i = 1; i < nodes +1; i++)
    {
        for(int k = nodes ; k > i; k--)
        {
            if (randhold[i] != randhold[k])
            {
                
              tempgain = cutcal[i] + cutcal[k];
              
              cout << " tempgain between i " << i << "and  k " << k << " is: " << tempgain << endl << endl;
                
            }
            
        }
        
        for (::std::vector<pair<int,float> >::iterator it  = graph[i].begin(); it!=graph[i].end(); it++) 
        { 
            n = it->first; 
            w = it->second;
            
           
            
           float checkit = 0.0;
            
            if(randhold[n] != randhold[i])
            {
              
                checkit = tempgain - (2 * w);
                //cout << " not equal " << w << endl << endl << endl;
            }
            
           
            
          
            
            
        }
        
        cout << " gain for node " << i << " at " << w << endl << endl << endl;
        
        cout << endl << endl << endl;
        
    }
    
    
      
        //cout << "T0 : " << track0 << endl << endl;
        //cout << "T1 : " << track1 << endl << endl;
     
    return 0; 
} 
