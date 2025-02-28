//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    bool findTriplets(vector<int> &arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end()); // Step 1: Sort the array

        for (int i = 0; i < n - 2; i++) {
            int left = i + 1, right = n - 1;

            while (left < right) {
                int sum = arr[i] + arr[left] + arr[right];

                if (sum == 0) {
                    return true; // Triplet found
                } else if (sum < 0) {
                    left++; // Move left pointer to increase sum
                } else {
                    right--; // Move right pointer to decrease sum
                }
            }
        }
        return false; // No triplet found
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline after the integer input
    while (t--) {
        string input;
        getline(cin, input);

        stringstream ss(input);
        vector<int> arr;
        int num;
        while (ss >> num)
            arr.push_back(num);

        Solution obj;
        if (obj.findTriplets(arr))
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }

    return 0;
}

// } Driver Code Ends