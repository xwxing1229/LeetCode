# https://leetcode.cn/problems/alert-using-same-key-card-three-or-more-times-in-a-one-hour-period/

class Solution:
    def alertNames(self, keyName, keyTime):
        """
        Inputs:
            keyName, keyTime: list[str]
        Outputs:
            res: list[str]
        """
        table = defaultdict(list)
        for i in range(len(keyName)):
            hour, minute = int(keyTime[i][:2]), int(keyTime[i][3:])
            table[keyName[i]].append(hour * 60 + minute)

        res = []
        for name, times in table.items():
            times.sort()
            for i in range(len(times)-2):
                if times[i+2] - times[i] <= 60:
                    res.append(name)
                    break

        res.sort()
        return res