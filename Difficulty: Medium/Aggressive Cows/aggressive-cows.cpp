//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int check(vector<int>&stalls,int dist,int k)
    {
        int prev=stalls[0];
        int cows=1;
        for(int i=1;i<stalls.size();i++)
        {
            if(stalls[i]-prev>=dist)
            {
                cows++;
                prev=stalls[i];
            }
        }
        return cows>=k;
    }
    int aggressiveCows(vector<int> &stalls, int k) {

        // Write your code here
        int n=stalls.size();
        sort(stalls.begin(),stalls.end());
        int lo=1;
        int hi=stalls.back()-stalls[0];
        while(lo<=hi)
        {
            int mid=(lo+hi)/2;
            if(check(stalls,mid,k))
            {
                lo=mid+1;
            }
            else
            {
                hi=mid-1;
            }
        }
        return hi;
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int k;
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string in;
        getline(cin, in);
        stringstream sss(in);
        int num;
        while (sss >> num) {
            k = num;
        }
        Solution ob;
        int ans = ob.aggressiveCows(arr, k);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends