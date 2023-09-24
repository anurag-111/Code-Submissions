class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> greaterElements;
        vector<int> result;
        stack<int> st;

        for(int i = 0; i < nums2.size(); i++) {
            while(!st.empty() && st.top() < nums2[i]) {
                greaterElements[st.top()] = nums2[i];
                st.pop();
            }
            st.push(nums2[i]);
        }

        for(int i = 0; i < nums1.size(); i++) {
            if(greaterElements.find(nums1[i]) != greaterElements.end()) {
                result.push_back(greaterElements[nums1[i]]);
            } else {
                result.push_back(-1);
            }
        }

        return result;
    }
};

