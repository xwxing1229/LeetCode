// https://leetcode.cn/problems/walking-robot-simulation-ii/

#include <vector>
#include <string>

using namespace std;

class Robot {
public:
    Robot(int width, int height) {
        pos_lim_ = {width-1, height-1};
        perimeter_ = 2 * width + 2 * height - 4;
    }
    
    void step(int num) {
        if (num > perimeter_) {
            num %= perimeter_;
            if (num == 0) {
                num = perimeter_;
            }
        }
        while (num > 0) {
            int move;
            if (dir_[0] == 1) move = pos_lim_[0] - pos_[0];
            else if (dir_[0] == -1) move = pos_[0];
            else if (dir_[1] == 1) move = pos_lim_[1] - pos_[1];
            else move = pos_[1];
            move = min(move, num);
            pos_[0] += move * dir_[0];
            pos_[1] += move * dir_[1];
            if (move < num) {
                int tmp = dir_[0];
                dir_[0] = -dir_[1];
                dir_[1] = tmp;
                dir_id_ = (dir_id_ + 1) % 4;
            }
            num -= move;
        }
    }
    
    vector<int> getPos() {
        return pos_;
    }
    
    string getDir() {
        return dir_names_[dir_id_];
    }

private:
    vector<int> pos_ {0, 0};
    vector<int> pos_lim_;
    int perimeter_ {0};
    vector<int> dir_ {1, 0};
    vector<string> dir_names_ {"East", "North", "West", "South"};
    int dir_id_ {0};
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */