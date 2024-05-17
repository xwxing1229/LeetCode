// https://leetcode.cn/problems/most-profit-assigning-work/

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size();
        vector<pair<int, int>> work;
        for (int i = 0; i < n; ++i) {
            work.push_back(make_pair(difficulty[i], profit[i]));
        }
        sort(work.begin(), work.end(), [](const pair<int,int> &p1, const pair<int,int> &p2) {
            return p1.first <= p2.first;
        });
        sort(worker.begin(), worker.end());

        int res = 0;
        int i = 0, p_max = 0;
        for (auto w: worker) {
            while (i < n && work[i].first <= w) {
                p_max = max(p_max, work[i].second);
                i += 1;
            }
            res += p_max;
        }
        return res;
    }
};
