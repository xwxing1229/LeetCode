// https://leetcode.cn/problems/1-bit-and-2-bit-characters/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size(), i = 0;
        while (i < n-1) {
            i += bits[i] + 1;
        }
        return i == n-1;
    }
};

int main() {
    Solution sol;
    vector<int> bits = {1,0,0};
    cout << sol.isOneBitCharacter(bits) << '\n';
    return 0;
}