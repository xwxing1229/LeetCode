# https://leetcode.cn/problems/earliest-finish-time-for-land-and-water-rides-i/

class Solution:
    def earliestFinishTime(self, landStartTime: list[int], landDuration: list[int], waterStartTime: list[int], waterDuration: list[int]) -> int:
        def f(firstStartTime: list[int], firstDuration: list[int], secondStartTime: list[int], secondDuration: list[int]) -> int:
            finish = firstStartTime[0] + firstDuration[0]
            for i, start in enumerate(firstStartTime):
                finish = min(finish, start + firstDuration[i])
            res = max(finish, secondStartTime[0]) + secondDuration[0]
            for i, start in enumerate(secondStartTime):
                tmp = max(finish, start) + secondDuration[i]
                res = min(res, tmp)
            return res
        return min(
            f(landStartTime, landDuration, waterStartTime, waterDuration),
            f(waterStartTime, waterDuration, landStartTime, landDuration)
        )