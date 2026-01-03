def generate_testcases():
    n = 10000

    with open("tests/testcases.txt", "w") as f:
        # Header line for clarity (skipped by main.c)
        f.write("# testNumber n arr[0] ... arr[n-1] k expected\n")

        # 81: All zeros
        arr81 = [0] * n
        k81 = 0
        expected81 = n * (n + 1) // 2
        print(81, n, *arr81, k81, expected81, file=f)

        # 82: All ones
        arr82 = [1] * n
        k82 = n
        expected82 = 1
        print(82, n, *arr82, k82, expected82, file=f)

        # 83: Alternating 1 and -1
        arr83 = [1 if i % 2 == 0 else -1 for i in range(n)]
        k83 = 0
        from collections import defaultdict
        prefix_sum = 0
        count = 0
        freq = defaultdict(int)
        freq[0] = 1
        for num in arr83:
            prefix_sum += num
            count += freq[prefix_sum - k83]
            freq[prefix_sum] += 1
        expected83 = count
        print(83, n, *arr83, k83, expected83, file=f)

        # 84: All 1000s
        arr84 = [1000] * n
        k84 = 1000
        expected84 = n
        print(84, n, *arr84, k84, expected84, file=f)

        # 85: Sparse non-zero (one 5 among zeros)
        arr85 = [0] * (n - 1)
        arr85.insert(n // 2, 5)
        k85 = 5
        expected85 = (n // 2 + 1) * (n - n // 2)
        print(85, n, *arr85, k85, expected85, file=f)

        # 86: Repeated mixed pattern
        pattern = [3, 4, 7, 2, -3, 1, 4, 2]
        arr86 = (pattern * (n // len(pattern)))[:n]
        k86 = 7
        prefix_sum = 0
        count = 0
        freq = defaultdict(int)
        freq[0] = 1
        for num in arr86:
            prefix_sum += num
            count += freq[prefix_sum - k86]
            freq[prefix_sum] += 1
        expected86 = count
        print(86, n, *arr86, k86, expected86, file=f)


if __name__ == "__main__":
    generate_testcases()
