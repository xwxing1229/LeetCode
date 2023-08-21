// https://leetcode.cn/problems/move-pieces-to-obtain-a-string/

class Solution {
public:
    bool canChange(string start, string target) {
        int i = 0, n = start.size();
        for (int j = 0; j < n; ++j) {
            if (target[j] == 'L') {
                while (i < n && start[i] == '_') {
                    i += 1;
                }
                if (i == n || i < j || start[i] == 'R') {
                    return false;
                }
                i += 1;
            }
            else if (target[j] == 'R') {
                while (i < n && start[i] == '_') {
                    i += 1;
                }
                if (i == n || i > j || start[i] == 'L') {
                    return false;
                }
                i += 1;
            }
        }
        while (i < n) {
            if (start[i] != '_') {
                return false;
            }
            i += 1;
        }
        return true;
    }
};
