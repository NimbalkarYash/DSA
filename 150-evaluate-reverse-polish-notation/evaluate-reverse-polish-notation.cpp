class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(string n: tokens)
        {
            if(n == "+" || n == "-" || n == "*" || n == "/")
            {
                int b = st.top();
                st.pop();

                int a = st.top();
                st.pop();

                if(n == "+")
                {
                    st.push(a+b);
                }
                else if(n == "/")
                {
                    st.push(a/b);
                }
                else if(n == "-")
                {
                    st.push(a-b);
                }
                else if(n == "*")
                {
                    st.push(a*b);
                }
                else
                {
                    continue;
                }
            }
            else
            {
                st.push(stoi(n));
            }
        }
        return st.top();
    }
};