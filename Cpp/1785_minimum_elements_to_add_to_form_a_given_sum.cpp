// https://leetcode.cn/problems/minimum-elements-to-add-to-form-a-given-sum/

class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        int diff = -goal;
        for (int num: nums) {
            diff += num;
        }
        int res = (abs(diff) + limit - 1) / limit;
        return res;
    }
};
