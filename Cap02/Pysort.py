# [numero] * n, creates a list with size n and with numero as element to each index.

import os
import array

def insertionSort(list: array.array, size:int) -> None:
    j = 0
    for i in range(size - 1):
        j = i + 1
        while((j > 0) and (list[j - 1] > list[j])):
            temp = list[j - 1]
            list[j - 1] = list[j]
            list[j] = temp
            j -= 1

SIZE = 1000

nums = array.array("i", [0] * SIZE)

with open("numbers.bin", "rb") as numFile:
    numFile.readinto(nums)

insertionSort(nums, SIZE)

for i in range(30):
    print(nums[i])
