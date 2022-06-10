// https://leetcode.cn/problems/add-binary/

class Solution {
public:
    string addBinary(string a, string b) {
        int na = a.size(), nb = b.size(), carry = 0;
        if (na > nb) {
            b = string(na-nb, '0') + b;
        }
        else {
            a = string(nb-na, '0') + a;
            na = nb;
        }

        string res(na, '0');
        for (int i = na-1; i >= 0; --i) {
            int tmp = a[i] - '0' + b[i] - '0' + carry;
            carry = tmp / 2;
            res[i] = tmp - 2 * carry + '0';
        }
        if (carry > 0) {
            res = '1' + res;
        }
        return res;
    }
};
