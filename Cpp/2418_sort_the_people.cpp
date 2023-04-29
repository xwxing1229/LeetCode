// https://leetcode.cn/problems/sort-the-people/

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        vector<int> idxs(n);
        for (int i = 0; i < n; ++i) {
            idxs[i] = i;
        }
        sort(idxs.begin(), idxs.end(), [&](int i, int j) {
            return heights[i] > heights[j];
        });
        vector<string> res(n);
        for (int i = 0; i < n; ++i) {
            res[i] = names[idxs[i]];
        }
        return res;
    }
};
