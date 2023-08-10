//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int findElement(int arr[], int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) cin >> a[i];
        cout << findElement(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends


int findElement(int arr[], int n) {
    // Create two arrays to store the maximum element on the left and minimum element on the right
    int leftMax[n], rightMin[n];
    leftMax[0] = INT_MIN;
    rightMin[n - 1] = INT_MAX;
    
    // Fill the leftMax array with maximum element on the left side of each element
    for (int i = 1; i < n; i++) {
        leftMax[i] = max(leftMax[i - 1], arr[i - 1]);
    }
    
    // Fill the rightMin array with minimum element on the right side of each element
    for (int i = n - 2; i >= 0; i--) {
        rightMin[i] = min(rightMin[i + 1], arr[i + 1]);
    }
    
    // Find the element which satisfies the condition
    for (int i = 1; i < n - 1; i++) {
        if (arr[i] >= leftMax[i] && arr[i] <= rightMin[i]) {
            return arr[i];
        }
    }
    
    return -1; // If no such element is found
}