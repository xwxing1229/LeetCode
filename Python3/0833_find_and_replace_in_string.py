# https://leetcode.cn/problems/find-and-replace-in-string/

class Solution:
    def findReplaceString(self, s: str, indices, sources, targets):
        """
        Inputs:
            s: str
            indices: list[int]
            sources, targets: list[str]
        Outputs:
            res: str
        """
        res = []
        idxs = [j for j in range(len(indices))]
        idxs.sort(key=lambda x: indices[x])
        i, j = 0, 0
        n = len(s)
        while i < n:
            if j >= len(indices):
                res.append(s[i:])
                break
            elif i != indices[idxs[j]]:
                res.append(s[i])
                i += 1
            else:
                source = sources[idxs[j]]
                len_source = len(source)
                if i + len_source <= n and s[i:i+len_source] == source:
                    res.append(targets[idxs[j]])
                    i += len_source
                else:
                    res.append(s[i])
                    i += 1
                j += 1
        return "".join(res)