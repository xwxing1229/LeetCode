// https://leetcode.cn/problems/magnetic-force-between-two-balls/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int res = 1, left = 1, right = (position.back() - position[0]) / (m-1);

        auto valid = [&](int x) {
            int cnt = 0, pre = position[0] - x;
            for (int pos: position) {
                if (pos >= pre + x) {
                    cnt += 1;
                    pre = pos;
                }
            }
            return cnt >= m;
        };

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (valid(mid)) {
                res = max(res, mid);
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> position = {1,2,3,4,7};
    int m = 3;
    cout << sol.maxDistance(position, m) << '\n';
    return 0;
}