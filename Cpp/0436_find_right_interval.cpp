// https://leetcode.cn/problems/find-right-interval/

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> idxs(n), res(n,-1);
        for (int i = 0; i < n; ++i) {
            idxs[i] = i;
        }
        sort(idxs.begin(), idxs.end(),
            [&](const int idx1, const int idx2) {
                return intervals[idx1][0] < intervals[idx2][0];
            });

        for (int i = 0; i < n; ++i) {
            int left = i, right = n-1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (intervals[idxs[i]][1] <= intervals[idxs[mid]][0]) {
                    res[idxs[i]] = idxs[mid];
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }
            }
        }
        return res;
    }
};
