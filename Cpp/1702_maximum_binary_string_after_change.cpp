// https://leetcode.cn/problems/maximum-binary-string-after-change/

class Solution {
public:
    string maximumBinaryString(string binary) {
        string res(binary.size(), '1');
        int idx = -1;
        for (int i = 0; i < binary.size(); ++i) {
            char ch = binary[i];
            if (ch == '0') {
                if (idx < 0) idx = i;
                else idx += 1;
            }
        }
        if (idx >= 0) {
            res[idx] = '0';
        }
        return res;
    }
};
