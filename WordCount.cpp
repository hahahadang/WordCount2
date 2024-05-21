#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning(disable:4996)
#define MAX_FILENAME_LENGTH 100 // �ļ�����󳤶�
#define MAX_PARAM_LENGTH 3 // ������󳤶�

// ��������
int count_characters(FILE* file);
int count_words(FILE* file);

int main() {
    char param[MAX_PARAM_LENGTH]; // ����
    char file_name[MAX_FILENAME_LENGTH]; // �ļ���

    // ��ȡ�û�����Ĳ������ļ���
    if (scanf("%2s %99s", param, file_name) != 2) {
        printf("Error: Invalid input format\n");
        return 1;
    }

    // ���ļ�
    FILE* file = fopen(file_name, "r");
    if (file == NULL) {
        printf("Error: Unable to open file\n");
        return 1;
    }

    // ���ݲ���ͳ���ַ����򵥴���
    if (strcmp(param, "-c") == 0) {
        int char_count = count_characters(file);
        printf("�ַ�����%d\n", char_count);
    }
    else if (strcmp(param, "-w") == 0) {
        int word_count = count_words(file);
        printf("��������%d\n", word_count);
    } else {
        printf("Error: Invalid parameter\n");
    }

    // �ر��ļ�
    fclose(file);

    return 0;
}

// ͳ���ַ���
int count_characters(FILE* file) {
    int char_count = 0; // �ַ�����
    char ch;

    while ((ch = fgetc(file)) != EOF) {
        char_count++;
    }

    return char_count;
}

// ͳ�Ƶ�����
int count_words(FILE* file) {
    int word_count = 0; // ���ʸ���
    int flag = 0; // ���Ƶ��ʸ�������
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

