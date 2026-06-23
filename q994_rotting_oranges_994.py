from collections import deque

class Solution:
    def organeRotting(self,grid:list[list[int]])->int:
        row,col=len(grid),len(grid[0]);
        print(row)
        print(col)

Solution1=Solution()
list1=[[1,1,0],[2,1,0]]
Solution1.organeRotting(list1)