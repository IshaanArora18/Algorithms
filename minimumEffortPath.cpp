//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
        // Code here
        int m=heights.size();
        int n=heights[0].size();
        vector<vector<int>> diff(m,vector<int>(n,1e9));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});
        int delrow[4]={-1,0,1,0};
        int delcol[4]={0,1,0,-1};
        while(!pq.empty()){
            auto it=pq.top();
            int row=it.second.first;
            int col=it.second.second;
            int diff_curr=it.first;
            pq.pop();
            for(int i=0;i<4;i++){
                int nrow=delrow[i]+row;
                int ncol=delcol[i]+col;
                if(nrow>=0 && ncol>=0 && nrow<m && ncol<n){
                    int difference=max(abs(heights[nrow][ncol]-heights[row][col]),diff_curr);
                    if(difference<diff[nrow][ncol]){
                        diff[nrow][ncol]=difference;
                        pq.push({difference,{nrow,ncol}});
                    }
                }
            }
        }
        if(diff[m-1][n-1]==1e9)return 0;
        return diff[m-1][n-1];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends