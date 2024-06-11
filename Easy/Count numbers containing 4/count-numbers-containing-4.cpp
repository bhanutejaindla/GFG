//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countNumberswith4(int n) {
        // code here
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            int num=i;
            int a=log10(num)+1;
            while(a--)
            {
                int k=num%10;
                if(k==4) {cnt++; break;}
                num=num/10;
            }
        }
        return cnt;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        Solution obj;
        int res = obj.countNumberswith4(n);

        cout << res << endl;
    }
}

// } Driver Code Ends