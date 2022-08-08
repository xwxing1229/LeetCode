// https://leetcode.cn/problems/maximum-product-of-word-lengths/

class Solution {
public:
    int maxProduct(vector<string>& words) {
        unordered_map<int, int> masks;
        for (string word: words) {
            int mask = 0, len = word.size();
            for (int j = 0; j < len; ++j) {
                mask = mask | (1 << (word[j] - 'a'));
            }
            if (masks.find(mask) == masks.end()) {
                masks[mask] = len;
            }
            else if (masks[mask] < len) {
                masks[mask] = len;
            }
        }

        int res = 0;
        for (auto &map1: masks) {
            int mask1 = map1.first, len1 = map1.second;
            for (auto &map2: masks) {
                if ((mask1 & map2.first) == 0) {
                    int tmp = len1 * map2.second;
                    res = max(res, tmp);
                }
            }
        }
        return res;
    }
};
