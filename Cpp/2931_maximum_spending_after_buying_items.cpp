// https://leetcode.cn/problems/maximum-spending-after-buying-items/
      
class Solution {
public:
    long long maxSpending(vector<vector<int>>& values) {
        using pi = pair<int, int>;

        int m = values.size(), n = values[0].size();
        priority_queue<pi, vector<pi>, greater<pi>> items;
        for (int i = 0; i < m; ++i) {
            items.push(make_pair(values[i].back(), i));
        }
        vector<int> idxs(m, n-1);

        long long res = 0;
        int days = 0;
        while (!items.empty()) {
            pi val_idx = items.top();
            items.pop();
            days += 1;
            res += (long long)val_idx.first * days;

            int i = val_idx.second;
            idxs[i] -= 1;
            if (idxs[i] >= 0) items.push(make_pair(values[i][idxs[i]], i));
        }
        return res;
    }
};
