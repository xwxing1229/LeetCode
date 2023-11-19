// https://leetcode.cn/problems/max-sum-of-a-pair-with-equal-sum-of-digits/

class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int res = -1;
        unordered_map<int, int> record;
        for (int num: nums) {
            int digitsum = 0, tmp = num;
            while (tmp > 0) {
                digitsum += tmp % 10;
                tmp /= 10;
            }
            if (record.find(digitsum) != record.end()) {
                res = max(res, record[digitsum] + num);
                record[digitsum] = max(record[digitsum], num);
            }
            else {
                record[digitsum] = num;
            }
        }
        return res;
    }
};