// https://leetcode.cn/problems/longest-subsequence-with-limited-sum/

class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size(), m = queries.size();
        vector<int> res(m, 0);

        sort(nums.begin(), nums.end());
        vector<int> idxs(m);
        for (int j = 0; j < m; ++j) {
            idxs[j] = j;
        }

        sort(idxs.begin(), idxs.end(), [&](int j1, int j2) {
            return queries[j1] < queries[j2];
        });
        int i = 0, cumsum = 0;
        for (int j = 0; j < m; ++j) {
            int idx = idxs[j], query = queries[idx];
            while (i < n && cumsum <= query) {
                cumsum += nums[i];
                i += 1;
            }
            if (cumsum <= query) {
                res[idx] = i;
            }
            else {
                res[idx] = i - 1;
            }
        }
        return res;
    }
};
