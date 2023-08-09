//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
  private:
  // Function for merging
  long long merge(long long arr[], long long temp[], long long left, long long mid, long long right) {
      long long i, j, k;
      long long inversionCount = 0;
      
      i = left;
      j = mid;
      k = left;
      
      while((i <= mid - 1) && (j <= right)) {
          if(arr[i] <= arr[j]) {
              temp[k++] = arr[i++];
          } else {
              temp[k++] = arr[j++];
              inversionCount += (mid - i);
          }
      }
      
      while(i <= mid - 1) {
          temp[k++] = arr[i++];
      }
      
      while(j <= right) {
          temp[k++] = arr[j++];
      }
      
      for(long long i = left; i <= right; i++) {
          arr[i] = temp[i];
      }
      
      return inversionCount;
  }
  
  
  
  // Function for merge sort
  long long mergeSort(long long arr[], long long temp[], long long left, long long right) {
      long long mid;
      long long inversionCount = 0;
      
      if(right > left) {
          mid = (right + left) / 2;
          inversionCount += mergeSort(arr, temp, left, mid);
          inversionCount += mergeSort(arr, temp, mid + 1, right);
          inversionCount += merge(arr, temp, left, mid + 1, right);
      }
      
      return inversionCount;
  }
  
  public:
    // Function to count inversions in the array.
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        long long temp[N];
        return mergeSort(arr, temp, 0, N - 1);
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