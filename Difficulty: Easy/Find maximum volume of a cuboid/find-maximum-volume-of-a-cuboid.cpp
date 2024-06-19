//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    double maxVolume(double perimeter, double area) {
        //lbh=x;
        //l(a/2-lb-lh)=x;
        //al/2-l2b-l2h=x;
        //al/2-l2(p/4-l)=x;
        //al/2-l2p/4-l3=x;
        double len=(perimeter-sqrt(perimeter*perimeter-24*area))/12;
        double bred=perimeter/4-2*len;
        return  len *len*bred;
        
       
        
    }
};

//{ Driver Code Starts.
int main() {
    long long int t;
    cin >> t;
    while (t--) {
        double perimeter, area;
        cin >> perimeter >> area;
        // if (area == 5 and parameter == 15) {
        //     cout << "0.46" << endl;
        //     return 0;
        // }
        Solution ob;
        double ans = ob.maxVolume(perimeter, area);
        cout.precision(2);
        cout << fixed << ans << "\n";
    }
}
// } Driver Code Ends