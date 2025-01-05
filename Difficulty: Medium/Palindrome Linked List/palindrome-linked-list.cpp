//{ Driver Code Starts
#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <ios>
#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution {
  public:
    bool isPalindrome(Node *head) {
        // Corner Case
        if(!head || !head->next)
        {
            return true;
        }
        Node* slow = head;
        Node* fast = head;
        Node* head2 = nullptr;
        Node* prevSlow = nullptr;
        while(fast && fast->next)
        {
            prevSlow = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast && !fast->next)
        {
            head2 = slow->next;
            prevSlow->next = nullptr;
            delete slow;
        }
        else
        {
            head2 = slow;
            prevSlow->next = nullptr;
        }
        
        // Reverse LL1
        Node* curr = head;
        Node* next = nullptr;
        Node* prev = nullptr;
        while(curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
        
        // Compare Reversed LL1 and LL2
        while(head && head2)
        {
            if(head->data != head2->data)
            {
                break;
            }
            head = head->next;
            head2 = head2->next;
        }
        
        return !head && !head2;
    }
};


//{ Driver Code Starts.

/* Function to print nodes in a given linked list */
void printList(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

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

        if (arr.empty()) {
            cout << "empty" << endl;
            continue;
        }

        struct Node *head = new Node(arr[0]);
        struct Node *tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }
        Solution ob;
        if (ob.isPalindrome(head))
            cout << "true" << endl;
        else
            cout << "false" << endl;

        // Clean up the remaining nodes to avoid memory leaks
        while (head != NULL) {
            struct Node *temp = head;
            head = head->next;
            delete temp;
        }
    }
    return 0;
}

// } Driver Code Ends