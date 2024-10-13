// https://leetcode.cn/problems/find-the-number-of-good-pairs-ii/

class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        unordered_map<int, long long> cnts;
        for (int i = 0; i < nums1.size(); ++i) {
            int num = nums1[i];
            if (num % k != 0) {
                continue;
            }
            num /= k;
            for (int val = 1; val <= sqrt(num); ++val) {
                if (num % val == 0) {
                    cnts[val] += 1;
                    if (val * val != num) {
                        cnts[num / val] += 1;
                    }
                }
            }
        }
        long long res = 0;
        for (int num: nums2) {
            res += cnts[num];
        }
        return res;
    }
};

