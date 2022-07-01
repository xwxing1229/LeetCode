// https://leetcode.cn/problems/compare-version-numbers/

class Solution {
public:
    int compareVersion(string version1, string version2) {
        unsigned i1 = 0, num1 = 0, n1 = version1.size();
        unsigned i2 = 0, num2 = 0, n2 = version2.size();
        while ((i1 < n1) || (i2 < n2)) {
            while ((i1 < n1) && (version1[i1] != '.')) {
                num1 = num1 * 10 + version1[i1] - '0';
                i1 = i1 + 1;
            }
            while ((i2 < n2) && (version2[i2] != '.')) {
                num2 = num2 * 10 + version2[i2] - '0';
                i2 = i2 + 1;
            }

            if (num1 > num2) {
                return 1;
            }
            else if (num1 < num2) {
                return -1;
            }

            i1 = i1 + 1;
            num1 = 0;
            i2 = i2 + 1;
            num2 = 0;
        }
        return 0;
    }
};
