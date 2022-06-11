// https://leetcode.cn/problems/search-a-2d-matrix/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(), cols = matrix[0].size();
        int left = 0, right = rows-1, row = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int val = matrix[mid][0];
            if (val <= target) {
                left = mid + 1;
                row = mid;
            }
            else {
                right = mid - 1;
            }
        }

        left = 0;
        right = cols - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int val = matrix[row][mid];
            if (val < target) {
                left = mid + 1;
            }
            else if (val > target) {
                right = mid - 1;
            }
            else {
                return true;
            }
        }
        return false;
    }
};
