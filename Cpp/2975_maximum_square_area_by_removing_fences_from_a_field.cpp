// https://leetcode.cn/problems/maximum-square-area-by-removing-fences-from-a-field/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        int mod = 1e9 + 7;
        
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);
        int hFencesSize = hFences.size(), vFencesSize = vFences.size();

        unordered_set<int> hSides;
        for (int i = 0; i < hFencesSize; ++i) {
            const int &hfi = hFences[i];
            for (int j = i+1; j < hFencesSize; ++j) {
                hSides.insert(abs(hfi - hFences[j]));
            }
        }

        int side = 0;
        for (int i = 0; i < vFencesSize; ++i) {
            const int &vfi = vFences[i];
            for (int j = i+1; j < vFencesSize; ++j) {
                int tmp = abs(vfi - vFences[j]);
                if (hSides.count(tmp) && side < tmp) {
                    side = tmp;
                }
            }
        }
        return side ? (long)side * side % mod : -1;
    }
};

int main() {
    Solution sol;
    int m = 4, n = 3;
    vector<int> hFences = {2,3}, vFences = {2};
    cout << sol.maximizeSquareArea(m, n, hFences, vFences) << '\n';
    return 0;
}