//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    private :
        bool isPossible(vector<int> &stalls, int distance, int cows) {
            int cowsCount = 1;
            int previous = stalls[0];
            
            for(int i = 0; i < stalls.size(); i++) {
                if(stalls[i] - previous >= distance) {
                    cowsCount++;
                    previous = stalls[i];
                } 
            
                if(cowsCount >= cows) {
                    return true;
                }
            }
            
            return false;
        }
    
    public :
    
        int solve(int n, int k, vector<int> &stalls) {
            sort(stalls.begin(), stalls.end());
            
            int low = 1;
            int high = stalls[stalls.size() - 1] - stalls[0];
            
            while(low <= high) {
                int mid = low + (high - low) / 2;
                
                if(isPossible(stalls, mid, k)) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            
            return high;
        }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends