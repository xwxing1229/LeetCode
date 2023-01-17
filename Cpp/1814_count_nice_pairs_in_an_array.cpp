// https://leetcode.cn/problems/count-nice-pairs-in-an-array/

class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        int res = 0;
        unordered_map<int,int> cnt;
        for (int num: nums) {
            int rev = 0, tmp = num;
            while (tmp) {
                rev = rev * 10 + tmp % 10;
                tmp /= 10;
            }
            res = (res + cnt[num - rev]) % 1000000007;
            cnt[num - rev] += 1;
        }
        return res;
    }
};
