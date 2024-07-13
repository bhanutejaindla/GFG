//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
         vector<pair<int,int>>adj[n+1];
         for(const auto &it:edges)
         {
             adj[it[0]].push_back({it[1],it[2]});
             adj[it[1]].push_back({it[0],it[2]});
         }
         priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
         vector<int>dist(n+1);
         vector<int> parent(n + 1, -1); // To reconstruct the pat
         
         for(int i=0;i<=n;i++) dist[i]=1e9;
         dist[1]=0;
         pq.push({0,1});
         while(!pq.empty())
         {
             int dis=pq.top().first;
             int node=pq.top().second;
             pq.pop();
             for(auto it:adj[node])
             {
                 int edgweight=it.second;
                 int adjnode=it.first;
                 if(dis+edgweight<dist[adjnode])
                 {
                     dist[adjnode]=dis+edgweight;
                     pq.push({dist[adjnode],adjnode});
                     parent[adjnode]=node;
                 }
             }
         }
         
         if(dist[n]==1e9) return {-1};
                 vector<int> path;
        for(int v = n; v != -1; v = parent[v])
            path.push_back(v);
        path.push_back(dist[n]);
        reverse(path.begin(), path.end());
        
        return path;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        map<pair<int, int>, int> mp;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
            mp[{edges.back()[0], edges.back()[1]}] = edges.back()[2];
            mp[{edges.back()[1], edges.back()[0]}] = edges.back()[2];
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        int ans = 0;
        for (int i = 2; i < res.size(); i++) {
            ans += mp[{res[i], res[i - 1]}];
        }
        if (ans == res[0]) {

        } else if (res.size() == 1 && res[0] == -1)
            ans = res[0];
        else
            ans = -2;
        cout << ans << endl;
    }
}

// } Driver Code Ends