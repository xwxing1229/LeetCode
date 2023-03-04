# https://leetcode.cn/problems/validate-ip-address/

class Solution:
    def validIPAddress(self, queryIP):
        """
        Inputs:
            queryIP: str
        Outputs:
            res: str
        """
        if len(queryIP) < 5:
            return "Neither"
            
        for i in range(5):
            if queryIP[i] == ".":
                return self.check_ipv4(queryIP.split("."))
            elif queryIP[i] == ":":
                return self.check_ipv6(queryIP.split(":"))
        return "Neither"
        
    def check_ipv4(self, address):
        if len(address) != 4:
            return "Neither"
        for ad in address:
            if len(ad) < 1 or len(ad) > 4 or not ad.isdigit():
                return "Neither"
            val = int(ad)
            if val > 255 or str(val) != ad:
                return "Neither"
        return "IPv4"

    def check_ipv6(self, address):
        if len(address) != 8:
            return "Neither"
        check = {"0", "1", "2", "3", "4",
                 "5", "6", "7", "8", "9",
                 "a", "b", "c", "d", "e", "f",
                 "A", "B", "C", "D", "E", "F"}
        for ad in address:
            if len(ad) < 1 or len(ad) > 4:
                return "Neither"
            for ch in ad:
                if ch not in check:
                    return "Neither"
        return "IPv6"