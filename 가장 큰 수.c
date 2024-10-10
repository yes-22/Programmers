#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


int compare(const void* a, const void* b) {
    char ab[20], ba[20];
    sprintf(ab, "%d%d", *(int*)a, *(int*)b);
    sprintf(ba, "%d%d", *(int*)b, *(int*)a);
    return strcmp(ba, ab);
}

char* solution(int numbers[], size_t numbers_len) {
    qsort(numbers, numbers_len, sizeof(int), compare);
    char* answer = (char*)malloc(numbers_len * 5 + 1);
    answer[0] = '\0'; 
    bool all_zero = true;
    for (int i = 0; i < numbers_len; i++) {
        if (numbers[i] != 0) {
            all_zero = false;
        }
        char num_str[5]; 
        sprintf(num_str, "%d", numbers[i]);
        strcat(answer, num_str);
    }

    if (all_zero) {
        char* result = (char*)malloc(2); 
        strcpy(result, "0");
        return result;
    }

    return answer;
}

int main() {
    int numbers[] = {6, 10, 2};
    size_t numbers_len = sizeof(numbers) / sizeof(numbers[0]);
    char* result = solution(numbers, numbers_len);
    printf("%d", result);
    return 0;
}
