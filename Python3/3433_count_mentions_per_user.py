# https://leetcode.cn/problems/count-mentions-per-user/

class Solution:
    def countMentions(self, numberOfUsers: int, events: list[list[str]]) -> list[int]:
        events.sort(key=lambda x: (int(x[1]), x[0][2]))
        res = [0 for _ in range(numberOfUsers)]
        online = [0 for _ in range(numberOfUsers)]
        mention_all = 0
        for e in events:
            if e[0][0] == "M":
                if e[2] == "ALL":
                    mention_all += 1
                elif e[2] == "HERE":
                    t = int(e[1])
                    for i in range(numberOfUsers):
                        if online[i] <= t:
                            res[i] += 1
                else:
                    for user in e[2].split(" "):
                        res[int(user[2:])] += 1
            else:
                online[int(e[2])] = int(e[1]) + 60
        for i in range(numberOfUsers):
            res[i] += mention_all
        return res