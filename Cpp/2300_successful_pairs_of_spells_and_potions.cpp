// https://leetcode.cn/problems/successful-pairs-of-spells-and-potions/

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int m = spells.size(), n = potions.size();
        vector<int> res(m, 0);
        sort(potions.begin(), potions.end());
        for (int i = 0; i < m; ++i) {
            long long spell = spells[i];
            int left = 0, right = n-1, start = n;
            while (left <= right) {
                int mid = (left + right) / 2;
                if (spell * potions[mid] >= success) {
                    right = mid - 1;
                    start = mid;
                }
                else {
                    left = mid + 1;
                }
            }
            res[i] = n - start;
        }
        return res;
    }
};