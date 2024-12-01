// https://leetcode.cn/problems/image-smoother/

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size(), n = img[0].size();
        vector<vector<int>> res(m, vector<int>(n,0));
        vector<vector<pair<int,int>>> dirs(3, vector<pair<int,int>>(3));
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                dirs[i][j].first = i-1;
                dirs[i][j].second = j-1;
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int s = 0, cnt = 0;
                for (int di = 0; di < 3; ++di) {
                    for (int dj = 0; dj < 3; ++dj) {
                        int i0 = i + dirs[di][dj].first;
                        int j0 = j + dirs[di][dj].second;
                        if (i0 < 0 || i0 >= m || j0 < 0 || j0 >= n) continue;
                        s += img[i0][j0];
                        cnt += 1;
                    }
                }
                res[i][j] = s / cnt;
            }
        }
        return res;
    }
};
