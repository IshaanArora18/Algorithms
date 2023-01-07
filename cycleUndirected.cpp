//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool bfs(vector<int> adj[],int src,vector<int>&visited){
        queue<pair<int,int>> q;
        visited[src]=1;
        q.push({src,-1});
        while(!q.empty())
        {
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();
            for(auto adjNode:adj[node]){
                if(!visited[adjNode])
                {
                    visited[adjNode]=1;
                    q.push({adjNode,node});
                }
                //if this node is already visited and it is not a parent of the adjNode.
                else if(parent!=adjNode){
                    return true;
                }
            }
        }
        return false;
    }
    bool dfs(vector<int> adj[],int node,int parent,vector<int>&visited){
        visited[node]=1;
        for(auto it:adj[node]){
            if(!visited[it]){
                visited[it]=1;
                if(dfs(adj,it,node,visited)==true){
                    return true;
                }
            }
             else if(parent!=it){
                    return true;
                }
            
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> visited(V,0);
       
        visited[0]=1;
        
        for(int i=0;i<V;i++){
            //if the node is not visited till now then call bfs.
            if(!visited[i]){
                if(bfs(adj,i,visited)==true)return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends