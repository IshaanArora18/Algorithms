//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // code here
        vector<pair<int,int>>adj[n];
        for(auto it:roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        vector<int> dist(n,1e9);
        vector<int> ways(n);
        dist[0]=0;
        ways[0]=1;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        long long mod=1e9+7;
        while(!pq.empty()){
            auto it=pq.top();
            int node=it.second;
            int distance=it.first;
            pq.pop();
            for(auto itr:adj[node]){
                int edgeWeight=itr.second;
                int adjNode=itr.first;
                if(edgeWeight+distance<dist[adjNode]){
                    dist[adjNode]=edgeWeight+distance;
                    pq.push({dist[adjNode],adjNode});
                    ways[adjNode]=ways[node];
                }
                else if(edgeWeight+distance==dist[adjNode]){
                    ways[adjNode]+=ways[node]%mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends