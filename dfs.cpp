#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    void DFS(vector<int>&dfs,vector<int>&visited,vector<int>adj[],int node){
       visited[node]=1;
       dfs.push_back(node);
       for(auto it:adj[node]){
           if(!visited[it]){
               DFS(dfs,visited,adj,it);
           }
       }
          
            
    } 
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> visited(V,0);
        vector<int> dfs;
        visited[0]=1;
        DFS(dfs,visited,adj,0);
        return dfs;
    }

};

int main(){

}
