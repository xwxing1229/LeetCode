// https://leetcode.cn/problems/remove-k-digits/

class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<char> st;
        for (char ch: num) {
            while ((st.size() > 0) && (st.back() > ch) && (k > 0)) {
                st.pop_back();
                k = k - 1;
            }
            st.push_back(ch);
        }
        while (k > 0) {
            st.pop_back();
            k = k - 1;
        }

        string res = "";
        bool ignore0 = true;
        for (char ch: st) {
            if ((ch == '0') && (ignore0)) {
                continue;
            }
            ignore0 = false;
            // res = res + ch; // time limit exceeded
            res += ch;
        }
        if (res == "") {
            res = "0";
        }
        return res;
    }
};