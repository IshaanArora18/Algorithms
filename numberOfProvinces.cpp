#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  int count=0;
    void bfs(vector<int>adj[],int V,int i,vector<bool>&visited){
        queue<int> q;
        q.push(i);
        visited[i]=true;
        while(!q.empty()){
            int front=q.front();
            q.pop();
            for(auto it:adj[front]){
                if(!visited[it]){
                    visited[it]=true;
                    q.push(it);
                }
            }
        }
    }
    void dfs(vector<int>adj[],int V,int node,vector<bool>&visited){
        visited[node]=true;
        for(auto it:adj[node]){
            if(!visited[it]){
                dfs(adj,V,it,visited);
            }
        }
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        
        vector<int> adjList[V];
        //convert adj matrix to adj list
        vector<bool> visited(V+1,false);
        for(int i=0;i<V;i++){
            
            for(int j=0;j<V;j++){
                if(adj[i][j]==1 && i!=j){
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
       for(int i=0;i<V;i++){
           if(!visited[i]){
               count++;
            //   bfs(adjList,V,i,visited);
                 dfs(adjList,V,i,visited);
           }
       }
       return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
