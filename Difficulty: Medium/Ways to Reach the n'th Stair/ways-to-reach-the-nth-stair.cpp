//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  int helper(vector<int>& dp, int n){
        if(n<=1) return 1;
        if(dp[n]!=-1) return dp[n];
        dp[n]=helper(dp,n-1)+helper(dp,n-2);
        return dp[n];
    }
    int countWays(int n) {
        vector<int> dp(n+1,-1);
        return helper(dp,n);
    }
};


//{ Driver Code Starts.
int main() {
    // taking total testcases
    int t;
    cin >> t;
    while (t--) {
        // taking stair count
        int m;
        cin >> m;
        Solution ob;
        cout << ob.countWays(m) << endl; // Print the output from our pre computed array

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends