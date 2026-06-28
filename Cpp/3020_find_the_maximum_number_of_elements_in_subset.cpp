// https://leetcode.cn/problems/find-the-maximum-number-of-elements-in-subset/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> cnt;
        for (const int x: nums) {
            cnt[x] += 1;
        }

        // If cnt[1] is odd, res = cnt[1].
        // Otherwise, res = cnt[1] - 1;
        int res = (cnt[1] - 1) | 1;
        cnt.erase(1);

        for (const auto &[num, _]: cnt) {
            int tmp = 0;
            long long x = num;
            while (cnt.count(x) && cnt[x] >= 2) {
                tmp += 2;
                x *= x;
            }
            res = max(res, tmp + (cnt.count(x) ? 1 : -1));
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {5,4,1,2,2};
    cout << sol.maximumLength(nums) << '\n';
    return 0;
}