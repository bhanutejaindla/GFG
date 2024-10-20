//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
  public:
    // Function to get the maximum total value in the knapsack.
    bool static comp(pair<int,pair<int,double>>&p1,pair<int,pair<int,double>>&p2)
    {
        return p1.second.second>p2.second.second;
    }
    double fractionalKnapsack(vector<int>& values, vector<int>& weights, int w) {
        // Your code here
        vector<pair<int,pair<int,double>>>v;
        int n=values.size();
        for(int i=0;i<n;i++)
        {
            v.push_back({values[i],{weights[i],(double)values[i]/weights[i]}});
        }
        sort(v.begin(),v.end(),comp);
        double ans=0;
        for(int i=0;i<n;i++)
        {
            double a=v[i].second.second;
            int weight=v[i].second.first;
            if(weight<=w)
            {
                ans+=a*weight;
                w-=weight;
            }
            else
            {
                ans+=w*a;
                w=0;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    // taking testcases
    cin >> t;
    cin.ignore(); // to ignore the newline after the number of test cases
    cout << setprecision(6) << fixed;

    while (t--) {
        // Reading the value array
        vector<int> values;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            values.push_back(number);
        }

        // Reading the weight array
        vector<int> weights;
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            weights.push_back(number);
        }

        // Reading the capacity
        int w;
        cin >> w;
        cin.ignore(); // to ignore the newline after capacity

        // function call
        Solution ob;
        cout << ob.fractionalKnapsack(values, weights, w) << endl;
    }
    return 0;
}

// } Driver Code Ends