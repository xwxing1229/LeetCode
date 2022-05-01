// https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> table{
            {'2', "abc"}, {'3', "def"},
            {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"},
            {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
        };
        vector<string> res;
        if (digits.size() == 0)
            return res;

        res.push_back("");
        for (char num: digits) {
            int res_len = res.size();
            for (int i = 0; i < res_len; ++i) {
                string tmp = res.back();
                res.pop_back();

                for (char c: table[num]) {
                    string tmp_new = tmp + c;
                    res.insert(res.begin(), tmp_new);
                }
            }
        }

        return res;
    }
};