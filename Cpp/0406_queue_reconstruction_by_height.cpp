// https://leetcode.cn/problems/queue-reconstruction-by-height/

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](const vector<int>& v1, const vector<int>& v2) {
            return ((v1[0] < v2[0]) || (v1[0] == v2[0] && (v1[1] > v2[1])));
        });
        int n = people.size();
        vector<int> idxs(n);
        for (int i = 0; i < n; ++i) {
            idxs[i] = i;
        }

        vector<vector<int>> res(n, (vector<int>) {0,0});
        for (vector<int> person: people) {
            int idx = idxs[person[1]];
            res[idx] = person;
            idxs.erase(idxs.begin() + person[1]);
        }
        return res;
    }
};
