// https://leetcode.cn/problems/most-frequent-even-element/

class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (int num: nums) {
            if (num % 2 == 0) {
                cnt[num] += 1;
            }
        }
        int res = -1, appear = 0;
        for (auto it = cnt.begin(); it != cnt.end(); ++it) {
            if (res < 0 || appear < it->second || (appear == it->second && res > it->first)) {
                res = it->first;
                appear = it->second;
            }
        }
        return res;
    }
};
