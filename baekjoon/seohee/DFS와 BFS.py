from collections import deque

n, m, v = map(int, input().split())
visited_dfs = [False] * (n+1)
visited_bfs = [False] * (n+1)

graph = [[] for _ in range(n+1)]
for _ in range(m):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)
for i in graph:
    i.sort()

def dfs(graph, v, visited):
    visited[v] = True
    print(v, end= ' ')
    for i in graph[v]:
        if not visited[i]:
            dfs(graph, i, visited)

def bfs(graph, start, visited):
    queue = deque([start])
    visited[start] = True
    while queue:
        v = queue.popleft()
        print(v, end=' ')
        for i in graph[v]:
            if not visited[i]:
                queue.append(i)
                visited[i] = True

dfs(graph, v, visited_dfs)
print()
bfs(graph, v, visited_bfs)