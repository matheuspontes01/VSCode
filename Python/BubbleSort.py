def BubbleSort(nums):
    for i in range(len(nums)):
        for j in range(1, len(nums) - i):
            if nums[j] < nums[j - 1]:
                nums[j], nums[j-1] = nums[j-1], nums[j]
                # aux = nums[j]
                # nums[j] = nums[j-1]
                # nums[j-1] = aux

    return nums


numeros = [5, 2, 8, 4]

BubbleSort(numeros)

print(numeros)