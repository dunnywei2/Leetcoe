#https://www.youtube.com/watch?v=HCbKvBOlMVI&pp=ygUYbWVyZ2UgaW50ZXJ2YWxzIGxlZXRjb2Rl

#other solutions
# def merge_intervals(intervals: list[list[int]]) -> list[list[int]]:
#     if not intervals:
#         return []

#     intervals.sort(key=lambda x: x[0])

#     merged = [intervals[0]]

#     for start, end in intervals[1:]:
#         last = merged[-1]

#         if start <= last[1]:
#             last[1] = max(last[1], end)
#         else:
#             merged.append([start, end])

#     return merged




def merge_intervals(intervals: list[list[int]]) -> list[list[int]]:
    if not intervals:
        return []

    intervals.sort(key=lambda interval:interval[0])

    print(intervals)
    merged = []

    for interval in intervals:
        if not merged or merged[-1][1]<interval[0]:
            #merged is empty or no overlapping
            merged.append(interval)
            print("-------------------")
            print(interval)
        else:
            print("xxxxxxxxxxxxxxxxxx")

            print(interval)

            print(merged[-1])
            print(merged[-1][0])
            print(merged[-1][1])
            print(interval[1])
            print(interval[0])
            merged[-1]=[merged[-1][0],max(merged[-1][1],interval[1])]

    return merged



interval=[[2,6],[1,3],[8,10],[15,18]]
print(merge_intervals(interval))