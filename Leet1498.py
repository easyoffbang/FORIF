class Solution:
    def numSubseq(self, nums: List[int], target: int) -> int:
        nums.sort()
        print(nums)

        left = 0
        right = len(nums) - 1

        res = 0

        while (left < right):

            min_v = nums[left]
            max_v = nums[right]

            sum = min_v + max_v

            if sum <= target:
                count = right - left
                res = res + 2 ** count
                left += 1
            else:
                right -= 1

        if nums[left] * 2 <= target:
            res += 1

        return res % (10 ** 9 + 7)

