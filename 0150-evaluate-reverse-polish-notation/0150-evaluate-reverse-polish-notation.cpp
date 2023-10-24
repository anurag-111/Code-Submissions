class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long> st;
        for(auto x : tokens) {
            if(x == "+" || x == "-" || x == "*" || x == "/") {
                long operand2 = st.top();
                st.pop();
                long operand1 = st.top();
                st.pop();
                if(x == "+") {
                    st.push(operand1 + operand2);
                } else if(x == "-") {
                    st.push(operand1 - operand2);
                } else if(x == "*") {
                    st.push(operand1 * operand2);
                } else if(x == "/") {
                    st.push(operand1 / operand2);
                }
            } else {
                long num = stoi(x);
                st.push(num);
                
            }
        }
        return st.top();
    }
};