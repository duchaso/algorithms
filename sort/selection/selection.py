import random
import time
def selection_sort(array):
    size_of_array = len(array)
    for i in range(size_of_array):
        min_index = i
        for j in range(i+1, size_of_array):
            if array[j] < array[min_index]:
                min_index = j
        array[i], array[min_index] = array[min_index], array[i]
    return array


start_time = time.time()
array = random.sample(range(0, 1000), 2**9)
array = selection_sort(array)
print(array)
print("Time execution:", time.time()-start_time)
