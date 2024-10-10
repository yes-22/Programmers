#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int dungeon;

// 현재 체력 k, 던전 정보 dungeons, 탐험 여부 visit, 던전의 수 rows, 현재까지 방문한 횟수 n을 입력 받기  
void search(int k, int **dungeons, int *visit, int rows, int n){ 
    if (dungeon < n ) dungeon = n;
    for (int i = 0; i < rows && dungeon < rows; i++){
        if (!visit[i] && dungeons[i][0] <= k){ 
            visit[i] = 1; //탐험한 던전 표시
            search(k - dungeons[i][1], dungeons, visit, rows, n + 1);
            visit[i] = 0;
        }
    }
}

// dungeons_rows는 2차원 배열 dungeons의 행 길이, dungeons_cols는 2차원 배열 dungeons의 열 길이입니다.
int solution(int k, int** dungeons, size_t dungeons_rows, size_t dungeons_cols) {
    int *visit = (int*)malloc(dungeons_rows * sizeof(int)); //malloc을 이용해 필요한 공간을 동적 할당한다
    for (int i = 0; i < dungeons_rows; i++)
        visit[i] = 0;
        
    search(k, dungeons, visit, dungeons_rows, 0);
    
    free(visit);
    return dungeon;
}
