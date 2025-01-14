# https://leetcode.cn/problems/largest-3-same-digit-number-in-string/

class Solution:
    def largestGoodInteger(self, num: str) -> str:
        res, res_num = "", 0
        cnt = 1
        for i in range(1, len(num)):
            if num[i] != num[i-1]:
                cnt = 1
                continue

            cnt += 1
            if cnt == 3 and int(num[i-2: i+1]) >= res_num:
                res = num[i-2: i+1]
                res_num = int(res)
        return res