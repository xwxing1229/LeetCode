// https://leetcode.cn/problems/design-a-text-editor/

#include <vector>
#include <string>

using namespace std;

class TextEditor {
public:
    TextEditor() {
        left_ = "";
        right_ = "";
    }
    
    void addText(string text) {
        left_ += text;
    }
    
    int deleteText(int k) {
        int n = left_.size();
        int res = min(k, n);
        left_.resize(n - res);
        return res;
    }
    
    string cursorLeft(int k) {
        while (k && left_.size()) {
            right_ += left_.back();
            left_.pop_back();
            k -= 1;
        }
        int start = max((int)left_.size()-10, 0);
        return left_.substr(start);
    }
    
    string cursorRight(int k) {
        while (k && right_.size()) {
            left_ += right_.back();
            right_.pop_back();
            k -= 1;
        }
        int start = max((int)left_.size()-10, 0);
        return left_.substr(start);
    }

    string left_, right_;
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */