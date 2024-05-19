// https://leetcode.cn/problems/find-the-winner-of-an-array-game/

class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();
        int win_idx = 0, win_times = 0;
        int idx = 1;
        while (true) {
            if (arr[win_idx] > arr[idx]) {
                win_times += 1;
            }
            else {
                win_idx = idx;
                win_times = 1;
            }
            int idx_new = (idx + 1) % n;
            if (win_times == k || idx_new <= idx) {
                return arr[win_idx];
            }
            idx = idx_new;
        }
        return -1;
    }
};

