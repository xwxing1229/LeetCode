// https://leetcode.cn/problems/pascals-triangle-ii/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex+1, 1);
        for (int row = 2; row <= rowIndex; ++row) {
            int last = 1;
            for (int i = 1; i < row; ++i) {
                int tmp = last + res[i];
                last = res[i];
                res[i] = tmp;
            }
        }
        return res;
    }
};

int main() {
    Solution solu;
    int rowIndex = 5;
    vector<int> res = solu.getRow(rowIndex);
    for (int i: res) {
        cout << i << ", ";
    }
    cout << '\n';
    
    return 0;
}