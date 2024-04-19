// https://leetcode.cn/problems/find-original-array-from-doubled-array/

class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        sort(changed.begin(), changed.end());
        unordered_map<int, int> cnt;
        for (auto num: changed) {
            cnt[num] += 1;
        }

        vector<int> res;
        for (auto num: changed) {
            if (cnt[num] <= 0) continue;
            if (cnt[2*num] > 0) {
                cnt[num] -= 1;
                cnt[2*num] -= 1;
                res.push_back(num);
            }
            else {
                res.clear();
                return res;
            }
        }
        for (auto it = cnt.begin(); it != cnt.end(); ++it) {
            if (it->second != 0) {
                res.clear();
                return res;
            }
        }
        return res;
    }
};
