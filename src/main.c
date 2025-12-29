#include <stdio.h>
#include <stdlib.h>
#include "Headers.h"

int main() {
    FILE *fp = fopen("testcases.txt", "r");
    if (!fp) {
        printf("Error: could not open test file.\n");
        return 1;
    }

    // Skip the first line (format description)
    char buffer[1024];
    if (!fgets(buffer, sizeof(buffer), fp)) {
        printf("Error: empty test file.\n");
        fclose(fp);
        return 1;
    }

    int testNumber, n, k, expected;
    while (fscanf(fp, "%d %d", &testNumber, &n) == 2) {
        int *arr = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) {
            if (fscanf(fp, "%d", &arr[i]) != 1) {
                printf("Error: could not read array element for test %d.\n", testNumber);
                free(arr);
                fclose(fp);
                return 1;
            }
        }

        if (fscanf(fp, "%d %d", &k, &expected) != 2) {
            printf("Error: could not read k/expected for test %d.\n", testNumber);
            free(arr);
            fclose(fp);
            return 1;
        }

        int result = subarraySum(arr, n, k);
        free(arr);

        if (result != expected) {
            printf("Test %d FAILED\n", testNumber);
            printf("Received: %d, Expected: %d\n", result, expected);
            fclose(fp);
            return 1;
        }
    }

    printf("All tests were accepted.\n");
    fclose(fp);
    return 0;
}
