// https://leetcode.cn/problems/three-consecutive-odds/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        for (int i = 1; i < arr.size()-1; ++i) {
            if (arr[i-1] % 2 && arr[i] % 2 && arr[i+1] % 2) return true;
        }
        return false;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1,2,34,3,4,5,7,23,12};
    cout << sol.threeConsecutiveOdds(arr) << '\n';
    return 0;
}