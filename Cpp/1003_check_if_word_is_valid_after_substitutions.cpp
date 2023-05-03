// https://leetcode.cn/problems/check-if-word-is-valid-after-substitutions/

class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        if (n % 3 != 0) {
            return false;
        }
        vector<char> st;
        for (char ch: s) {
            if (ch == 'c') {
                int len = st.size();
                if (len >= 2 && st.back() == 'b' && st[len-2] == 'a') {
                    st.pop_back();
                    st.pop_back();
                }
                else {
                    st.push_back(ch);
                }
            }
            else {
                st.push_back(ch);
            }
        }
        return st.size() == 0 ? true: false;
    }
};