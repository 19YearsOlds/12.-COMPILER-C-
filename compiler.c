#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *input, *output;

void compile() {
    char line[100];

    fprintf(output, "section .text\n");
    fprintf(output, "global _start\n");
    fprintf(output, "_start:\n");

    while (fgets(line, sizeof(line), input)) {
        char var[20];
        int value;


        if (sscanf(line, "%s = %d;", var, &value) == 2) {
            fprintf(output, "    mov eax, %d\n", value);
        }
    }

    fprintf(output, "    mov eax, 60\n");
    fprintf(output, "    xor edi, edi\n");
    fprintf(output, "    syscall\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    input = fopen(argv[1], "r");
    if (!input) {
        printf("Error opening file!\n");
        return 1;
    }

    output = fopen("output.asm", "w");
    if (!output) {
        printf("Error creating output file!\n");
        return 1;
    }

    compile();

    fclose(input);
    fclose(output);

    printf("Compilation successful! Generated output.asm\n");
    return 0;
}