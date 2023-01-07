//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
    bool dfs(int node,stack<int>&s,vector<int> adj[],vector<int>&visited,vector<int>&pathVisited){
        pathVisited[node]=1;
        visited[node]=1;
        for(auto it:adj[node]){
            if(!visited[it]){
                if(dfs(it,s,adj,visited,pathVisited)){
                    return true;
                }
            }
            else if(pathVisited[it]==1){
                    return true;
                }
        }
        s.push(node);
        pathVisited[node]=0;
        return false;
    }
    vector<int> findOrder(int V, int m, vector<vector<int>> prerequisites) 
    {
        //code here
        vector<int> adj[V];
        vector<int> visited(V,0);
        vector<int> pathVisited(V,0);
        vector<int> ans;
        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        stack<int> s;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(dfs(i,s,adj,visited,pathVisited)){
                    return ans;
                }
            }
        }
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};

//{ Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends