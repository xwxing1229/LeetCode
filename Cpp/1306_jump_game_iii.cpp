// https://leetcode.cn/problems/jump-game-iii/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        queue<int> q;
        q.push(start);
        vector<bool> visited(n, false);
        visited[start] = true;

        auto PushIntoQueue = [&](int i) {
            if (i < 0 || i >= n || visited[i]) return;
            q.push(i);
            visited[i] = true;
        };

        while (!q.empty()) {
            int i = q.front();
            q.pop();
            if (arr[i] == 0) return true;
            PushIntoQueue(i + arr[i]);
            PushIntoQueue(i - arr[i]);
        }
        return false;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {4,2,3,0,3,1,2};
    int start = 5;
    cout << sol.canReach(arr, start) << '\n';
    return 0;
}