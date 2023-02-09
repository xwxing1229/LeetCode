// https://leetcode.cn/problems/design-authentication-manager/

class AuthenticationManager {
public:
    AuthenticationManager(int timeToLive) {
        time_to_live_ = timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        tokens_[tokenId] = currentTime + time_to_live_;
    }
    
    void renew(string tokenId, int currentTime) {
        if (tokens_[tokenId] > currentTime) {
            tokens_[tokenId] = currentTime + time_to_live_;
        }
    }
    
    int countUnexpiredTokens(int currentTime) {
        int res = 0;
        for (auto it = tokens_.begin(); it != tokens_.end(); ++it) {
            if (it->second > currentTime) {
                res += 1;
            }
        }
        return res;
    }

private:
    unordered_map<string, int> tokens_;
    int time_to_live_;
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */