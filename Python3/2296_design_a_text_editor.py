# https://leetcode.cn/problems/design-a-text-editor/

class TextEditor:
    def __init__(self) -> None:
        self.left = []
        self.right = []

    def addText(self, text: str) -> None:
        self.left.extend(text)
    
    def deleteText(self, k: int) -> int:
        pre = len(self.left)
        del self.left[-k:]
        return pre - len(self.left)
    
    def cursorLeft(self, k: int) -> str:
        while k and self.left:
            self.right.append(self.left.pop())
            k -= 1
        return "".join(self.left[-10:])
    
    def cursorRight(self, k: int) -> str:
        while k and self.right:
            self.left.append(self.right.pop())
            k -= 1
        return "".join(self.left[-10:])
    

# Your TextEditor object will be instantiated and called as such:
# obj = TextEditor()
# obj.addText(text)
# param_2 = obj.deleteText(k)
# param_3 = obj.cursorLeft(k)
# param_4 = obj.cursorRight(k)