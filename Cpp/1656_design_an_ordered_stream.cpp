// https://leetcode.cn/problems/design-an-ordered-stream/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class OrderedStream {
public:
    OrderedStream(int n) {
        n_ = n;
        cur_ = 1;
        stream_ = vector<string>(n+1, "");
    }
    
    vector<string> insert(int idKey, string value) {
        stream_[idKey] = value;

        vector<string> res;
        while (cur_ <= n_ && stream_[cur_].size()) {
            res.push_back(stream_[cur_]);
            cur_ += 1;
        }
        return res;
    }

    int n_, cur_;
    vector<string> stream_;
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */