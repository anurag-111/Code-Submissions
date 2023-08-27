//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{   
public:
    vector<int> countChars (string s)
    {
        // code here
        int count = 0;
        vector<int> result;
        
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == ' ') {
                result.push_back(count);
                count = 0;
            }
            else {
                count++;
            }
        }
        result.push_back(count);
        return result;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; 
    cin >> t;
    cin.ignore ();
    while (t--)
    {
        string s;
        getline (cin, s);
        Solution ob;
        vector <int> result = ob.countChars(s);
        for (int i : result)
            cout << i << " ";
        cout << endl;
    }
}
// } Driver Code Ends