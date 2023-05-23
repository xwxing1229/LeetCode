// https://leetcode.cn/problems/largest-values-from-labels/

class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        int n = values.size();
        vector<int> idxs(n);
        for (int i = 0; i < n; ++i) {
            idxs[i] = i;
        }
        sort(idxs.begin(), idxs.end(), [&](int i, int j) {
            return values[i] > values[j];
        });
        int res = 0, nums = 0;
        unordered_map<int, int> cnt;
        for (int i: idxs) {
            if (nums == numWanted) {
                break;
            }
            if (cnt[labels[i]] < useLimit) {
                res += values[i];
                cnt[labels[i]] += 1;
                nums += 1;
            }
        }
        return res;
    }
};
