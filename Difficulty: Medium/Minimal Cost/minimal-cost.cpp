//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int helper(vector<int>&arr,int ind,int k,vector<int>&dp)
    {
        if(ind==0) return 0;
        if(ind<0) return INT_MAX;
        if(dp[ind]!=-1) return dp[ind];
        int cost=INT_MAX;
        for(int j=1;j<=k;j++)
        {
            if(ind-j>=0){
            int cost1=abs(arr[ind]-arr[ind-j])+helper(arr,ind-j,k,dp);
            cost=min(cost,cost1);
            }
        }
        return dp[ind]=cost;
    }
    int minimizeCost(int k, vector<int>& arr) {
        // Code here
        int n=arr.size();
        vector<int>dp(n,-1);
        return helper(arr,n-1,k,dp);
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minimizeCost(k, arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends