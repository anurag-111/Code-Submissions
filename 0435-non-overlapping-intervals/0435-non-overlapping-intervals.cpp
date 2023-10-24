class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // Step 1 : Sort the intervals on the basis of start time
        sort(intervals.begin(), intervals.end());
        
        // Step 2 : Classify the overlapping cases
        int left = 0;
        int right = 1;
        int count = 0;
        int noOfIntervals = intervals.size();
        
        while(right < noOfIntervals) {
            // Case 1 : No overlapping occurs
            if(intervals[left][1] <= intervals[right][0]) {
                left = right++;
            } 
            // Case 2 : Overlapping case 1
            else if(intervals[left][1] <= intervals[right][1]) {
                // Remove the right interval
                right++;
                count++;
            } 
            // Case 2 : Overlapping case 1
            else if(intervals[left][1] > intervals[right][1]) {
                // Remove the left interval
                left = right;
                right++;
                count++;
            }
        }
        
        return count;
    }
};