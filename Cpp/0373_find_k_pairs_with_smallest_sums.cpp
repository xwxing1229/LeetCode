// https://leetcode.cn/problems/find-k-pairs-with-smallest-sums/

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        auto cmp = [&](const vector<int>& pair1, const vector<int>& pair2) {
            return nums1[pair1[0]] + nums2[pair1[1]] > nums1[pair2[0]] + nums2[pair2[1]];
        };

        int m = nums1.size(), n = nums2.size();
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
        for (int i = 0; i < m; ++i) {
            pq.push((vector<int>) {i, 0});
        }

        vector<vector<int>> res;
        while ((res.size() < k) && (!pq.empty())) {
            vector<int> idxs = pq.top();
            pq.pop();
            res.push_back((vector<int>) {nums1[idxs[0]], nums2[idxs[1]]});
            
            if (idxs[1] + 1 < n) {
                idxs[1] = idxs[1] + 1;
                pq.push(idxs);
            }
        }
        return res;
    }
};
