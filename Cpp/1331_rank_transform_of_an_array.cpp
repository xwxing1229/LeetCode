// https://leetcode.cn/problems/rank-transform-of-an-array/

#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> arr_sort(arr);
        sort(arr_sort.begin(), arr_sort.end());
        
        int n = arr.size();
        unordered_map<int, int> rank;
        for (int i = 0; i < n; ++i) {
            if (i == 0 || arr_sort[i] != arr_sort[i-1]) {
                rank[arr_sort[i]] = rank.size() + 1;
            }
        }

        vector<int> res(n);
        for (int i = 0; i < n; ++i) {
            res[i] = rank[arr[i]];
        }
        return res;
    }
};