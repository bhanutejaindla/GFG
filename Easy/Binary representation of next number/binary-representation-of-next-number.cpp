//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string binaryNextNumber(string s) {
        // code here
        int l=0;
        while(s[l]=='0')
        {
            l++;
        }
        if(l==s.size()) return "1";
        string str="";
        for(int i=l;i<s.size();i++)
        {
            str+=s[i];
        }
        reverse(str.begin(),str.end());
        int left=0;
        int n=str.size();
        string ans="";
        int carry=((str[0]-'0')+1)/2;
        int sum=((str[0]-'0')+1)%2;
        ans+=to_string(sum);
        left++;
        while(left<n)
        {
             sum=carry+(str[left]-'0');
             if(sum>=2)
             {
                 ans+=to_string(sum%2);
                 carry=sum/2;
             }
             else
             {
                 ans+=to_string(sum);
                 carry=0;
             }
             left++;
        }
        if(carry==1)
        {
            ans+=to_string(1);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.binaryNextNumber(s);
        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends