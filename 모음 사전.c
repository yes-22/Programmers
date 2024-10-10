#include <stdio.h>
#include <string.h>

char vowels[] = "AEIOU"; 
int answer = -1;
int count = 0; 

void dfs(char current[], const char* target) { //현재 문자열 current, 찾고자 하는 문자열 target
    if (strcmp(current, target) == 0) { //strcmp 함수로 두 문자열 비교
        answer = count; 
        return;
    }


    if (strlen(current) > 5) { //strlen 함수를 통해 입력받은 문자열이 5 글자를 넘어가면 반환 
        return;
    }

    count++; 

    for (int i = 0; i < 5; i++) {
        char new[10];
        strcpy(new, current); //문자열 복사 
        strncat(new, &vowels[i], 1); //계속 붙여넣기 
        dfs(new, target); //재귀호출 사용

        if (answer != -1) { 
            return;
        }
    }
}

int solution(const char* word) {
    char initial[10] = ""; 
    dfs(initial, word); 
    return answer;
}
