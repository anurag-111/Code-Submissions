class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string temp = "";
        string ans = "";

        for (char c : s) {
            if (c == ' ') {
                if (!temp.empty())
                    st.push(temp);
                temp = "";
            } else {
                temp += c;
            }
        }

        ans += temp;

        while (!st.empty()) {
            ans += " " + st.top();
            st.pop();
        }

        if (!ans.empty() && ans[0] == ' ')
            ans = ans.substr(1);

        return ans;
    }
};

