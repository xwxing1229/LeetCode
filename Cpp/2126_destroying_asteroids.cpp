// https://leetcode.cn/problems/destroying-asteroids/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        long curr = mass;
        for (const auto &a: asteroids) {
            if (curr < a) return false;
            curr += a;
        }
        return true;
    }
};

int main() {
    Solution sol;
    int mass = 10;
    vector<int> asteroids = {3,9,19,5,21};
    cout << sol.asteroidsDestroyed(mass, asteroids) << '\n';
    return 0;
}