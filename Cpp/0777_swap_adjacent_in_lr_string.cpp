// https://leetcode.cn/problems/swap-adjacent-in-lr-string/

class Solution {
public:
    bool canTransform(string start, string end) {
        int n = start.size();
        if (n != end.size()) {
            return false;
        }
        int i = 0, j = 0;
        while ((i < n) && (j < n)) {
            while ((i < n) && (start[i] == 'X')) {
                i = i + 1;
            }
            while ((j < n) && (end[j] == 'X')) {
                j = j + 1;
            }
            if ((i == n) || (j == n)) {
                break;
            }
            if (start[i] != end[j]) {
                return false;
            }
            if ((start[i] == 'L') && (i < j)) {
                return false;
            }
            if ((start[i] == 'R') && (i > j)) {
                return false;
            }

            i = i + 1;
            j = j + 1;
        }

        if (i == n) {
            for (int k = j; k < n; ++k) {
                if (end[k] != 'X') {
                    return false;
                }
            }
        }
        else {
            for (int k = i; k < n; ++k) {
                if (start[k] != 'X') {
                    return false;
                }
            }
        }
        return true;
    }
};
