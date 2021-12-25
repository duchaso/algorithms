import random
import time

def merge(array1, array2):
    res = []
    n = len(array1)+len(array2)
    i = 0
    j = 0
    for k in range(n):
        if(i == len(array1)):
            for val in range(j, len(array2)):
                res.append(array2[val])
            break
        if(j == len(array2)):
            for val in range(i, len(array1)):
                res.append(array1[val])
            break

        if array1[i] < array2[j]:
            res.append(array1[i])
            i += 1
        else:
            res.append(array2[j])
            j += 1
    return res

def merge_sort(array):
    array_length = len(array)
    #print(array)
    if array_length==1 or array_length==0:
        return array
    center = int(array_length/2)
    subarray1 = merge_sort(array[0:center])
    #print(subarray1)
    subarray2 = merge_sort(array[center:len(array)])
    #print(subarray2)
    #print(subarray1)
    return merge(subarray1, subarray2)

start_time = time.time()
array = random.sample(range(0, 1000), 2**9)
print(array)
array = merge_sort(array)
print(array)
print("Time exectution:", time.time()-start_time)