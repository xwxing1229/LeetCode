// https://leetcode.cn/problems/minimum-number-of-pushes-to-type-word-i/

#include <string>

using namespace std;

class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        int k = n / 8, rem = n % 8;
        return (4 * k + rem) * (k + 1);
    }
};