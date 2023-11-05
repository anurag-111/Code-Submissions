class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int, int> freq;
        vector<int> result;
        for(int num : nums) {
            freq[num]++;
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(auto itr = freq.begin(); itr != freq.end(); itr++) {
            pq.push({itr -> second, itr -> first});
            
            if(pq.size() > k) {
                pq.pop();
            }
        }
        
        while(!pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();
        }
        
        return result;
        
    }
};