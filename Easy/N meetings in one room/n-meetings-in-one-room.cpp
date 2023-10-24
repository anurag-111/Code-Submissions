//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(int startTime[], int endTime[], int n)
    {
        // Create a vector of pairs to store the start and end times of meetings.
        vector<pair<int, int>> meetings;

        for (int i = 0; i < n; i++)
        {
            meetings.push_back({endTime[i], startTime[i]});
        }

        // Sort meetings by their end times.
        sort(meetings.begin(), meetings.end());

        int rooms = 1;
        int prevEnd = meetings[0].first; // Initialize with the end time of the first meeting.

        for (int i = 1; i < n; i++)
        {
            if (meetings[i].second > prevEnd)
            {
                rooms++;
                prevEnd = meetings[i].first;
            }
        }

        return rooms;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends