from collections import deque

def solution(rectangle, characterX, characterY, itemX, itemY):
    field = [[-1] * 102 for _ in range(102)]    # 필드를 102x102 크기로 초기화 (-1로 초기화)

    for x1, y1, x2, y2 in rectangle:     # 사각형의 좌표를 2배로 확장하여 필드에 표시
        x1, y1, x2, y2 = x1 * 2, y1 * 2, x2 * 2, y2 * 2
        for i in range(x1, x2 + 1):
            for j in range(y1, y2 + 1):
                if x1 < i < x2 and y1 < j < y2:
                    field[i][j] = 0  # 내부 채우기
                elif field[i][j] != 0:
                    field[i][j] = 1  # 테두리 채우기
    
    dx = [-1, 1, 0, 0]
    dy = [0, 0, -1, 1]
    q = deque([(characterX * 2, characterY * 2)])
    visited = [[-1] * 102 for _ in range(102)] #거리 기록 
    visited[characterX * 2][characterY * 2] = 0
    
    while q:      # BFS 실행
        x, y = q.popleft()
        
        if x == itemX * 2 and y == itemY * 2:
            return visited[x][y] // 2
        
        for k in range(4):
            nx, ny = x + dx[k], y + dy[k]
            if 0 <= nx < 102 and 0 <= ny < 102 and field[nx][ny] == 1 and visited[nx][ny] == -1:
                visited[nx][ny] = visited[x][y] + 1
                q.append((nx, ny))

    return -1
