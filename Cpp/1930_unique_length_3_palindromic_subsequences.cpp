// https://leetcode.cn/problems/unique-length-3-palindromic-subsequences/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<vector<int>> position(26, vector<int>());
        for (int i = 0; i < s.size(); ++i) {
            position[s[i] - 'a'].push_back(i);
        }

        int res = 0;
        for (int i = 0; i < 26; ++i) {
            if (position[i].size() < 2) continue;
            int start = position[i][0], stop = position[i].back();
            for (int j = 0; j < 26; ++j) {
                // Check whether there exists a valid index for the middle char.
                int n = position[j].size();
                if (i == j) {
                    res += (n > 2);
                    continue;
                }

                int valid_min = n, valid_max = -1;
                
                int left = 0, right = n-1;
                while (left <= right) {
                    int mid = (left + right) / 2;
                    if (position[j][mid] >= start) {
                        right = mid - 1;
                        valid_min = mid;
                    }
                    else {
                        left = mid + 1;
                    }
                }

                left = 0;
                right = n-1;
                while (left <= right) {
                    int mid = (left + right) / 2;
                    if (position[j][mid] <= stop) {
                        left = mid + 1;
                        valid_max = mid;
                    }
                    else {
                        right = mid - 1;
                    }
                }

                res += (valid_min <= valid_max);
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    string s = "aabca";
    cout << sol.countPalindromicSubsequence(s) << '\n';
    return 0;
}