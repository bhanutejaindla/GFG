//{ Driver Code Starts

#include <iostream>
#include <regex>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string compareFrac(string str) {

        // Code here
        int a=0;
        int b=0;
        int c=0;
        int d=0;
        int n=str.size();
        int ind=0;
        for(int i=0;i<n;i++)
        {
            if(str[i]!='/')
            a=a*10+(str[i]-'0');
            else
            { ind=i;  break; }
        }
        for(int i=ind+1;i<n;i++)
        {
            if(str[i]!=',')
            b=b*10+(str[i]-'0');
            else
            {
                ind=i;
                break;
            }
        }
        for(int i=ind+2;i<n;i++)
        {
            if(str[i]!='/')
            c=c*10+(str[i]-'0');
            else
            {
                ind=i;
                break;
            }
        }
        for(int i=ind+1;i<n;i++)
        {
           
            d=d*10+(str[i]-'0');
        }
        string ans1="";
        string ans2="";
        ans1+=to_string(a);
        ans1+="/";
        ans1+=to_string(b);
        ans2+=to_string(c);
        ans2+="/";
        ans2+=to_string(d);
        double fr1=(double)a/b;
        double fr2=(double)c/d;// 
        // cout<<fr1<<endl;
        // cout<<fr2<<endl;
        if(fr1==fr2) return "equal";
        else if(fr1>fr2) return ans1;
        else return ans2;
        
        
    }
};


//{ Driver Code Starts.

int main() {
    Solution ob;
    int t;
    cin >> t;
    cin.ignore();
    for (int i = 0; i < t; i++) {

        string str;
        getline(cin, str);

        cout << ob.compareFrac(str) << endl;
    }
    return 0;
}

// } Driver Code Ends