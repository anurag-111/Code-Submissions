//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

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
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

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
private:
    // Step 1: Traverse the left boundary nodes of the binary tree
    // - Add the current node's value to the 'ans' vector
    // - Recursively traverse the left child if it exists, otherwise, traverse the right child
    void traverseLeftBoundary(Node* root, vector<int> &ans) {
        if (root == NULL || (root->left == NULL && root->right == NULL)) {
            // Base case: If the current node is NULL or it is a leaf node, stop the traversal
            return;
        }
        
        ans.push_back(root->data); // Add the current node's value to the answer
        
        if (root->left) {
            traverseLeftBoundary(root->left, ans); // Traverse the left child
        } else {
            traverseLeftBoundary(root->right, ans); // Traverse the right child
        }
    }
    
    // Step 2: Traverse the leaf nodes of the binary tree
    // - Add the current node's value to the 'ans' vector if it is a leaf node
    // - Recursively traverse both left and right children
    void traverseLeafNodes(Node* root, vector<int> &ans) {
        if (root == NULL) {
            // Base case: If the current node is NULL, stop the traversal
            return;
        }
        
        if (root->left == NULL && root->right == NULL) {
            // If the current node is a leaf node, add its value to the answer
            ans.push_back(root->data);
        }
        
        traverseLeafNodes(root->left, ans); // Traverse the left child
        traverseLeafNodes(root->right, ans); // Traverse the right child
    }
    
    // Step 3: Traverse the right boundary nodes of the binary tree in reverse order
    // - Recursively traverse the right child if it exists, otherwise, traverse the left child
    // - Add the current node's value to the 'ans' vector after traversing its children
    void traverseRightBoundary(Node* root, vector<int> &ans) {
        if (root == NULL || (root->left == NULL && root->right == NULL)) {
            // Base case: If the current node is NULL or it is a leaf node, stop the traversal
            return;
        }
        
        if (root->right) {
            traverseRightBoundary(root->right, ans); // Traverse the right child
        } else {
            traverseRightBoundary(root->left, ans); // Traverse the left child
        }
        
        ans.push_back(root->data); // Add the current node's value to the answer
    }

public:
    // Function to find the boundary nodes of a binary tree
    vector<int> boundary(Node *root) {
        vector<int> ans;
        
        if (root == NULL) {
            // If the root is NULL, return an empty vector as there are no boundary nodes
            return {};
        }
        
        ans.push_back(root->data); // Add the root's value to the answer
        
        // Step 1: Traverse the left boundary nodes of the binary tree
        traverseLeftBoundary(root->left, ans);
        
        // Step 2.1: Traverse the left subtree leaf nodes
        traverseLeafNodes(root->left, ans);
        
        // Step 2.2: Traverse the right subtree leaf nodes
        traverseLeafNodes(root->right, ans);
        
        // Step 3: Traverse the right boundary nodes of the binary tree in reverse order
        traverseRightBoundary(root->right, ans);
    
        return ans; // Return the vector containing the boundary nodes of the binary tree
    }
};


//{ Driver Code Starts.

/* Driver program to test size function*/

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector <int> res = ob.boundary(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends