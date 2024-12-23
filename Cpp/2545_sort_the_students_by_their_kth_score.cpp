// https://leetcode.cn/problems/sort-the-students-by-their-kth-score/

class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        sort(score.begin(), score.end(), [&](const vector<int> &si, const vector<int> &sj) {
            return si[k] > sj[k];
        });
        return score;
    }
};
