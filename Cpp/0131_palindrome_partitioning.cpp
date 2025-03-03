// https://leetcode.cn/problems/palindrome-partitioning/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string> cur;
        dfs(cur, s, 0);
        return res_;
    }

    void dfs(vector<string> &cur, string &s, int idx) {
        int n = s.size();
        if (idx == n) {
            res_.push_back(cur);
            return;
        }
        for (int i = idx; i < n; ++i) {
            int left = idx, right = i;
            bool valid = true;
            while (left < right) {
                if (s[left] == s[right]) {
                    left += 1;
                    right -= 1;
                }
                else {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                cur.push_back(s.substr(idx, i-idx+1));
                dfs(cur, s, i+1);
                cur.pop_back();
            }
        }
    }

    vector<vector<string>> res_;
};

int main() {
    Solution solu;
    string s = "aba";
    vector<vector<string>> res = solu.partition(s);
    for (vector<string> row: res) {
        for (string st: row) {
            cout << st << ", ";
        }
        cout << '\n';
    }
    
    return 0;
}