//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string smallestNumber(int s, int d) {
        // code here
        string v="1";
        for(int i=0;i<d-1;i++)
        {
            v+="0";
        }
        int num=stoi(v);
        string x=to_string(num);
        while(true && x.size()<=d)
        {
             x=to_string(num);
            int a=0;
            for(int i=0;i<x.size();i++)
            {
                a+=x[i]-'0';
            }
            if(a==s) return x;
            num++;
        
        }
        return "-1";
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int s, d;
        cin >> s >> d;
        Solution ob;
        cout << ob.smallestNumber(s, d) << "\n";
    }

    return 0;
}
// } Driver Code Ends