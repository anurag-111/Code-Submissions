class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int stone : stones) {
            pq.push(stone);
        }
        
        while(pq.size() >= 2) {
            int y = pq.top();
            pq.pop();
            int x = pq.top();
            pq.pop();
            
            if(y >= x) {
                if(x == y) {
                    continue;
                } else if(x != y) {
                    pq.push(y - x);
                }
            }
        }
        
        if(pq.empty()) {
            return 0;
        }
        
        return pq.top();
    }
};