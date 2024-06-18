# https://leetcode.cn/problems/apply-discount-to-prices/

class Solution:
    def discountPrices(self, sentence: str, discount: int) -> str:
        k = 1 - discount / 100
        words = sentence.split(" ")
        for i, w in enumerate(words):
            if w[0] == "$" and w[1:].isdigit():
                value = "{:0.2f}".format(float(w[1:]) * k)
                words[i] = "$" + value
        return " ".join(words)