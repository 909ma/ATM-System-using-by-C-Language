#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

int main() {
    char file1[] = "people.csv";
    char file2[] = "new_people.csv";
    char output[] = "merged.csv";

    FILE *fp1 = fopen(file1, "r");
    if (fp1 == NULL) {
        printf("Error: Failed to open %s\n", file1);
        exit(EXIT_FAILURE);
    }

    FILE *fp2 = fopen(file2, "r");
    if (fp2 == NULL) {
        printf("Error: Failed to open %s\n", file2);
        exit(EXIT_FAILURE);
    }

    FILE *fp_out = fopen(output, "w");
    if (fp_out == NULL) {
        printf("Error: Failed to create %s\n", output);
        exit(EXIT_FAILURE);
    }

    // Write header
    fprintf(fp_out, "BankName,BankCode,ClientCode,ClientName,CardNumber,AccountNumber,NowMoney,AccountPW,AccountDate\n");

    // Skip header line in both files
    char line[MAX_LINE_SIZE];
    fgets(line, MAX_LINE_SIZE, fp1);
    fgets(line, MAX_LINE_SIZE, fp2);

    // Merge files
    while (fgets(line, MAX_LINE_SIZE, fp1) != NULL) {
        fprintf(fp_out, "%s", line);
    }

    while (fgets(line, MAX_LINE_SIZE, fp2) != NULL) {
        fprintf(fp_out, "%s", line);
    }

    fclose(fp1);
    fclose(fp2);
    fclose(fp_out);

    printf("Merged file saved to %s\n", output);

    return 0;
}

