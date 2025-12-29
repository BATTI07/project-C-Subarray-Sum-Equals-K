echo "# project-C-Subarray-Sum-Equals-K

C program to check if a subarray sum equals K.

## Build
gcc -Wall -Wextra -O2 main.c source.c -o subarray_k

## Run
./subarray_k testcases.txt

## Generate large tests
python3 large_test_generator.py > large_testcases.txt
./subarray_k large_testcases.txt
" > README.md