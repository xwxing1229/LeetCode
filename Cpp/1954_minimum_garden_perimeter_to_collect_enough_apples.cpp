// https://leetcode.cn/problems/minimum-garden-perimeter-to-collect-enough-apples/

class Solution {
public:
    long long minimumPerimeter(long long neededApples) {
        long long apples = 0, k = 0;
        while (apples < neededApples) {
            k += 1;
            apples += k * k * 12;
        }
        return 8*k;
    }
};
