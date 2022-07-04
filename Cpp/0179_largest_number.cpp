// https://leetcode.cn/problems/largest-number/

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> nums_s;
        for (int num: nums) {
            string num_s = to_string(num);
            nums_s.push_back(num_s);
        }

        sort(nums_s.begin(), nums_s.end(),
            [](string s1, string s2) {
                string s1s2 = s1 + s2;
                string s2s1 = s2 + s1;
                return s1s2 > s2s1;
            });

        string res = "";
        for (string num_s: nums_s) {
            res = res + num_s;
        }
        if (res[0] == '0') {
            res = "0";
        }
        return res;
    }
};
