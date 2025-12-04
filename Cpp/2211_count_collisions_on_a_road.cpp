// https://leetcode.cn/problems/count-collisions-on-a-road/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size();
        int left = 0, right = n-1;
        while (left < n && directions[left] == 'L') left += 1;
        while (right >= 0 && directions[right] == 'R') right -= 1;
        if (left >= n || right < 0) return 0;
        int cnt_S = 0;
        for (int i = left; i <= right; ++i) cnt_S += directions[i] == 'S';
        return right - left + 1 - cnt_S;
    }
};

int main() {
    Solution sol;
    string directions = "RLRSLL";
    cout << sol.countCollisions(directions) << '\n';
    return 0;
}