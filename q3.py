# https://www.youtube.com/watch?v=FCbOzdHKW18

#from chapgpt q1
# def length_of_longest_substring(s: str) -> int:
#     last_seen = {}
#     left = 0
#     best = 0

#     for right, ch in enumerate(s):
#         if ch in last_seen and last_seen[ch] >= left:
#             print("last_seen %s"%(last_seen))
#             left = last_seen[ch] + 1

#         last_seen[ch] = right
#         best = max(best, right - left + 1)

#     return best
# s="abcabcbb"
# print("length is%d"%(length_of_longest_substring(s)))



#from you tube

def length_of_longest_substring(s: str) -> int:
    sett = set()
    l = 0
    longest = 0
    n=len(s)

    for r in range(n):
        while s[r] in sett:
            print("s before %s, r %d, l %d"%(s,r,l))
            sett.remove(s[l])
            l+=1
            print("s after %s, r %d, l %d"%(s,r,l))

        print("after 2,r %d, l %d"%(r,l))
        w=r-l+1
        longest=max(longest,w)
        sett.add(s[r])
    return longest
    

    return best
s="abcabcbb"
print("length is%d"%(length_of_longest_substring(s)))

#substring version


def longest_substring(s: str) -> str:
    last_seen = {}
    left = 0
    best_start = 0
    best_len = 0

    for right, ch in enumerate(s):
        if ch in last_seen and last_seen[ch] >= left:
            left = last_seen[ch] + 1

        last_seen[ch] = right

        window_len = right - left + 1
        if window_len > best_len:
            best_len = window_len
            best_start = left

    return s[best_start:best_start + best_len]

s="abcabcbb"

print("substring is %s"%(longest_substring(s)))



#longest substring

def length_of_longest_substring(s: str) -> str:
    sett = set()
    l = 0
    longest = 0
    n=len(s)

    best_len=0
    best_start=0

    for r in range(n):
        while s[r] in sett:
            print("s before %s, r %d, l %d"%(s,r,l))
            sett.remove(s[l])
            l+=1
            print("s after %s, r %d, l %d"%(s,r,l))

        print("after 2,r %d, l %d"%(r,l))

        sett.add(s[r])
        w=r-l+1

        if w>best_len:
            best_len=w
            best_start=l
        
    return s[best_start:best_start+best_len]
s="abcabcbb"

print("substring is %s"%(length_of_longest_substring(s)))



