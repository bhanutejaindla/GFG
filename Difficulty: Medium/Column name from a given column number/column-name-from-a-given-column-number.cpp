//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends



class Solution {
  public:
    string colName(long long int n) {
        // your code here
        string s="";
        while(n>0)
        {
            int num=n%26;
            n=n/26;
            if(num==0)
            {
                n--;
                s+='Z';
            }
            else
            {
                s+='A'+(num-1);
            }
        }
        reverse(s.begin(),s.end());
        return s;
        
    }
};


//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
	{
		long long int n; cin >> n;
		Solution ob;
		cout << ob.colName (n) << '\n';
	
cout << "~" << "\n";
}
}

// } Driver Code Ends