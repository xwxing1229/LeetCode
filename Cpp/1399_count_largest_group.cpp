// https://leetcode.cn/problems/count-largest-group/

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int countLargestGroup(int n) {
        auto digitsum = [](int num) {
            int res = 0;
            while (num) {
                res += num % 10;
                num /= 10;
            }
            return res;
        };

        unordered_map<int, int> cnt;
        int cnt_max = 0, res = 0;
        for (int num = 1; num <= n; ++num) {
            int value = digitsum(num);
            cnt[value] += 1;
            if (cnt[value] > cnt_max) {
                cnt_max = cnt[value];
                res = 1;
            }
            else if (cnt[value] == cnt_max) {
                res += 1;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    int n = 13;
    cout << sol.countLargestGroup(n) << '\n';
    return 0;
}