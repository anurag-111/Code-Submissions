//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
string isCircular(string path);

int main(){
    int t;
    cin >> t;
    while(t--){
        string path;
        cin >> path;
        cout << isCircular(path) << endl;
    }
return 0;
}
// } Driver Code Ends


string isCircular(string path) {
    int x = 0, y = 0, axis = 0;

    for (int i = 0; i < path.length(); i++) {
        if (path[i] == 'L')
            axis--;
        else if (path[i] == 'R')
            axis++;
        else if (path[i] == 'G') {
            if (abs(axis % 4) == 0) {
                y++;
            } else if (abs(axis % 4) == 1) {
                x--;
            } else if (abs(axis % 4) == 2) {
                y--;
            } else if (abs(axis % 4) == 3) {
                x++;
            }
        }
    }

    if (x == 0 && y == 0)
        return "Circular";
    else
        return "Not Circular";
}
