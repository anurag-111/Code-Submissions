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
    int max[n];
    int min[n];
    
    int big = arr[0];
    int small = arr[n - 1];
    
    for(int i = 0; i < n; i++) {
        big = std::max(arr[i], big);
        max[i] = big;
    }
    
    for(int i = n - 1; i >= 0; i--) {
        small = std::min(arr[i], small);
        min[i] = small;
    }
    
    for(int i = 0; i < n; i++) {
        if(i != 0 && i < n - 1) {
            if(max[i] == min[i]) {
                return max[i];
            }
        }
    }
    
    return -1;
}