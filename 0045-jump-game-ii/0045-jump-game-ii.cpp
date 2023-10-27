class Solution {
public:
    int jump(vector<int>& nums) {
        int currJump = 0;
        int maxJump = 0;
        int jumps = 0;
        
        for(int i = 0; i < nums.size() - 1; i++) {
            currJump = max(currJump, i + nums[i]);
            
            if(i == maxJump) {
                maxJump = currJump;
                jumps++;
            }
        }
        
        return jumps;
    }
};