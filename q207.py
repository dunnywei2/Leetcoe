#Course Schedule
#https://www.youtube.com/watch?v=nz5V5pOiT8w&pp=ygUYQ291cnNlIFNjaGVkdWxlIGxlZXRjb2Rl

#my solution
from collections import defaultdict, deque

def course_order(num_courses: int, prerequisites: list[list[int]]) -> bool:
    g = defaultdict(list)
    courses=prerequisites
    for a,b in courses:
        g[a].append(b)
    
    print(g)

    # print(g[1])
    # print(g[2])

    
    UNVISITED = 0
    VISITING =1
    VISITED =2

    states = [UNVISITED]*num_courses

    print(states)

    def dfs(node):
        state=states[node]
        if state== VISITED:
            return True
        elif state==VISITING:
            return False
        
        states[node]=VISITING

        for nei in g[node]:
            print("nei %d"%(nei))

            if not dfs(nei):
                return False
        states[node]=VISITED
        return True
          
        return True

    for i in range(num_courses):
        if not dfs(i):
              return False
        
    return True

numCourse=3
prerequisites=[[1,0],[2,1]]

#CYCLE
# numCourse=2 
# prerequisites=[[1,0],[0,1]]

print(course_order(numCourse,prerequisites))




#other solution
# from collections import defaultdict, deque

# def course_order(num_courses: int, prerequisites: list[list[int]]) -> list[int]:
#     graph = defaultdict(list)
#     indegree = [0] * num_courses

#     for course, prereq in prerequisites:
#         graph[prereq].append(course)
#         indegree[course] += 1

#     queue = deque([i for i in range(num_courses) if indegree[i] == 0])
#     order = []

#     while queue:
#         course = queue.popleft()
#         order.append(course)

#         for next_course in graph[course]:
#             indegree[next_course] -= 1

#             if indegree[next_course] == 0:
#                 queue.append(next_course)

#     if len(order) != num_courses:
#         return []

#     return order