#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char* solution(const char* number, int k) {
    int len = strlen(number);  // 입력된 문자열의 길이 저장
    int n = len - k;  //최종 문자열의 길이로 n을 설정하고 len에서 제거할 문자 수인 k를 뺀 값을 저장 
    char* answer = (char*)malloc((n + 1) * sizeof(char));  //가장 큰 수를 저장할 answer에 동적 할당을 한다 
    
    int idx = -1;  
    for (int i = 0; i < n; i++) { //
        char max = '0';  //가장 큰 수를 저장할 변수 max 선언
        for (int j = idx + 1; j <= k + i; j++) { //idx+1 부터 k+i 까지의 범위에서 탐색
            if (max < number[j]) { //현재 숫자인 number[j]가 더 클 경우
                max = number[j];  //max에 최대값을 저장
                idx = j; 
            }
        }
        answer[i] = max;  //가장 큰 수를 배열에 저장 
    }
    answer[n] = '\0'; 

    return answer;
}
