def solution(arrows):
    move = [(0, 1), (1, 1), (1, 0), (1, -1), (0, -1), (-1, -1), (-1, 0), (-1, 1)]   #각 방향 정의
    visited = set()
    crossed = set()
    x, y = (0, 0)

    for arrow in arrows:
        for _ in range(2):         # 화살표 방향에 따라 두 번 이동
            nx, ny = x + move[arrow][0], y + move[arrow][1]
            if ((x, y), (nx, ny)) in crossed:      #이미 교차한 선분이라면 이동만 하고 넘어감 
                x, y = nx, ny
                continue
            visited.add((x, y))    #방문한 점을 추가
            visited.add((nx, ny))
            crossed.add(((x, y), (nx, ny)))    #교차한 선분을 추가합니다.
            crossed.add(((nx, ny), (x, y)))
            x, y = nx, ny

    #방의 개수를 반환
    return len(crossed) // 2 - len(visited) + 1
