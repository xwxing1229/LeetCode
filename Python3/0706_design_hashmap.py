# https://leetcode.cn/problems/design-hashmap/

class MyHashMap:

    def __init__(self):
        self.size = 1000
        self.data = [[] for _ in range(self.size)]

    def put(self, key: int, value: int) -> None:
        idx = self.hash(key)
        for i in range(len(self.data[idx])):
            if self.data[idx][i][0] == key:
                self.data[idx][i][1] = value
                return
        self.data[idx].append([key, value])

    def get(self, key: int) -> int:
        idx = self.hash(key)
        for i in range(len(self.data[idx])):
            if self.data[idx][i][0] == key:
                return self.data[idx][i][1]
        return -1

    def remove(self, key: int) -> None:
        idx = self.hash(key)
        for i in range(len(self.data[idx])):
            if self.data[idx][i][0] == key:
                value = self.data[idx][i][1]
                self.data[idx].remove([key, value])
                return

    def hash(self, key):
        return key % self.size



# Your MyHashMap object will be instantiated and called as such:
# obj = MyHashMap()
# obj.put(key,value)
# param_2 = obj.get(key)
# obj.remove(key)