#!/usr/bin/env python
# coding=utf-8

class Solution(object):
    def twoSum(self, nums, target):
        hash_map = {}
        for index, value in enumerate(nums):
            hash_map[value] = index
        for index1,value in enumerate(nums):
            if target - value in hash_map:
                index2 = hash_map[target - value]
                if index1 != index2:
                    return [index1 + 1, index2 + 1]



if __name__ == "__main__":
    print Solution().twoSum([2,7,11,15],9)
