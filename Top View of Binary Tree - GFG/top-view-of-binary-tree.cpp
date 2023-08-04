//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends


class Solution {
public:
    vector<int> topView(Node* root) {
        vector<int> result;
        
        // If the tree is empty, return an empty result vector
        if (root == NULL) {
            return result;
        }
        
        // (Node, Line) pairs in the queue
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        
        // Mapping of (Line -> Node value) to store the top view nodes
        map<int, int> mymap;
        
        while (!q.empty()) {
            // Take out the top most (node, line)
            auto it = q.front();
            q.pop();
            
            // Extract Node and Line values from the pair
            Node* node = it.first;
            int line = it.second;
            
            // If this line is not yet mapped, create a new mapping
            if (mymap.find(line) == mymap.end()) {
                mymap[line] = node->data;
            }
            
            // Add the left child to the queue with the line value decremented by 1
            if (node->left) {
                q.push({node->left, line - 1});
            }
            
            // Add the right child to the queue with the line value incremented by 1
            if (node->right) {
                q.push({node->right, line + 1});
            }
        }
        
        // Push the values of the map into the result vector
        for (auto pair : mymap) {
            result.push_back(pair.second);
        }
        
        return result;
    }
};


// Time complexity : O(N * log(N))
// O(N) (enqueue and dequeue operations) * O(log(N)) (map insertion) + O(N) (result vector construction) = O(N * log(N)) + O(N) = O(N * log(N))


//{ Driver Code Starts.

int main() {
    int tc;
    cin>>tc;
    cin.ignore(256, '\n');
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        vector<int> vec = ob.topView(root);
        for(int x : vec)
            cout<<x<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends