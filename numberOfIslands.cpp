#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void bfs(int row,int col,vector<vector<char>>&grid,int m,int n,vector<vector<int>>&visited){
         queue<pair<int,int>>q;
         visited[row][col]=1;
         q.push({row,col});
         while(!q.empty()){
             int row=q.front().first;
             int col=q.front().second;
             q.pop();
            
            int delrow[4]={-1,0,1,0};
            int delcol[4]={0,1,0,-1};
            for(int i=0;i<4;i++){
                    int nrow=delrow[i]+row;
                    int ncol=delcol[i]+col;
                    if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && !visited[nrow][ncol] && grid[nrow][ncol]=='1')
                {
                    visited[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
             
         }

    }
    void dfs(int row,int col,vector<vector<char>>&grid,int m,int n,vector<vector<int>>&visited){
        visited[row][col]=1;
        int delrow[4]={-1,0,1,0};
            int delcol[4]={0,1,0,-1};
            for(int i=0;i<4;i++){
                    int nrow=delrow[i]+row;
                    int ncol=delcol[i]+col;
                    if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && !visited[nrow][ncol] && grid[nrow][ncol]=='1')
                {
                    visited[nrow][ncol]=1;
                    dfs(nrow,ncol,grid,m,n,visited);
                }
            }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size(),n=grid[0].size();
        int count=0;
          vector<vector<int>> visited(m,vector<int>(n,0));
        for(int row=0;row<m;row++){
            for(int col=0;col<n;col++){
                if(!visited[row][col] && grid[row][col]=='1'){
                   dfs(row,col,grid,m,n,visited);
                   count++;
                }
            }
        }
       return count;
        
    
    }
};
int main(){

}