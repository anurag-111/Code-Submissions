//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    string reverseWords (string s) {
        int start = 0;
    
        for(int end = 0; end <= s.size(); end++) {
            if(s[end] == '.' || end == s.size()) {
                int left = start;
                int right = end - 1;
                while(left < right) {
                    char temp = s[left];
                    s[left] = s[right];
                    s[right] = temp;
                    left++;
                    right--;
                }
                start = end + 1;
            }
        }
        return s;
    }
};



//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.reverseWords (s) << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends