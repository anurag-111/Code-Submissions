//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    public:
    //Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string str) {
        vector<int> charFreq(26, 0);
        for(char ch : str) {
            charFreq[ch - 'a']++;
        }
        
        int maxOcc = INT_MIN;
        char maxChar;
        for(int i = 0; i < charFreq.size(); i++) {
            if(charFreq[i] > maxOcc) {
                maxOcc = charFreq[i];
                maxChar = i + 'a';
            }
        }
        
        return maxChar;
    }

};


//{ Driver Code Starts.

int main()
{
   
    int t;
    cin >> t;
    while(t--)
    {
        string str;
        cin >> str;
    	Solution obj;
        cout<< obj.getMaxOccuringChar(str)<<endl;
    }
}
// } Driver Code Ends