def SearchIndex(nums, target):
    if target in nums:
        return nums.index(target)
    else:
        for n in nums:
            if target < n:
                return nums.index(n)
            
    return len(nums)
        

array = [1, 3, 5, 6]

print(SearchIndex(array, 7))
