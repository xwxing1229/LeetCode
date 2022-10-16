// https://leetcode.cn/problems/third-maximum-number/

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int max_1 = INT_MIN, max_2 = INT_MIN, max_3 = INT_MIN;
        for (auto it = s.begin(); it != s.end(); ++it) {
            if (*it > max_1) {
                max_3 = max_2;
                max_2 = max_1;
                max_1 = *it;
            }
            else if (*it > max_2) {
                max_3 = max_2;
                max_2 = *it;
            }
            else if (*it > max_3) {
                max_3 = *it;
            }
        }
        if (s.size() < 3) {
            return max_1;
        }
        else {
            return max_3;
        }
    }
};
