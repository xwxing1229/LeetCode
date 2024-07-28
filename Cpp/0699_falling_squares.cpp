// https://leetcode.cn/problems/falling-squares/

class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        int n = positions.size();
        vector<int> heights(n);
        for (int i = 0; i < n; ++i) {
            int left_i = positions[i][0], side_i = positions[i][1];
            int right_i = left_i + side_i;
            heights[i] = side_i;

            for (int j = 0; j < i; ++j) {
                int left_j = positions[j][0], side_j = positions[j][1];
                int right_j = left_j + side_j;
                if (right_j > left_i && left_j < right_i) {
                    heights[i] = max(heights[i], heights[j]+side_i);
                }
            }
        }
        vector<int> res(n, heights[0]);
        for (int i = 1; i < n; ++i) {
            res[i] = max(res[i-1], heights[i]);
        }
        return res;
    }
};
