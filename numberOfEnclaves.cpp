//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(int row,int col,vector<vector<int>>&grid,vector<vector<int>>&visited){
        visited[row][col]=1;
        int m=grid.size();
        int n=grid[0].size();
        int delrow[4]={-1,0,1,0};
        int delcol[4]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nrow=delrow[i]+row;
            int ncol=delcol[i]+col;
            if(nrow>=0 && ncol>=0 && nrow<m && ncol<n && !visited[nrow][ncol] && grid[nrow][ncol]==1){
                dfs(nrow,ncol,grid,visited);
            }
        }
    }
    void bfs(int row,int col,vector<vector<int>>&grid,vector<vector<int>>&visited){
        queue<pair<int,int>> q;
        q.push({row,col});
        visited[row][col]=1;
        int m=grid.size();
        int n=grid[0].size();
        int delrow[4]={-1,0,1,0};
        int delcol[4]={0,1,0,-1};
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
            int nrow=delrow[i]+row;
            int ncol=delcol[i]+col;
            if(nrow>=0 && ncol>=0 && nrow<m && ncol<n && !visited[nrow][ncol] && grid[nrow][ncol]==1){
               visited[nrow][ncol]=1;
               q.push({nrow,ncol});
            }
        }
        }
    }
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        for(int j=0;j<n;j++){
            if(!visited[0][j] && grid[0][j]==1){
               //dfs(0,j,grid,visited);
               bfs(0,j,grid,visited);
            }
            if(!visited[m-1][j] && grid[m-1][j]==1){
                //bfs(m-1,j,grid,visited);
               bfs(m-1,j,grid,visited);
            }
        }
        for(int i=0;i<m;i++){
            if(!visited[i][0] && grid[i][0]==1){
               //dfs(i,0,grid,visited);
               bfs(i,0,grid,visited);
            }
            if(!visited[i][n-1] && grid[i][n-1]==1){
                //dfs(i,n-1,grid,visited);
               bfs(i,n-1,grid,visited);
            }
        }
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!visited[i][j] && grid[i][j]==1){
                    count++;
                }
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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends