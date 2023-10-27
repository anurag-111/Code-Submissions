class Solution {
private:
    void findCombination(int index, vector<int>& candidates, int target, vector<int> &combination, vector<vector<int>> &result) {
        if (target == 0) {
            result.push_back(combination);
            return;
        }
        
        for (int i = index; i < candidates.size(); i++) {
            if (candidates[i] > target) {
                break;
            }
            
            combination.push_back(candidates[i]);
            findCombination(i, candidates, target - candidates[i], combination, result);
            combination.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<int> combination;
        vector<vector<int>> result;

        findCombination(0, candidates, target, combination, result);

        return result;
    }
};
