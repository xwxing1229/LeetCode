// https://leetcode.cn/problems/majority-element-ii/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // Boyer–Moore majority vote algorithm.
        int tmp1 = 0, tmp2 = 0;
        int cnt1 = 0, cnt2 = 0;
        for (int i: nums) {
            if (i == tmp1) {
                cnt1 = cnt1 + 1;
            }
            else if (i == tmp2) {
                cnt2 = cnt2 + 1;
            }
            else if (cnt1 == 0) {
                tmp1 = i;
                cnt1 = 1;
            }
            else if (cnt2 == 0) {
                tmp2 = i;
                cnt2 = 1;
            }
            else {
                cnt1 = cnt1 - 1;
                cnt2 = cnt2 - 1;
            }
        }

        cnt1 = 0;
        cnt2 = 0;
        for (int i: nums) {
            if (i == tmp1) {
                cnt1 = cnt1 + 1;
            }
            else if (i == tmp2) {
                cnt2 = cnt2 + 1;
            }
        }

        vector<int> res;
        int k = nums.size() / 3;
        if (cnt1 > k) {
            res.push_back(tmp1);
        }
        if (cnt2 > k) {
            res.push_back(tmp2);
        }
        return res;
    }
};
