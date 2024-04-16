// https://leetcode.cn/problems/design-hashmap/

class MyHashMap {
public:
    MyHashMap() {
        size_ = 1000;
        data_.resize(size_);
    }
    
    void put(int key, int value) {
        int idx = hash(key);
        for (auto it = data_[idx].begin(); it != data_[idx].end(); ++it) {
            if (it->first == key) {
                it->second = value;
                return;
            }
        }
        data_[idx].push_back(make_pair(key, value));
    }
    
    int get(int key) {
        int idx = hash(key);
        for (auto it = data_[idx].begin(); it != data_[idx].end(); ++it) {
            if (it->first == key) {
                return it->second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        int idx = hash(key);
        for (auto it = data_[idx].begin(); it != data_[idx].end(); ++it) {
            if (it->first == key) {
                data_[idx].erase(it);
                return;
            }
        }
    }

    int hash(int key) {
        return key % size_;
    }

    vector<list<pair<int,int>>> data_;
    int size_;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */