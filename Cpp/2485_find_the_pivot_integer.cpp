// https://leetcode.cn/problems/find-the-pivot-integer/

class Solution {
public:
    int pivotInteger(int n) {
        int target = (n+1) * n / 2;
        int tmp = sqrt(target);
        return (tmp*tmp == target) ? tmp : -1;
    }
};