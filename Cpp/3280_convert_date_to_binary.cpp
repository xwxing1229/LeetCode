// https://leetcode.cn/problems/convert-date-to-binary/

class Solution {
public:
    string convertDateToBinary(string date) {
        string res = "";
        res += to_binary(date.substr(0, 4));
        res += '-';
        res += to_binary(date.substr(5, 2));
        res += '-';
        res += to_binary(date.substr(8, 2));
        return res;
    }

    string to_binary(string s) {
        string res = "";
        int num = stoi(s);
        while (num) {
            res += '0' + (num & 1);
            num >>= 1;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
