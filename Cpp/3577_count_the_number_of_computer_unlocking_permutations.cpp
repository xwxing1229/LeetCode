// https://leetcode.cn/problems/count-the-number-of-computer-unlocking-permutations/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        long res = 1;
        int mod = 1e9+7;
        int comp_min = complexity[0];
        for (int i = 1; i < complexity.size(); ++i) {
            if (complexity[i] <= comp_min) return 0;
            res = res * i % mod;
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> complexity = {1,2,3};
    cout << sol.countPermutations(complexity) << '\n';
    return 0;
}