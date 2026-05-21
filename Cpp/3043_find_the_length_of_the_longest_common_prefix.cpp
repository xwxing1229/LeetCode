// https://leetcode.cn/problems/find-the-length-of-the-longest-common-prefix/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> s;
        for (int num: arr1) {
            while (num > 0) {
                s.insert(num);
                num /= 10;
            }
        }
        int res = 0;
        for (int num: arr2) {
            while (num > 0 && !s.count(num)) {
                num /= 10;
            }
            res = max(res, num);
        }
        return res > 0 ? to_string(res).size() : 0;
    }
};

int main() {
    Solution sol;
    vector<int> arr1 = {1, 10, 100};
    vector<int> arr2 = {1000};
    cout << sol.longestCommonPrefix(arr1, arr2) << '\n';
    return 0;
}