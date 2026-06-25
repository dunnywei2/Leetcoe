#https://www.youtube.com/watch?v=y704fEOx0s0&t=234s


#0 representing an empty cell,
#1 representing a fresh orange, or
#2 representing a rotten orange.


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
                r,c =q.popleft()
                print("r %d c %d"%(r,c))
                for dr,dc in directions:
                    print("dr %d dc %d"%(dr,dc))
                    row,col=dr+r,dc+c
                    #if in bound, make orage rotten
                    if((row<0 or row==len(grid) or
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
        return_value=0
        if fresh==0:
            return_value=time
        else:
            return_value=-1
        return return_value


Solution1=Solution()
# list1=[[1,1,0],[2,1,0],[0,0,1]]
list1=[[2,1,1],[1,1,1],[1,1,1]]

print("return value is %d"%(Solution1.organeRotting(list1)));


# print the content of 2D array
# directions=[[0,1],[0,-1],[1,0],[-1,0]]
# for dr,dc in directions:
#     print("dr is %d"%(dr))
#     print("dc is %d"%(dc))


#From google gemini Q1 stage 1

#"Imagine an automated guided vehicle (AGV) in a warehouse. The warehouse is represented by an m x n grid, where 0 represents an empty path and 1 represents a fixed structural pillar (an obstacle). The robot starts at the top-left corner (0, 0) and needs to reach a charging dock at the bottom-right corner (m-1, n-1). Write a Python function to find the length of the shortest path. The robot can only move Up, Down, Left, and Right. If the destination is unreachable, return -1



from collections import deque

from collections import deque

def shortest_path_warehouse(grid):
    if not grid or not grid[0]:
        return -1
        
    rows, cols = len(grid), len(grid[0])
    
    # Edge case: If start or end is blocked
    if grid[0][0] == 1 or grid[rows-1][cols-1] == 1:
        return -1
        
    # Queue stores tuples of (row, col, current_steps)
    queue = deque([(0, 0, 0)])
    visited = {(0, 0)}
    
    directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]
    
    while queue:
        print("queue length is %d"%(len(queue)))
        r, c, steps = queue.popleft()
        
        print("r %d c%d steps%d "%(r,c,steps))

        
        # Goal check
        if r == rows - 1 and c == cols - 1:
            return steps
            
        # Explore neighbors
        for dr, dc in directions:
            nr, nc = r + dr, c + dc
            
            # Check boundaries, obstacles, and visited status
            if 0 <= nr < rows and 0 <= nc < cols:
                if grid[nr][nc] == 0 and (nr, nc) not in visited:
                    visited.add((nr, nc))
                    queue.append((nr, nc, steps + 1))
                    
    return -1

# --- Test Case Stage 1 ---
warehouse = [
    [0, 0, 0],
    [1, 1, 0],
    [1, 1, 0]
]
shortest_path_warehouse(warehouse)
# print(f"Stage 1 Shortest Path: {shortest_path_warehouse(warehouse)}")  # Expected: 4