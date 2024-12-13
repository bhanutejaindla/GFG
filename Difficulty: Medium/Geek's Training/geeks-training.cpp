//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int helper(vector<vector<int>>&arr,int row,int col,int last,vector<vector<int>>&dp)
    {
        if(row==0)
        {
            int maxi=INT_MIN;
            for(int i=0;i<=col;i++)
            {
                if(i!=last)
                {
                    maxi=max(maxi,arr[0][i]);
                }
            }
            return maxi;
        }
        if(row<0) return 0;
        if(dp[row][last]!=-1) return dp[row][last];
        int maxi=INT_MIN;
        for(int i=0;i<=col;i++)
        {
            if(i!=last)
            {
                int points=arr[row][i]+helper(arr,row-1,col,i,dp);
                maxi=max(maxi,points);
            }
        }
        return dp[row][last]=maxi;
        
    }
    int maximumPoints(vector<vector<int>>& arr, int n) {
        // Code here
        int m=arr[0].size();
        vector<vector<int>>dp(n+1,vector<int>(4,-1));
        return helper(arr,n-1,m-1,m,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> arr;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            arr.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(arr, n) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends