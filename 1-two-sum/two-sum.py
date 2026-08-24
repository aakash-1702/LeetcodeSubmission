class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        mp = dict()

        n = len(nums)

        for i in range(n):
            newTarget = target - nums[i]
            if newTarget in mp:
                return [mp[newTarget] , i]
            
            mp[nums[i] ] = i
        
        return [-1 , -1]


        