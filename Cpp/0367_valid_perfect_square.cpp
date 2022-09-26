// https://leetcode.cn/problems/count-numbers-with-unique-digits/

#include <iostream>

using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        int left = 0, right = num;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            long sq = (long)mid * mid;
            if (sq < num) {
                left = mid + 1;
            }
            else if (sq > num) {
                right = mid - 1;
            }
            else {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution solu;
    int num = 16;
    cout << solu.isPerfectSquare(num) << endl;
}