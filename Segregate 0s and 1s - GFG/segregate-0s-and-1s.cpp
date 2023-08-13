//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    void segregate0and1(int arr[], int n) {
        int ptr1 = 0;
        int ptr2 = n - 1;
        
        while(ptr1 < ptr2) {
            if(arr[ptr1] == 1) {
                // Different elements found, swap
                if(arr[ptr2] != 1) {
                    int temp = arr[ptr1];
                    arr[ptr1] = arr[ptr2];
                    arr[ptr2] = temp;
                }
                // Same element, just decrease the pointer 2
                ptr2--;
            } else {
                //  0 found on the left side, just increase the pointer 1
                ptr1++;
            }
            
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.segregate0and1(arr, n);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends