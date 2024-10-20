//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    bool static comp(pair<int,int>&p1,pair<int,int>&p2)
    {
        if(p1.second==p2.second) return p1.first<p2.first;
        else return p1.second<p2.second;
    }
    int maxMeetings(vector<int> start, vector<int> end) {
        // Your code here
        vector<pair<int,int>>v;
        int n=start.size();
        for(int i=0;i<n;i++)
        {
            v.push_back({start[i],end[i]});
        }
        sort(v.begin(),v.end(),comp);
        int cnt=1;
        int f=v[0].first;
        int s=v[0].second;
        for(int i=1;i<n;i++)
        {
            if(s<v[i].first)
            {
                cnt++;
                f=v[i].first;
                s=v[i].second;
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> start;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            start.push_back(num);
        }

        vector<int> end;
        getline(cin, input);
        stringstream s22(input);
        while (s22 >> num) {
            end.push_back(num);
        }

        Solution ob;
        int ans = ob.maxMeetings(start, end);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends