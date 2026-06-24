#https://www.youtube.com/watch?v=y704fEOx0s0&t=234s
from collections import deque
from pprint import pprint

class Solution:
    def organeRotting(self,grid:list[list[int]])->int:
        row,col=len(grid),len(grid[0]);
        print(row)
        print(col)

        q=deque();
        time,fresh=0,0;

        for r in range(row):
            for c in range (col):
                if grid[r][c]==1:
                    fresh+=1
                if grid[r][c]==2:
                    q.append([r,c]);

        print(fresh)
        print(len(q))

        directions=[[0,1],[0,-1],[1,0],[-1,0]]
        while q and fresh >0:
            #if there is a rot organe and # of fresh >0 do
            for i in range(len(q)):
                r,c =q.pop()
                print("r %d c %d"%(r,c))
                for dr,dc in directions:
                    print("dr %d dc %d"%(dr,dc))
                    row,col=dr+r,dc+c
                    if((row<0 or row==len(grid) and
                       col<0 or col==len(grid[0])) or grid[row][col]!=1):
                       print("row %d col %d first time"%(row,col))

                       continue
                    print("row %d col %d second time"%(row,col))

                    grid[row][col]=2
                    q.append([row,col])
                    fresh-=1
            print("time is %d with with grid" %(time))
            pprint(grid,width=20)
            time+=1
        print("length of q is %d fresh %d" %(len(q),fresh))


Solution1=Solution()
# list1=[[1,1,0],[2,1,0],[0,0,1]]
list1=[[2,1,1],[1,1,1],[1,1,1]]

Solution1.organeRotting(list1)


# print the content of 2D array
# directions=[[0,1],[0,-1],[1,0],[-1,0]]
# for dr,dc in directions:
#     print("dr is %d"%(dr))
#     print("dc is %d"%(dc))
