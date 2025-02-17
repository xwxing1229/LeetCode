// https://leetcode.cn/problems/replace-elements-with-greatest-element-on-right-side/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int max_right = -1;
        for (int i = arr.size()-1; i >= 0; --i) {
            int tmp = arr[i];
            arr[i] = max_right;
            max_right = max(max_right, tmp);
        }
        return arr;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {17,18,5,4,6,1};
    auto res = sol.replaceElements(arr);
    for (auto num: res) cout << num << ", ";
    cout << '\n';
    return 0;
}