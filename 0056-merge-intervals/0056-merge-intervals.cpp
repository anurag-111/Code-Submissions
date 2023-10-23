class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        // 1. Sort the intervals by their start times.
        sort(intervals.begin(), intervals.end());
        
        // 2. Initialize an empty result vector and add the first interval.
        vector<vector<int>> result;
        result.push_back(intervals[0]);
        
        // 3. Loop through the intervals, merging overlapping ones into the last added interval 
        // or adding non-overlapping ones to the result.
        for(vector<int> interval : intervals) {
            if(result.back()[1] >= interval[0]) {
                result.back()[1] = max(result.back()[1], interval[1]);
            } else {
                result.push_back(interval);
            }
        }
        
        // 4. Return the merged intervals in the result vector.
        return result;
        
    }
};