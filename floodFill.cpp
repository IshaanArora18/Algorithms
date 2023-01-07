#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void bfs(int row,int col,vector<vector<int>>&image,vector<vector<int>>&visited,int incolor,int newColor){
        int n=image[0].size();
        int m=image.size();
        visited[row][col]=1;
        queue<pair<int,int>>q;
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
                if(nrow<m && ncol<n && nrow>=0 && ncol>=0 && !visited[nrow][ncol] && image[nrow][ncol]==incolor){
                    image[nrow][ncol]=newColor;
                    visited[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
        }
    }
    void dfs(int row, int col,vector<vector<int>>& image,vector<vector<int>>&visited,int incolor, int newColor)
    {
         int m=image.size();
         int n=image[0].size();
         visited[row][col]=1;
         int delrow[4]={-1,0,1,0};
         int delcol[4]={0,1,0,-1};
         image[row][col]=newColor;
         for(int i=0;i<4;i++){
             int nrow=delrow[i]+row;
             int ncol=delcol[i]+col;
             if(nrow>=0 && ncol>=0 && nrow<m && ncol<n && !visited[nrow][ncol] && image[nrow][ncol]==incolor){
                 visited[nrow][ncol]=1;
                 image[nrow][col]=newColor;
                 dfs(nrow,ncol,image,visited,incolor,newColor);
             }
         }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        int m=image.size();
        int n=image[0].size();
        int incolor=image[sr][sc];
        vector<vector<int>> visited(m,vector<int>(n,0));
        image[sr][sc]=newColor;
        bfs(sr,sc,image,visited,incolor,newColor);
        return image;
        }
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends