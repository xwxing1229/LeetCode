// https://leetcode.cn/problems/apple-redistribution-into-boxes/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int res = 0;
        int remain = 0;
        for (const int &cnt: apple) {
            remain += cnt;
        }
        sort(capacity.begin(), capacity.end(), greater<int>());
        for (const int &cap: capacity) {
            remain -= cap;
            res += 1;
            if (remain <= 0) {
                break;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> apple = {1,3,2};
    vector<int> capacity = {4,3,1,5,2};
    cout << sol.minimumBoxes(apple, capacity) << '\n';
    return 0;
}