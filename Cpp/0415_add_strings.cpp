// https://leetcode.cn/problems/add-strings/

class Solution {
public:
    string addStrings(string num1, string num2) {
        int n1 = num1.size(), n2 = num2.size();
        if (n1 < n2) {
            string tmp_s = num1;
            num1 = num2;
            num2 = tmp_s;
            int tmp_n = n1;
            n1 = n2;
            n2 = tmp_n;
        }
        string res;
        int i = n1 - 1, carry = 0;
        for (int j = n2-1; j >= 0; --j) {
            int s = num1[i] - '0' + (num2[j] - '0') + carry;
            res += '0' + s % 10;
            carry = s / 10;
            i -= 1;
        }
        while (i >= 0) {
            int s = num1[i] - '0' + carry;
            res += '0' + s % 10;
            carry = s / 10;
            i -= 1;
        }
        if (carry > 0) {
            res += '1';
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
