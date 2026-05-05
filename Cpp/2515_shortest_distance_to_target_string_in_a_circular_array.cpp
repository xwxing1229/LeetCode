// https://leetcode.cn/problems/shortest-distance-to-target-string-in-a-circular-array/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size(), res = -1;
        for (int i = startIndex; i < startIndex+n; ++i) {
            if (words[i % n] == target) {
                res = i - startIndex;
                break;
            }
        }
        for (int i = startIndex; i > startIndex-n; --i) {
            if (words[(i+n) % n] == target) {
                if (res < 0 || res > startIndex - i) {
                    res = startIndex - i;
                }
                break;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<string> words = {"a","b","leetcode"};
    string target = "leetcode";
    int startIndex = 0;
    cout << sol.closestTarget(words, target, startIndex) << '\n';
    return 0;
}