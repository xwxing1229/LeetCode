# https://leetcode.cn/problems/frequency-tracker/

class FrequencyTracker:

    def __init__(self):
        self.num_freq = [0 for _ in range(int(1e5)+1)]
        self.freq_num = defaultdict(set)

    def add(self, number: int) -> None:
        freq = self.num_freq[number]
        if number in self.freq_num[freq]:
            self.freq_num[freq].remove(number)

        self.num_freq[number] += 1
        freq = self.num_freq[number]
        self.freq_num[freq].add(number)

    def deleteOne(self, number: int) -> None:
        freq = self.num_freq[number]
        if number in self.freq_num[freq]:
            self.freq_num[freq].remove(number)

        self.num_freq[number] = max(0, self.num_freq[number]-1)
        freq = self.num_freq[number]
        self.freq_num[freq].add(number)

    def hasFrequency(self, frequency: int) -> bool:
        return len(self.freq_num[frequency]) > 0


# Your FrequencyTracker object will be instantiated and called as such:
# obj = FrequencyTracker()
# obj.add(number)
# obj.deleteOne(number)
# param_3 = obj.hasFrequency(frequency)
