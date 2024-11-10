// https://leetcode.cn/problems/lexicographically-smallest-string-after-a-swap/

class Solution {
public:
    string getSmallestString(string s) {
        for (int i = 0; i < s.size()-1; ++i) {
            char ch1 = s[i], ch2 = s[i+1];
            int num1 = ch1 - '0', num2 = ch2 - '0';
            if ((num1 % 2 == num2 % 2) && (num1 > num2)) {
                s[i] = ch2;
                s[i+1] = ch1;
                break;
            }
        }
        return s;
    }
};
