//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

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

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
	private :
		Node *childToParentMapper(Node *root, unordered_map<Node*, Node*> &childToParentMap, int target) {
			// Queue for BFS traversal
			queue<Node*> nodes;
			nodes.push(root);
			
			Node *targetNode = nullptr;
			
			while(!nodes.empty()) {
				int size = nodes.size();
				
				for(int i = 0; i < size; i++) {
					Node* current = nodes.front();
					nodes.pop();
					
					if(current -> data == target) {
					targetNode = current;
				    }
					
					if(current -> left) {
						nodes.push(current -> left);
						childToParentMap[current -> left] = current;
					}
					
					if(current -> right) {
						nodes.push(current -> right);
						childToParentMap[current -> right] = current;
					}
				}
			}
			
			return targetNode;
		}
		
	public :
		int minTime(Node* root, int target) {
			// Mapping Creation
			unordered_map<Node*, Node*> childToParentMap;
			
			// Target value has been given to us in 'int', convert to 'TreeNode*'
			// Function call for mapping
			Node *targetNode = childToParentMapper(root, childToParentMap, target);
			
			//  For visited markings
			unordered_set<Node*> visited;
			
			// Queue for BFS
			queue<Node*> nodes;
			nodes.push(targetNode);
			
			// Insert the visited node
			visited.insert(targetNode);
			
			// Time to burn : Initialize with -1 to account for starting from target
			int timeToBurn = -1;
			
			while(!nodes.empty()) {
				int size = nodes.size();
				
				// Level order traversal
				for(int i = 0; i < size; i++) {
					Node* current = nodes.front();
					nodes.pop();
					
					
					// Left residing nodes
					if(current -> left && visited.find(current -> left) == visited.end()) {
						visited.insert(current -> left);
						nodes.push(current -> left);
					}
					
					// Right residing nodes
					if(current -> right && visited.find(current -> right) == visited.end()) {
						visited.insert(current -> right);
						nodes.push(current -> right);
					}
					
					// For parents of the current node
					if(childToParentMap[current] && visited.find(childToParentMap[current]) == visited.end()) {
						visited.insert(childToParentMap[current]);
						nodes.push(childToParentMap[current]);
					}
				}
				
				timeToBurn++;
				
 			}
			
			return timeToBurn;
		}
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends