# Top K Frequent Elements

#https://www.youtube.com/watch?v=phNDYf1xzco&pp=ygUgdG9wIGsgZnJlcXVlbnQgZWxlbWVudHMgbGVldGNvZGU%3D



#search term:counter python functions items
# Initialize counter
# my_counter = Counter(['apple', 'banana', 'apple', 'orange', 'banana', 'apple'])

# 1. Using .items() to loop through pairs
# for item, count in my_counter.items():
#     print(f"{item}: {count}")
# Output:
# apple: 3
# banana: 2
# orange: 1

from collections import Counter
import heapq

def top_k_frequent(nums: list[int], k: int) -> list[int]:
    counts = Counter(nums)

    heap = []
    for num, freq in counts.items():
        heapq.heappush(heap, (freq, num))


        if len(heap) > k:
            heapq.heappop(heap)



    # return [num for freq, num in heap]
    #Step 3: Extract the numbers from the heap

    # return [item[1] for item in heap]
    return [item[1] for item in heap]



nums = [1,1,1,2,2,3]
#1,3->num,freq will change to 3,1
#2,2->2,2
#3,1->1,3
k = 2
print(top_k_frequent(nums,k))


