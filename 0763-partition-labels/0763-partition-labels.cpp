class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> lastOcc;
        for(int i = 0; i < s.size(); i++) {
            lastOcc[s[i]] = i;
        }
        
        int partitionStart = 0;
        int partitionEnd = 0;
        vector<int> result;
        
        for(int i = 0; i < s.size(); i++) {
            partitionEnd = max(partitionEnd, lastOcc[s[i]]);
            
            // Partition found
            if(partitionEnd == i) {
                result.push_back(partitionEnd - partitionStart + 1);
                partitionStart = partitionEnd + 1;
            }
        }
        
        return result;
    }
};