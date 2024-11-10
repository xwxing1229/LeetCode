// https://leetcode.cn/problems/implement-magic-dictionary/

class MagicDictionary {
public:
    MagicDictionary() {

    }
    
    void buildDict(vector<string> dictionary) {
        for (auto &s: dictionary) {
            dictionary_.insert(s);
        }
    }
    
    bool search(string searchWord) {
        for (auto i = dictionary_.begin(); i != dictionary_.end(); ++i) {
            auto s = *i;
            if (s.size() != searchWord.size()) continue;

            int diff = 0;
            for (int k = 0; k < s.size(); ++k) {
                if (s[k] != searchWord[k]) {
                    diff += 1;
                    if (diff >= 2) break;
                }
            }
            if (diff == 1) return true;
        }
        return false;
    }

    unordered_set<string> dictionary_;
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */
