// https://leetcode.cn/problems/jump-game-iv/

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>> position;
        for (int i = 0; i < n; ++i) {
            position[arr[i]].push_back(i);
        }

        int res = 0;
        queue<int> q;
        q.push(0);
        vector<bool> visited(n, false);
        visited[0] = true;
        while (true) {
            int n_q = q.size();
            for (int k = 0; k < n_q; ++k) {
                int i = q.front();
                q.pop();
                if (i == n-1) return res;

                if (!visited[i+1]) {
                    q.push(i+1);
                    visited[i+1] = true;
                }
                if (i > 0 && !visited[i-1]) {
                    q.push(i-1);
                    visited[i-1] = true;
                }
                for (int j: position[arr[i]]) {
                    if (!visited[j]) {
                        q.push(j);
                        visited[j] = true;
                    }
                }
                position[arr[i]].clear();
            }
            res += 1;
        }
    }
};

int main() {
    Solution sol;
    vector<int> arr = {100,-23,-23,404,100,23,23,23,3,404};
    cout << sol.minJumps(arr) << '\n';
    return 0;
}