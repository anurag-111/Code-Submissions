class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> stringMap;
        vector<string> result;

        if(s.size() < 9) {
            return result;
        }

        for(int i = 0; i < s.size() - 9; i++) {
            stringMap[s.substr(i, 10)]++;
        }

        for(pair<string, int> pair : stringMap) {
            if(pair.second > 1) {
                result.push_back(pair.first);
            }
        }

        return result;
    }
};