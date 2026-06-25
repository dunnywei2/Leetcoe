#https://www.youtube.com/watch?v=gCswsDauXPc

#non recursion
def num_islands(grid: list[list[str]]) -> int:
    if not grid or not grid[0]:
        return 0

    rows = len(grid)
    cols = len(grid[0])
    count = 0

    def dfs_iterative(r: int, c: int) -> None:
        stack = [(r, c)]
        grid[r][c] = "0"

        while stack:
            row, col = stack.pop()

            for dr, dc in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
                nr = row + dr
                nc = col + dc

                if 0 <= nr < rows and 0 <= nc < cols and grid[nr][nc] == "1":
                    grid[nr][nc] = "0"
                    stack.append((nr, nc))

    for r in range(rows):
        for c in range(cols):
            if grid[r][c] == "1":
                count += 1
                dfs_iterative(r, c)

    return count


#recursion:
def num_islands(grid: list[list[str]]) -> int:
    if not grid or not grid[0]:
        return 0

    rows = len(grid)
    cols = len(grid[0])
    count = 0

    def dfs_iterative(r: int, c: int) -> None:
        if((r<0) or (r>=rows) or(c<0) or (c>=cols) or (grid[r][c]=='0')):
            return
        else:
           grid[r][c] = "0"
           dfs_iterative(r,c+1)
           dfs_iterative(r,c-1)
           dfs_iterative(r+1,c)
           dfs_iterative(r-1,c)


    for r in range(rows):
        for c in range(cols):
            if grid[r][c] == "1":
                count += 1
                dfs_iterative(r, c)

    return count

grid=[
    ["1","1","0","0","0"],
    ["1","1","0","0","0"],
    ["0","0","1","0","0"],
    ["0","0","0","1","1"]
]

print(num_islands(grid))
