#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// prices_len은 배열 prices의 길이입니다.
int* solution(int prices[], size_t prices_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(prices_len * sizeof(int));  
    for (int i = 0; i < prices_len; ++i) {
        int time = 0;
        for (int j = i + 1; j < prices_len; ++j) {
            ++time; //j의 값이 pricess_len 보다 작을 때에는 주식이 유지되는 시간을 증가시킨다 

            if (prices[i] > prices[j]) {
                break;
            }
        }
        
        answer[i] = time; //가격이 떨어지기 직전의 시간을 answer 배열에 할당한다 
    }
    
    return answer; 
}
