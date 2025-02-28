//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#include <vector>

using namespace std;

class Solution {
public:
    int findFirst(vector<int>& arr, int x) {
        int left = 0, right = arr.size() - 1, first = -1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (arr[mid] == x) {
                first = mid;  // Possible first occurrence
                right = mid - 1;  // Move left to find earlier occurrence
            } else if (arr[mid] < x) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return first;
    }

    int findLast(vector<int>& arr, int x) {
        int left = 0, right = arr.size() - 1, last = -1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (arr[mid] == x) {
                last = mid;  // Possible last occurrence
                left = mid + 1;  // Move right to find later occurrence
            } else if (arr[mid] < x) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return last;
    }

    vector<int> find(vector<int>& arr, int x) {
        return {findFirst(arr, x), findLast(arr, x)};
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int x;
        cin >> x;
        cin.ignore();
        vector<int> ans;
        Solution ob;
        ans = ob.find(arr, x);
        cout << ans[0] << " " << ans[1] << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends