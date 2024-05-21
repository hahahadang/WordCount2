#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning(disable:4996)
#define MAX_FILENAME_LENGTH 100 // 文件名最大长度
#define MAX_PARAM_LENGTH 3 // 参数最大长度

// 函数声明
int count_characters(FILE* file);
int count_words(FILE* file);

int main() {
    char param[MAX_PARAM_LENGTH]; // 参数
    char file_name[MAX_FILENAME_LENGTH]; // 文件名

    // 获取用户输入的参数和文件名
    if (scanf("%2s %99s", param, file_name) != 2) {
        printf("Error: Invalid input format\n");
        return 1;
    }

    // 打开文件
    FILE* file = fopen(file_name, "r");
    if (file == NULL) {
        printf("Error: Unable to open file\n");
        return 1;
    }

    // 根据参数统计字符数或单词数
    if (strcmp(param, "-c") == 0) {
        int char_count = count_characters(file);
        printf("字符数：%d\n", char_count);
    }
    else if (strcmp(param, "-w") == 0) {
        int word_count = count_words(file);
        printf("单词数：%d\n", word_count);
    } else {
        printf("Error: Invalid parameter\n");
    }

    // 关闭文件
    fclose(file);

    return 0;
}

// 统计字符数
int count_characters(FILE* file) {
    int char_count = 0; // 字符个数
    char ch;

    while ((ch = fgetc(file)) != EOF) {
        char_count++;
    }

    return char_count;
}

// 统计单词数
int count_words(FILE* file) {
    int word_count = 0; // 单词个数
    int flag = 0; // 控制单词个数增加
    char ch;

    while ((ch = fgetc(file)) != EOF) {
        if (ch == ' ' || ch == '\n' || ch == '\t' || ch == ',') {
            flag = 0;
        }
        else if (flag == 0) {
            flag = 1;
            word_count++;
        }
    }

    return word_count;
}

