# https://leetcode.cn/problems/binary-watch/

class Solution:
    def readBinaryWatch(self, turnedOn: int) -> List[str]:
        self.hourTable = {i: [] for i in range(5)}
        self.minTable = {i: [] for i in range(7)}
        self.hours = [1, 2, 4, 8]
        self.mins = [1, 2, 4, 8, 16, 32]
        for onHour in range(max(turnedOn-6,0), min(turnedOn,4)+1):
            self.dfsHour(onHour, 0, 0, 0)
            self.dfsMin(turnedOn - onHour, 0, 0, 0)
        
        res = []
        for onHour in self.hourTable:
            for h in self.hourTable[onHour]:
                for m in self.minTable[turnedOn-onHour]:
                    res.append(h+":"+m)
        return res
    
    def dfsHour(self, turnedOnHour, tmpOn, tmpTime, idx):
        if turnedOnHour == tmpOn and tmpTime < 12:
            self.hourTable[turnedOnHour].append(str(tmpTime))
            return

        for i in range(idx, 4):
            self.dfsHour(turnedOnHour, tmpOn+1, tmpTime+self.hours[i], i+1)
        
    def dfsMin(self, turnedOnMin, tmpOn, tmpTime, idx):
        if turnedOnMin == tmpOn and tmpTime < 60:
            if tmpTime < 10:
                self.minTable[turnedOnMin].append("0"+str(tmpTime))
            else:
                self.minTable[turnedOnMin].append(str(tmpTime))
            return
        
        for i in range(idx, 6):
            self.dfsMin(turnedOnMin, tmpOn+1, tmpTime+self.mins[i], i+1)