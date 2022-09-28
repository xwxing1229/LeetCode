// https://leetcode.cn/problems/k-th-smallest-prime-fraction/

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        auto cmp = [&](const pair<int,int>& pair1, const pair<int,int>& pair2) {
            return arr[pair1.first] * arr[pair2.second] > arr[pair1.second] * arr[pair2.first];
        };

        int n = arr.size();
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> pq(cmp);
        for (int i = 0; i < n-1; ++i) {
            pq.push(make_pair(i, n-1));
        }

        for (int i = 0; i < k-1; ++i) {
            pair<int,int> idxs = pq.top();
            pq.pop();

            if (idxs.second - 1 > idxs.first) {
                pq.push(make_pair(idxs.first, idxs.second-1));
            }
        }
        vector<int> res = {arr[pq.top().first], arr[pq.top().second]};

        return res;
    }
};
