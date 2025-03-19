def BinarySearch(nums, target):
    l, r = 0, len(nums)-1

    while l <= r:
        m = (l+r)//2

        if nums[m] > target:
            r = m - 1
        elif nums[m] < target:
            l = m + 1
        else:
            return m
        
    return -1

array = [2, 4, 6, 10, 15, 21, 25, 27]

print(BinarySearch(array, 25))
    

    