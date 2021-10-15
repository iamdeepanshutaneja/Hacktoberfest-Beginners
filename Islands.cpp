//Interview question solved using dfs graph traversal logic
/*
  Question: 
  An island is a small piece of land surrounded by water .
  A group of islands is said to be connected if we can reach from any given island to any other island in the same group . 
  Given V islands (numbered from 1 to V) and E connections or edges between islands. Can you count the number of connected groups of islands.
  
    Input Format :
  The first line of input contains two integers, that denote the value of V and E.
  Each of the following E lines contains two integers, that denote that there exists an edge between vertex a and b. 
  
  Output Format :
  Print the count the number of connected groups of islands
  
  Constraints :
  0 <= V <= 1000
  0 <= E <= (V * (V-1)) / 2
  0 <= a <= V - 1
  0 <= b <= V - 1
  Time Limit: 1 second
  
  Sample Input 1:
  5 8
  0 1
  0 4
  1 2
  2 0
  2 4
  3 0
  3 2
  4 3
  Sample Output 1:
  1 
*/

//Solution code
void dfs(int **edge,int n,bool *visit,int s)
{
    visit[s]=true;
    for(int i=0;i<=n;i++)
    {
        if(edge[s][i]==1)
        {
            if(visit[i]==false)
            {
                dfs(edge,n,visit,i);
            }
        }
    }
}



int solve(int n,int m,vector<int>u,vector<int>v)
{
    int **edge=new int* [n+1];
    for(int i=0;i<=n;i++)
    {
        edge[i]=new int[n+1];
        for(int j=0;j<n;j++)
            edge[i][j]=0;
    }
    for(int i=0;i<m;i++)
    {
        edge[u[i]][v[i]]=1;
         edge[v[i]][u[i]]=1;
    }
    bool *visit=new bool[n+1];
    for(int i=0;i<=n;i++)
        visit[i]=false;
    int count=0;
    for(int i=1;i<=n;i++)
    {
        if(visit[i]==false)
        {
            dfs(edge,n,visit,i);
            count+=1;
        }
    }
    return count;
    
	// Write your code here .
}
