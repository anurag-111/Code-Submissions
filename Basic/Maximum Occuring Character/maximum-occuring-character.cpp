//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    public:
    //Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string str){
        int size = 26;
        vector<int> freq(size, 0);
        
        for(int i = 0; i < str.size(); i++) {
            int index = str[i] - 'a';
            freq[index]++;
        }
        
        // for(int frq : freq) {
        //     cout << frq << " ";
        // }
        // cout << endl;
        
        int maxCount = INT_MIN;
        char maxChar = ' ';
        for(int i = 0; i < 26; i++) {
            if(maxCount < freq[i]) {
                maxCount = freq[i];
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