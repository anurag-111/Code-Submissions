//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
public:
	int binaryPalin(long long int N) {
	    vector<int> binaryForm;
	    while(N > 0){
	        int bit = N & 1;
	        binaryForm.push_back(bit);
	        N >>= 1;
	    }
	    
	   // for(int num : binaryForm) {
	   //     cout << num << " ";
	   // }
	    
	   int i = 0;
	   int j = binaryForm.size() - 1;
	   while(i < j) {
	       if(binaryForm[i] != binaryForm[j]) {
	           return false;
	       }
	       i++;
	       j--;
	   }
	   
	   return true;
	}
};


//{ Driver Code Starts.

int main()
{
	int t; cin >> t;
	while (t--)
	{
		long long int n; cin >> n;
		Solution ob;
		cout << ob.binaryPalin (n) << endl;
	}
}

// Contributed By: Pranay Bansal

// } Driver Code Ends