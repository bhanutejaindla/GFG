//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    void solve(vector<vector<int>>&mat,string s,vector<string>&ans,int ind1,int ind2,vector<vector<bool>>&vis)
    {
        
        if(ind1==mat.size()-1 && ind2==mat[0].size()-1)
        {
            ans.push_back(s);
            return ;
        }
        if(ind1<0 || ind2<0 || ind1>=mat.size() || ind2>=mat[0].size() || vis[ind1][ind2]) return ;
        vis[ind1][ind2]=true;
        if(ind1+1<mat.size() && mat[ind1+1][ind2]!=0 && !vis[ind1+1][ind2]){
        // s.push_back('D');

        solve(mat,s+'D',ans,ind1+1,ind2,vis);
        // s.pop_back();
 
        }
        if(ind2+1<mat[0].size() && mat[ind1][ind2+1]!=0 && !vis[ind1][ind2+1])
        {
        // s.push_back('R');
        solve(mat,s+'R',ans,ind1,ind2+1,vis);
        // s.pop_back();
      
        }
        if(ind1-1>=0 && mat[ind1-1][ind2]!=0 && !vis[ind1-1][ind2])
        {
            solve(mat,s+'U',ans,ind1-1,ind2,vis);
        }
        if(ind2-1>=0 && mat[ind1][ind2-1] && !vis[ind1][ind2-1])
        {
            solve(mat,s+'L',ans,ind1,ind2-1,vis);
        }
        vis[ind1][ind2]=false;
        
    }
    vector<string> findPath(vector<vector<int>> &mat) {
        // code here
         vector<string>ans;
         string s="";
         
         int n=mat.size(),m=mat[0].size();
         if(mat[0][0]==0 || mat[n-1][m-1]==0) return {};
      
         vector<vector<bool>>vis(n,vector<bool>(m,false));
         solve(mat,s,ans,0,0,vis);
         sort(ans.begin(),ans.end());
         return ans;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        vector<vector<int>> mat;
        string innerArray;
        bool isInsideArray = false;

        for (char c : input) {
            if (c == '[') {
                if (isInsideArray) {
                    innerArray.clear();
                }
                isInsideArray = true;
            } else if (c == ']') {
                if (isInsideArray && !innerArray.empty()) {
                    vector<int> row;
                    stringstream ss(innerArray);
                    int num;

                    while (ss >> num) {
                        row.push_back(num);
                        if (ss.peek() == ',')
                            ss.ignore();
                        while (isspace(ss.peek()))
                            ss.ignore();
                    }

                    mat.push_back(row);
                    innerArray.clear();
                }
                isInsideArray = false;
            } else if (isInsideArray) {
                if (!isspace(c)) {
                    innerArray += c;
                }
            }
        }

        Solution obj;
        vector<string> result = obj.findPath(mat);
        sort(result.begin(), result.end());

        if (result.empty())
            cout << "[]";
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends