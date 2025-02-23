// https://leetcode.cn/problems/range-frequency-queries/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class RangeFreqQuery {
public:
    RangeFreqQuery(vector<int>& arr) {
        for (int i = 0; i < arr.size(); ++i) {
            idxs_[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int value) {
        vector<int> &idxs = idxs_[value];
        int n = idxs.size();
        int i = 0, j = n-1, idx1 = n;
        while (i <= j) {
            int mid = i + (j - i) / 2;
            if (idxs[mid] < left) {
                i = mid + 1;
            }
            else {
                j = mid - 1;
                idx1 = mid;
            }
        }

        i = 0;
        j = n - 1;
        int idx2 = -1;
        while (i <= j) {
            int mid = i + (j - i) / 2;
            if (idxs[mid] > right) {
                j = mid - 1;
            }
            else {
                i = mid + 1;
                idx2 = mid;
            }
        }
        int res = idx2 - idx1 + 1;
        return res > 0 ? res : 0;
    }

    unordered_map<int, vector<int>> idxs_;
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */


int main() {
    vector<int> arr = {12, 33, 4, 56, 22, 2, 34, 33, 22, 12, 34, 56};
    RangeFreqQuery obj(arr);
    cout << obj.query(1, 2, 4) << '\n';
    cout << obj.query(0, 11, 33) << '\n';
    return 0;
}