//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int upperBound(vector<int>&arr,int x,int n)
    {
        int low=0;
        int high=n-1;
        int ans=n;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(arr[mid]>x)
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return ans;
    }
    int countsmallequal(vector<vector<int>>&mat,int n,int m,int x)
    {
        int cnt=0;
        for(int i=0;i<m;i++)
        {
            cnt+=upperBound(mat[i],x,n);
        }
        return cnt;
    }
    int median(vector<vector<int>> &mat) {
        // code here
        int n=mat.size();
        int m=mat[0].size();
        int low=INT_MAX;
        int high=INT_MIN;
        for(int i=0;i<n;i++)
        {
            low=min(low,mat[i][0]);
            high=max(high,mat[i][m-1]);
        }
        int req=(n*m)/2;
        while(low<=high)
        {
            int mid=(low+high)/2;
            int smallequal=countsmallequal(mat,n,m,mid);
            if(smallequal<=req) low=mid+1;
            else high=mid-1;
        }
        return low;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
                cin >> matrix[i][j];
        Solution obj;
        int ans = -1;
        ans = obj.median(matrix);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends