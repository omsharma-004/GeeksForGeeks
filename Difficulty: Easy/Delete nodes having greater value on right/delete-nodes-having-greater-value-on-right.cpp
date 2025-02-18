//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void print(Node* root) {
    Node* temp = root;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}


// } Driver Code Ends

class Solution {
public:
    Node* compute(Node* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        // Step 1: Reverse the list
        Node* prev = NULL;
        Node* curr = head;
        while (curr != NULL) {
            Node* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        head = prev; // head now points to the reversed list

        // Step 2: Keep only nodes >= max after them (in original order)
        Node* newHead = NULL;
        Node* tail = NULL; // Keep track of the tail of the new list
        Node* maxNode = NULL;

        while (head != NULL) {
            if (maxNode == NULL || head->data >= maxNode->data) {
                Node* newNode = new Node(head->data);

                if (newHead == NULL) { // First node
                    newHead = newNode;
                    tail = newNode;
                } else { // Add to the tail
                    tail->next = newNode;
                    tail = newNode;
                }
                maxNode = head;
            }
            head = head->next;
        }

        // Step 3: Reverse the new list to get the original order
        prev = NULL;
        curr = newHead;
        while (curr != NULL) {
            Node* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev; // Return the head of the modified list
    }
};



//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }
        Solution ob;
        int data = arr[0];
        Node* head = new Node(data);
        Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        Node* result = ob.compute(head);
        print(result);
        cout << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends