// https://leetcode.cn/problems/merge-similar-items/

class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        sort(items1.begin(), items1.end());
        sort(items2.begin(), items2.end());
        int i = 0, j = 0;
        vector<vector<int>> res;
        while (i < items1.size() && j < items2.size()) {
            int value, weight;
            if (items1[i][0] < items2[j][0]) {
                value = items1[i][0];
                weight = items1[i][1];
                i += 1;
            }
            else {
                value = items2[j][0];
                weight = items2[j][1];
                j += 1;
                if (items1[i][0] == value) {
                    weight += items1[i][1];
                    i += 1;
                }
            }
            if (res.size() == 0 || res.back()[0] < value) {
                res.push_back(vector<int> {value, weight});
            }
            else {
                res.back()[1] += weight;
            }
        }
        if (i == items1.size()) {
            while (j < items2.size()) {
                if (res.back()[0] == items2[j][0]) {
                    res.back()[1] += items2[j][1];
                }
                else {
                    res.push_back(items2[j]);
                }
                j += 1;
            }
        }
        else {
            while (i < items1.size()) {
                if (res.back()[0] == items1[i][0]) {
                    res.back()[1] += items1[i][0];
                }
                else {
                    res.push_back(items1[i]);
                }
                i += 1;
            }
        }
        return res;
    }
};
