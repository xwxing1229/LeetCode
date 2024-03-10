// https://leetcode.cn/problems/find-a-peak-element-ii/

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int rows = mat.size();
        int low = 0, high = rows-1;
        vector<int> res(2, -1);
        while (low <= high) {
            int mid = (low + high) / 2;
            int j = max_element(mat[mid].begin(), mat[mid].end()) - mat[mid].begin();
            if (mid > 0 && mat[mid][j] < mat[mid-1][j]) {
                high = mid - 1;
                continue;
            }
            if (mid < rows-1 && mat[mid][j] < mat[mid+1][j]) {
                low = mid + 1;
                continue;
            }
            res[0] = mid;
            res[1] = j;
            return res;
        }
        return res;
    }
};