//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long merge(long long arr[], long long temp[], long long low, long long mid, long long high) {
        long long i, j, k;
        i = low;
        j = mid;
        k = low;
        
        long long inversion_count = 0;
        
        while((i <= mid - 1) && (j <= high)) {
            if(arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            } else {
                temp[k++] = arr[j++];
                inversion_count += (mid - i);
            }
        }
        
        while(i <= mid - 1) {
            temp[k++] = arr[i++];
        }
        
        while(j <= high) {
            temp[k++] = arr[j++];
        }
        
        for(long long i = low; i <= high; i++) {
            arr[i] = temp[i];
        }
        
        return inversion_count;
    }
    
    long long merge_sort(long long arr[], long long temp[], long long low, long long high) {
        long long inversion_count = 0;
        long long mid;
        if(high > low) {
            mid = (high + low) / 2;
            inversion_count += merge_sort(arr, temp, low, mid);
            inversion_count += merge_sort(arr, temp, mid + 1, high);
            inversion_count += merge(arr, temp, low, mid + 1, high);
        }
        return inversion_count;
    }
    
    long long int inversionCount(long long arr[], long long N) {
        long long temp[N];
        return merge_sort(arr, temp, 0, N - 1);
        
    }

};


//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends