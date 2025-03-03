// https://leetcode.cn/problems/design-memory-allocator/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Allocator {
public:
    Allocator(int n) {
        n_ = n;
        memory_ = vector<int>(n+1, 0);
        memory_[n] = 1;
    }
    
    int allocate(int size, int mID) {
        int res = 0, zeros = 0;
        for (int i = 0; i <= n_; ++i) {
            if (memory_[i] == 0) {
                zeros += 1;
            }
            else if (zeros >= size) {
                for (int k = res; k < res+size; ++k) {
                    memory_[k] = 1;
                }
                location_[mID].push_back(make_pair(res, size));
                return res;
            }
            else {
                res = i + 1;
                zeros = 0;
            }
        }
        return -1;
    }
    
    int freeMemory(int mID) {
        int res = 0;
        for (const auto &loc: location_[mID]) {
            int start = loc.first, size = loc.second;
            res += size;
            for (int i = start; i < start+size; ++i) {
                memory_[i] = 0;
            }
        }
        location_[mID].clear();
        return res;
    }

    int n_;
    vector<int> memory_;
    unordered_map<int, vector<pair<int,int>>> location_;
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->freeMemory(mID);
 */