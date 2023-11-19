#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <stdio.h>
#include <string.h>

int main() {
    //task 1
    FILE* input_file = fopen("input.txt", "r");
    FILE* output_file = fopen("output.txt", "w");
    char line[256];
    char prevline[256];
    if (!input_file || !output_file) {
        printf("failed to open file.\n");
        return 1;
    }

    if (fgets(line, sizeof(line), input_file)) {
        while (fgets(prevline, sizeof(prevline), input_file)) {
            fputs(line, output_file);
            strncpy(line, prevline, sizeof(line));
        }
    }

    fclose(input_file);
    fclose(output_file);


    //Task 2
    FILE* inFile = fopen("input_task2.txt", "r");
    FILE* outFile = fopen("output_task2.txt", "w");
    char line_task2[2048];
    int lineNumber = 1;

    while (fgets(line_task2, sizeof(line_task2), inFile)) {
        if (lineNumber % 2 != 0) {
            fputs(line_task2, outFile);
        }
        lineNumber++;
    }

    fclose(inFile);
    fclose(outFile);

}
