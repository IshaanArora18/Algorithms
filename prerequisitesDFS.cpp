//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool dfs(int node,vector<int>&visited,vector<int>&pathVisited,vector<int>&check,vector<int> adj[]){
        visited[node]=1;
        pathVisited[node]=1;
        for(auto it:adj[node]){
            if(!visited[it]){
                if(dfs(it,visited,pathVisited,check,adj)==false){
                    return false;
                }
            }
            else if(pathVisited[it]==1){
                return false;
            }
        }
        pathVisited[node]=0;
        check[node]=1;
        return true;
    }
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    vector<int> adj[N];
	    vector<int> visited(N,0);
	    vector<int> pathVisited(N,0);
	    vector<int> check(N,0);
	    for(auto it:prerequisites){
	        adj[it.first].push_back(it.second);
	    }
	    for(int i=0;i<N;i++){
	        if(!visited[i]){
	            if(dfs(i,visited,pathVisited,check,adj)==false){
	                return false;
	            }
	        }
	    }
	    return true;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends