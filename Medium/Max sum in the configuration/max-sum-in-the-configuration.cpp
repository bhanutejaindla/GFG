//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/
class Solution {
  public:
    long long max_sum(int a[], int n) {
        // Your code here
        long long sum=0;
        long long prev_sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=a[i];
            prev_sum+=(long long)i*a[i];
        }
        long long maxi=0;
        maxi=max(maxi,prev_sum);
        for(int i=1;i<n;i++)
        {
           long long cursum=prev_sum-(sum-a[i-1])+(long long)a[i-1]*(n-1);
            prev_sum=cursum;
            maxi=max(maxi,cursum);
        }
        return maxi;
        
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution ob;
        cout << ob.max_sum(A, N) << endl;
        /*keeping track of the total sum of the array*/
    }
}

// } Driver Code Ends