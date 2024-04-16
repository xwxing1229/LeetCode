// https://leetcode.cn/problems/design-hashset

class MyHashSet {
public:
    MyHashSet() {
        size_ = 1000;
        data_.resize(size_);
    }
    
    void add(int key) {
        if (contains(key)) {
            return;
        }
        int idx = hash(key);
        data_[idx].push_back(key);
    }
    
    void remove(int key) {
        int idx = hash(key);
        for (auto it = data_[idx].begin(); it != data_[idx].end(); ++it) {
            if (*it == key) {
                data_[idx].erase(it);
                return;
            }
        }
    }
    
    bool contains(int key) {
        int idx = hash(key);
        for (int x: data_[idx]) {
            if (x == key) {
                return true;
            }
        }
        return false;
    }

    int hash(int key) {
        return key % size_;
    }

    int size_;
    vector<list<int>> data_;
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */