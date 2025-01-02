//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countSubarrays(vector<int> &arr, int k) {
        int n=arr.size();
        for(int i=1;i<n;i++){
            arr[i]+=arr[i-1];
        }
        int count=0;
        unordered_map<int ,int> mp;
        for(int i=0;i<n;i++){
            if(arr[i]==k){
                count++;
            }
            int rem=arr[i]-k;
            if(mp.find(rem)!=mp.end()) count+=mp[rem];
            mp[arr[i]]++;
        }
        return count;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.countSubarrays(arr, k);
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends