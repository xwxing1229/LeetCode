# https://leetcode.cn/problems/kth-largest-element-in-an-array/

class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        """
        Inputs:
            nums: list[int]
            k: int
        Outputs:
            res: int
        """
        
        def quickSort(left, right):
            if left >= right:
                return

            pivotIdx = partition(left, right)

            if pivotIdx == len(nums) - k:
                return
            elif pivotIdx < len(nums) - k:
                quickSort(pivotIdx+1, right)
            else:
                quickSort(left, pivotIdx-1)

        def partition(left, right):
            pivotIdx = randPivotIdx(left, right)
            pivot = nums[pivotIdx]
            swap(left, pivotIdx)
            i = left + 1
            j = right
            while i <= j:
                while (i <= right) and (nums[i] < pivot):
                    i = i + 1
                while (j >= left) and  (nums[j] > pivot):
                    j = j - 1
                if i < j:
                    swap(i, j)
                    i = i + 1
                    j = j - 1
                elif i == j:
                    break
            swap(left, j)
            return j

        def randPivotIdx(left, right):
            pivotIdx = random.randint(left, right)
            return pivotIdx

        def swap(i, j):
            tmp = nums[i]
            nums[i] = nums[j]
            nums[j] = tmp

        n = len(nums)
        quickSort(0, n-1)
        return nums[n-k]
