# https://leetcode.cn/problems/subdomain-visit-count/

class Solution:
    def subdomainVisits(self, cpdomains):
        """
        Inputs:
            cpdomains: list[str]
        Outputs:
            res: list[int]
        """

        cnt = {}
        for line in cpdomains:
            record = line.split(" ")
            num = int(record[0])
            n = len(record[1])
            for i in range(n-1, -1, -1):
                if record[1][i] == ".":
                    web = record[1][i+1: n]
                    cnt[web] = cnt.get(web, 0) + num
            cnt[record[1]] = cnt.get(record[1], 0) + num

        res = []
        for k, v in cnt.items():
            tmp = str(v) + " " + k
            res.append(tmp)
        return res