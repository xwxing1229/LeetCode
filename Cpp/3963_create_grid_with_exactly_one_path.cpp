// https://leetcode.cn/problems/create-grid-with-exactly-one-path/

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> res(m, string(n-1, '#') + '.');
        res[0] = string(n, '.');
        return res;
    }
};