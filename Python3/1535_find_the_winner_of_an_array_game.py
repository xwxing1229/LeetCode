# https://leetcode.cn/problems/find-the-winner-of-an-array-game/

class Solution:
    def getWinner(self, arr, k):
        """
        Inputs:
            arr: list[int]
            k: int
        Outputs:
            res: int
        """
        n = len(arr)
        win_idx, win_times = 0, 0
        idx = 1
        while 1:
            if arr[win_idx] > arr[idx]:
                win_times += 1
            else:
                win_idx = idx
                win_times = 1
            idx_new = (idx + 1) % n
            if win_times == k or idx_new <= idx:
                return arr[win_idx]
            idx = idx_new
        return -1