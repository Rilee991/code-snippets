class Solution {
public:
    bool canBeValid(string s, string locked) {
        // 0 1
        // (()(()(())))
        stack<int> st;
        int open = 0, close = 0, flex = 0;

        for(int i=0;i<s.size();i++) {
            if(!st.empty() && s[i] == ')' && s[st.top()] == '(') {
                st.pop();
            } else {
                st.push(i);
            }
        }


        if(st.empty())
            return true;
        // 0
        // op = 0, cl = 0, fl = 2
        while(!st.empty()) {
            int idx = st.top();
            st.pop();

            if(locked[idx] == '0') {
                if(close) close--;
                else flex++;
            } else {
                if(s[idx] == '(') {
                    if(close)
                        close--;
                    else if(flex)
                        flex--;
                    else
                        return false;
                } else {
                    close++;
                }
            }

            // 0 0 - continue
            // 0 1 - if idx1 is locked and is open bracket then false, else continue
            // 1 0 - if
        }

        return (close + flex)%2 == 0;
    }
};