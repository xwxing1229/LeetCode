# https://leetcode.cn/problems/implement-magic-dictionary/

class MagicDictionary:

    def __init__(self):
        self.dictionary = set()

    def buildDict(self, dictionary: List[str]) -> None:
        for s in dictionary:
            self.dictionary.add(s)

    def search(self, searchWord: str) -> bool:
        for s in self.dictionary:
            if len(s) != len(searchWord):
                continue

            diff = 0
            for i, ch in enumerate(s):
                if ch != searchWord[i]:
                    diff += 1
                    if diff >= 2:
                        break
            if diff == 1:
                return True
        return False

# Your MagicDictionary object will be instantiated and called as such:
# obj = MagicDictionary()
# obj.buildDict(dictionary)
# param_2 = obj.search(searchWord)