//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool helper(vector<int>&arr,int sum ,int ind,vector<vector<int>>&dp)
    {
        if(sum==0) return true;
        if(ind==0) return arr[0]==sum;
        if(ind<0) return false;
        if(dp[ind][sum]!=-1) return dp[ind][sum];
        bool take=false;
        if(sum-arr[ind]>=0)
        take=helper(arr,sum-arr[ind],ind-1,dp);
        bool nottake=helper(arr,sum,ind-1,dp);
        return dp[ind][sum]=take || nottake;
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return helper(arr,sum,n-1,dp);
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();

        Solution ob;
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends