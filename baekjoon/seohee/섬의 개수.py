def dfs(x, y, graph):
    if x <= -1 or x >= w or y <= -1 or y >= h:
        return False
    if graph[x][y] == 0:
        graph[x][y] = 1
        dfs(x-1,y)
        dfs(x,y-1)
        dfs(x+1,y)
        dfs(x,y+1)
        return True
    return False

while True:
    w, h = map(int, input().split())
    if w == 0 and h == 0:
        break
    graph = []
    for i in range(h):
        graph.append(list(map(int, input().split())))
    
    result = 0
    for i in range(w):
        for j in range(h):
            if dfs(i,j):
                result += 1
    print(result)

# index 에러, 대각선 방향이 아직 안됨