from collections import deque

def count_connected(start, graph, visited, link_status):
    queue = deque([start])
    visited[start] = True #처음 노드 방문 처리
    count = 1

    while queue:
        node = queue.popleft()
        for neighbor in graph[node]:
            if not visited[neighbor] and link_status[start][neighbor]: #아직 방문하지 않은 노드를 큐에 삽입
                queue.append(neighbor)
                visited[neighbor] = True
                count += 1

    return count

def solution(n, wires):
    min_difference = n  #초기값을 n으로 설정한 min_differnce를 설정
    
    link_status = [[True] * (n + 1) for _ in range(n + 1)]   #2차원 배열을 통해 모든  노드가 연결되어 있음을 설정
    graph = [[] for _ in range(n + 1)]     #graph를 통해 송전탑에 연결된 다른 송전탑들 저장                  

    for a, b in wires:
        graph[a].append(b)
        graph[b].append(a)

	    for a, b in wires: #전선을 하나씩 순회하면서 방문 여부를 나타냄 
        visited = [False] * (n + 1)
        link_status[a][b] = False  #전선 제거
        cnt_a = count_connected(a, graph, visited, link_status)  
        cnt_b = count_connected(b, graph, visited, link_status)  
        link_status[a][b] = True  #전선 연결 

        min_difference = min(min_difference, abs(cnt_a - cnt_b))
    
    return min_difference

n = 9
wires = [[1,3],[2,3],[3,4],[4,5],[4,6],[4,7],[7,8],[7,9]]
print(solution(n, wires))
