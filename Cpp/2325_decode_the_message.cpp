// https://leetcode.cn/problems/decode-the-message/

class Solution {
public:
    string decodeMessage(string key, string message) {
        vector<char> table(26, ' ');
        int idx = 0;
        for (char ch: key) {
            if (ch != ' ' && table[ch-'a'] == ' ') {
                table[ch-'a'] = 'a' + idx;
                idx += 1;
            }
        }
        string res;
        for (char ch: message) {
            if (ch == ' ') res += ch;
            else res += table[ch-'a'];
        }
        return res;
    }
};