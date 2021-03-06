
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
    
    float ar[nodes+1][nodes+1];
    
    float arMax[nodes+1][nodes+1];
    
    int halfnodes = nodes/2;
    
    float max, max1;
            
    int k,x,y;
    
    string line;
    
    bool trip = false;
    
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
            
     for(int row = 0; row < nodes +1; row++)
	{
		for (int col = 0; col < nodes +1; col++)
			{
				ar[row][col] = 0.0;
                                arMax[row][col] = 0.0;
			}
	}  
	
	
      
    /*  printGraph(graph, nodes, nets);
        
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
    
    myfile.close(); */
      randhold[0]= 0;
      randhold[1]= 0;
      randhold[2]= 0;
      randhold[3]= 1;
      randhold[4]= 0;
      randhold[5]= 0;
      randhold[6]= 1;
      randhold[7]= 1;
      randhold[8]= 1;

while ( halfnodes > 0)
{
        for (int i = 1; i < nodes +1 ; i++)
        {
            cout <<"randhold @ : " << i << " is " << randhold[i] << endl;
        }
        
        
         for(int row = 0; row < nodes +1; row++)
	{
		for (int col = 0; col < nodes +1; col++)
			{
                            if (arMax[row][col] != INT_MIN)
                            {
				
                                arMax[row][col] = 0.0;
                            }
                            
                            ar[row][col] = 0.0;
			}
	} 
        
        int n = 0;
        
        float w = 0.0;
        float Ex = 0.0;
        float Ix = 0.0;
        
        float weightholdEx[nodes +1];
        float weightholdIx[nodes +1];
        
        
        
        for (int u = 0; u < nodes + 1; u++) 
        { 
            
            for (::std::vector<pair<int,float> >::iterator it  = graph[u].begin(); it!=graph[u].end(); it++) 
            { 
                n = it->first; 
                w = it->second;
                
                ar[u][n] += w;
                
                if(randhold[n] == randhold[u])
                {
                    Ix += w;
                    
                }
                
                if(randhold[n] != randhold[u])
                {
                
                    Ex += w ;
                    
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
            
            //cout <<" cutcal[u] at  " << u << " is " <<  cutcal[u] << endl << endl;
            
        } 
        
        
        
        float tempgain = 0.0;
        
        for(int i = 1; i < nodes +1; i++)
        {
            for(int k = 1  ; k < nodes +1; k++)
            {
                if ((randhold[i] != randhold[k]) && (arMax[i][k] != INT_MIN) )
                {
                    
                tempgain = cutcal[i] + cutcal[k];
                
                    if (ar[i][k] != 0.0)
                    {
                        tempgain = tempgain - (2 * ar[i][k]);
                        //cout << " C value happens : " << endl << endl;
                    }
                
                    //cout << " tempgain between i " << i << " and  k " << k << " is: " << tempgain << endl << endl;
                    arMax[i][k] = tempgain; 
                }
                    
            }
        }  
        
            
            //cout <<" x : " << x << " y : " << y <<  endl << endl << endl;
            
            
            
            
            if (trip == true)
            {
                
                for(int row = 1; row < nodes + 1 ; row++)
                {
                    for(int col = 1; col < nodes + 1 ; col++)
                    {
                        arMax[x][col]= INT_MIN;
                        arMax[y][col] = INT_MIN;
                    }
                    
                        arMax[row][x]= INT_MIN;
                        arMax[row][y] = INT_MIN;      
                }  
                
                
                
             
            }
          
       
            
            
          
            
            for(int row = 1; row < nodes + 1 ; row++)
            {
                    for(int col = 1; col < nodes + 1 ; col++)
                    {
                            cout << arMax[row][col] << "\t";
                    }
                            cout << endl;
            }
           
            
            for(int row = 1; row < nodes + 1 ; row++)
            {
                    for(int col = 1; col < nodes + 1 ; col++)
                    {
                        if (randhold[row] != randhold[col])
                        {
                            //cout << " col : " << arMax[row][col] << endl;
                            
                            if(arMax[row][col] >= max1) 
                                {
                                    max=arMax[row][col];
                                    k=max;// x=row; y=col; 
                                    max1= arMax[row][col];
                                    //cout << " MAX : " << max1 << endl;
                                }
                                
                        }
                    }
                    
                            
            }
           
           if (halfnodes == 4)
           {
               x = 4;
               y = 3;
           }
           
           if (halfnodes == 3)
           {
                x = 2;
                y = 7;
               
           }
            if (halfnodes == 2)
           {
                x = 1;
                y = 6;
               
           }
            if (halfnodes == 1)
           {
                x = 5;
                y = 8;
               
           }
            
            max = INT_MIN;
            
            max1 = INT_MIN;
            
            cout<<" Max gain is : " << k << " by swaping nodes " << x <<" and "<< y << endl << endl;
            
            
            
            if (randhold[x] == 0)
            {
            
                randhold[x] = 1;
                
            }
            else if (randhold[x] == 1)
            {
            
                randhold[x] = 0;
                
            }
            
            
            if (randhold[y] == 0)
            {
            
                randhold[y] = 1;
                
            }
            else if (randhold[y] == 1)
            {
            
                randhold[y] = 0;
                
            }
            
           // addEdge(graph, Z[0], Z[j], weight);
            
            cout << endl << endl << endl << endl;
            trip = true;
            halfnodes--;
            
    
   
            
}     
    
        
          
        
    
        for(int row = 1; row < nodes + 1 ; row++)
	{
		for(int col = 1; col < nodes + 1 ; col++)
		{
			cout << arMax[row][col] << "\t";
		}
			cout << endl;
	}
    
      
        //cout << "T0 : " << track0 << endl << endl;
        //cout << "T1 : " << track1 << endl << endl;
     
    return 0; 
    
    
}
