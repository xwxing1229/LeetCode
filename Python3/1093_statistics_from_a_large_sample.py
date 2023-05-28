# https://leetcode.cn/problems/statistics-from-a-large-sample/

class Solution:
    def sampleStats(self, count):
        """
        Inputs:
            count: list[int]
        Outputs:
            res: list[float]
        """
        res = [-1.0 for _ in range(5)]
        cnt_all, cnt_max = 0, 0
        s = 0.0
        for num, cnt in enumerate(count):
            if cnt == 0:
                continue
            if res[0] < 0:
                res[0] = num
            res[1] = num
            if cnt > cnt_max:
                res[4] = num
                cnt_max = cnt
            cnt_all += cnt
            s += num*cnt
        res[2] = s / cnt_all

        idx, half = -1, cnt_all//2
        for num, cnt in enumerate(count):
            if cnt == 0:
                continue
            idx += cnt
            if idx >= half:
                if cnt_all % 2 == 1:
                    res[3] = num
                else:
                    if idx - cnt + 1 == half:
                        res[3] = (pre + num) / 2.0
                    else:
                        res[3] = num
                break
            pre = num
        return res