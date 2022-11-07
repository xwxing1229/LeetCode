// https://leetcode.cn/problems/4sum-ii/

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int res = 0;
        unordered_map<int,int> record;
        for (int num1: nums1) {
            for (int num2: nums2) {
                record[num1 + num2] += 1;
            }
        }

        for (int num3: nums3) {
            for (int num4: nums4) {
                int sum_3_4 = -num3 - num4;
                if (record.find(-num3-num4) != record.end()) {
                    res += record[sum_3_4];
                }
            }
        }
        return res;
    }
};
