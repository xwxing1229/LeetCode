// https://leetcode.cn/problems/utf-8-validation/

class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int i = 0, n = data.size();
        while (i < n) {
            int num = data[i];
            if ((num & 128) == 0) {
                i = i + 1;
                continue;
            }

            int j = 0;
            while (j < 4) {
                if ((num & 128) != 0) {
                    j = j + 1;
                    num = num << 1;
                }
                else {
                    break;
                }
            }
            if ((j == 1) || ((num & 128) != 0)) {
                return false;
            }

            for (int k = 1; k < j; ++k) {
                if (i + k >= n) {
                    return false;
                }
                num = data[i + k];
                if ((num & 128) == 0) {
                    return false;
                }
                num = num << 1;
                if ((num & 128) != 0) {
                    return false;
                }
            }
            i = i + j;
        }
        return true;
    }
};
