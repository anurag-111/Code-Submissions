class Solution {
public:
    int strStr(string haystack, string needle) {
        int window = needle.size();
        int j = 0;
        int i = 0;
        while(j < haystack.size()) {
            if((j - i + 1) == window) {
                if(needle == haystack.substr(i, window)) {
                    return i;
                }
                i++;
            }
            j++;
        }
        return -1;
    }
};