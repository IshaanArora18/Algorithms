//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool dfs(int node,vector<int> adj[],vector<int>&visited,vector<int>&pathVisited,vector<int>&ans,vector<int>&check){
        for(auto it:adj[node]){
            if(!visited[it]){
                visited[it]=1;
                pathVisited[it]=1;
                if(dfs(it,adj,visited,pathVisited,ans,check)){
                return true;
                }
            }
            else if(pathVisited[it]==1){
                return true;
            }
        }
        pathVisited[node]=0;
        check[node]=1;
        return false;
    }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<int> visited(V,0);
        vector<int> pathVisited(V,0);
        vector<int> ans,check(V,0);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(i,adj,visited,pathVisited,ans,check);
            }
        }
        for(int i=0;i<V;i++){
            if(check[i])ans.push_back(i);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends