class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> tempStack;
        vector<int> warmTemp(temperatures.size());
        
        for(int i = 0; i < temperatures.size(); i++) {
            while(!tempStack.empty() && temperatures[tempStack.top()] < temperatures[i]) {
                warmTemp[tempStack.top()] = i - tempStack.top();
                tempStack.pop();
            }
            
            tempStack.push(i);
        }
        
        return warmTemp;        
    }
};