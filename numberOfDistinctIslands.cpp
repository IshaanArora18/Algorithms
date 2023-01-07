//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(int row,int col,vector<vector<int>>&grid,vector<vector<int>>&visited,vector<pair<int,int>>&vec,int row0,int col0){
        visited[row][col]=1;
        vec.push_back({row-row0,col-col0});
        int delrow[4]={-1,0,+1,0};
        int delcol[4]={0,-1,0,+1};
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<4;i++){
            int nrow=delrow[i]+row;
            int ncol=delcol[i]+col;
            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && !visited[nrow][ncol] && grid[nrow][ncol]==1){
                dfs(nrow,ncol,grid,visited,vec,row0,col0);
            }
        }
    }
    void bfs(int row,int col,vector<vector<int>>&grid,vector<vector<int>>&visited,vector<pair<int,int>>&vec,int row0,int col0){
        queue<pair<int,int>> q;
        q.push({row,col});
        vec.push_back({row-row0,col-col0});
        int delrow[4]={-1,0,1,0};
        int delcol[4]={0,1,0,-1};
        int n=grid.size();
        int m=grid[0].size();
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
        for(int i=0;i<4;i++){
            int nrow=delrow[i]+row;
            int ncol=delcol[i]+col;
            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && !visited[nrow][ncol] && grid[nrow][ncol]==1){
                q.push({nrow,ncol});
                vec.push_back({nrow-row0,ncol-col0});
                visited[nrow][ncol]=1;
            }
        }
        }
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n=grid.size();
        int m=grid[0].size();
        set<vector<pair<int,int>>> st;
        vector<vector<int>> visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j]&&grid[i][j]==1){
                     vector<pair<int,int>> vec;
                     bfs(i,j,grid,visited,vec,i,j);
                     st.insert(vec);
                }
            }
        }
        return st.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends