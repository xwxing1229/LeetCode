// https://leetcode.cn/problems/count-good-triplets/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int res = 0, n = arr.size();
        for (int i = 0; i < n; ++i) {
            int num_i = arr[i];
            for (int j = i+1; j < n; ++j) {
                int num_j = arr[j];
                if (num_i - num_j > a || num_j - num_i > a) continue;
                for (int k = j+1; k < n; ++k) {
                    int num_k = arr[k];
                    if (num_j - num_k > b || num_k - num_j > b
                        || num_i - num_k > c || num_k - num_i > c) continue;
                    res += 1;
                }
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {3,0,1,1,9,7};
    int a = 7, b = 2, c = 3;
    cout << sol.countGoodTriplets(arr, a, b, c) << '\n';
    return 0;
}