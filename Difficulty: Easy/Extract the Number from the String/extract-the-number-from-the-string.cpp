//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long ExtractNumber(string sentence) {

        // code here
        vector<string>ans;
        string v="";
        int n=sentence.size();
        bool flag=true;
        for(int i=0;i<n;i++)
        {
            if(sentence[i]>='0' && sentence[i]<='9')
            {
                v+=sentence[i];
                //  cout<<v<<endl;
                flag=true;
            }
            else
            {
                if(flag==true)
                {
                    if(v!="")
                    {
                    // cout<<v<<endl;
                    ans.push_back(v);
                    v="";
                    flag=false;
                    }
                }
            }
        }
        if(flag==true)  ans.push_back(v);
        long long maxi=-1;
        for(int i=0;i<ans.size();i++)
        {
            string x=ans[i];
            flag=true;
            for(int i=0;i<x.size();i++)
            {
                if(x[i]=='9') {flag=false; break;}
            }
            if(flag==true)
            {
                long long a=stoll(x);
                maxi=max(maxi,a);
            }
        }
        return maxi;
    }
};

//{ Driver Code Starts.
int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);

        Solution ob;
        cout << ob.ExtractNumber(s) << "\n";
    }

    return 0;
}

// } Driver Code Ends