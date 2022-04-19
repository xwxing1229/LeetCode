// https://leetcode-cn.com/problems/integer-to-roman/

class Solution {
public:
    string intToRoman(int num) {
        map<int, string> table{
            {1000, "M"},
            {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},
            {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"},
            {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
        };

        int key, quo, rem;
        string res = "";
        for (auto iter = table.rbegin(); iter != table.rend(); ++iter) {
            key = iter->first;
            quo = num / key;
            num = num - quo * key;

            string tmp = "";
            for (int i = 0; i < quo; ++i) {
                tmp = tmp + iter->second;
            }
            res = res + tmp;
        }

        return res;
    }
};