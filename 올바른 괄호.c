#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
bool solution(const char* s) { //문자열 s가 주어짐 
    bool answer = true;
    int top = 0; //초기화 

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(') {
            top++; //문자열 '('이 입력되면 top에 쌓는다 
        } else if (s[i] == ')') {
            top--; //문자열 ')'이 입력되면 스택의 top을 제거한다
        }

        if (top < 0) { //처음부터 top에 ')'가 입력될 수 없게한다 
            answer = false;
            break;
        }
    }

    if (top != 0) { //스택이 0이 아니라는 것은 내부에 '('가 남아 있으므로 false가 출력된다
        answer = false;
    }

    return answer;
}

