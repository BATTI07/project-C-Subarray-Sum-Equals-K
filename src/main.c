#include <stdio.h>
#include <stdlib.h>
#include "Headers.h"

// this is for safely read an integer from the file
int read_int(FILE *fp, int *out) {
    return fscanf(fp, "%d", out) == 1;
}

int main() {
    FILE *fp = fopen("tests/testcases.txt", "r");
    if (!fp) {
        printf("Error: could not open test file.\n");
        return 1;
    }

    // Skip first line (format description)
    char buffer[1024];
    if (!fgets(buffer, sizeof(buffer), fp)) {
        printf("Error: empty test file.\n");
        fclose(fp);
        return 1;
    }

    int testNumber, n, k, expected;
    while (fscanf(fp, "%d %d", &testNumber, &n) == 2) {
        int *arr = (int*)malloc(n * sizeof(int));
        if (!arr) {
            printf("Error: memory allocation failed for test %d.\n", testNumber);
            fclose(fp);
            return 1;
        }

        // Read array elements
        for (int i = 0; i < n; i++) {
            if (!read_int(fp, &arr[i])) {
                printf("Error: could not read array element for test %d.\n", testNumber);
                free(arr);
                fclose(fp);
                return 1;
            }
        }

        // Read target sum and expected result
        if (!read_int(fp, &k) || !read_int(fp, &expected)) {
            printf("Error: could not read k/expected for test %d.\n", testNumber);
            free(arr);
            fclose(fp);
            return 1;
        }

        // Call subarraySum
        int result = subarraySum(arr, n, k);
        free(arr);

        // Check result
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
