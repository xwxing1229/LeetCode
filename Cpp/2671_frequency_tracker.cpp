// https://leetcode.cn/problems/frequency-tracker/

class FrequencyTracker {
public:
    FrequencyTracker() {
        num_freq_ = vector<int>(int(1e5)+1);
    }
    
    void add(int number) {
        int freq = num_freq_[number];
        freq_num_[freq].erase(number);

        num_freq_[number] += 1;
        freq = num_freq_[number];
        freq_num_[freq].insert(number);
    }
    
    void deleteOne(int number) {
        int freq = num_freq_[number];
        freq_num_[freq].erase(number);

        num_freq_[number] = max(0, num_freq_[number]-1);
        freq = num_freq_[number];
        freq_num_[freq].insert(number);
    }
    
    bool hasFrequency(int frequency) {
        return freq_num_[frequency].size() == 0 ? false : true;
    }

    vector<int> num_freq_;
    unordered_map<int, unordered_set<int>> freq_num_;
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */