#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// sizes_rows는 2차원 배열 sizes의 행 길이, sizes_cols는 2차원 배열 sizes의 열 길이입니다.
int solution(int** sizes, size_t sizes_rows, size_t sizes_cols) {
    int answer = 0;
    int height = 0, width = 0, max;
    for (int i = 0; i < sizes_rows; i++){
        if(sizes[i][0] < sizes[i][1]){ //가로와 세로를 비교하고 더 큰 값을 가로 값으로 지정 
            max = sizes[i][0];
            sizes[i][0] = sizes[i][1];
            sizes[i][1] = max;
        }
            if(sizes[i][0] > width){
                width = sizes[i][0]; //가로 최댓값
            }
            if(sizes[i][1] > height){
                height = sizes[i][1];
            }
        
    }
    answer = width * height;
    return answer;
}
