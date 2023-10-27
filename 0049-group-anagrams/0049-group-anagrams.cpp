// Your input: ["eat","tea","tan","ate","nat","bat"]

// stdout : key: a1e1t1
//          key: a1e1t1
//          key: a1n1t1
//          key: a1e1t1
//          key: a1n1t1
//          key: a1b1t1
         
// Output: [["bat"],["tan","nat"],["eat","tea","ate"]]


class Solution {
    private:
        string generateKey(string str) {
            vector<int> freq(26, 0);
            for(int i = 0; i < str.size(); i++) {
                freq[str[i] - 'a']++;
            }
            
            string key = "";
            for(int i = 0; i < 26; i++) {
                if(freq[i] > 0) {
                    key += (i + 'a');
                    key += to_string(freq[i]);
                }
            }
            
            cout << "key: " << key << endl;
            return key;
        }
    
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
            // Result
            vector<vector<string>> groupAnagrams;
            // Mapping
            unordered_map<string, vector<string>> bucketMap;
            
            for(string str : strs) {
                string key = generateKey(str);
                bucketMap[key].push_back(str);
            }
            
            for (pair<string, vector<string>> group : bucketMap) {
                groupAnagrams.push_back(group.second);
            }
            
            return groupAnagrams;
        }
};