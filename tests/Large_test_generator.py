import os

def generate_testcases():
    n = 10000
    new_tests = []
    
    # 81: All zeros
    arr81 = [0] * n
    k81 = 0
    expected81 = n * (n + 1) // 2  # every subarray sums to 0
    new_tests.append((81, n, arr81, k81, expected81))

    # 82: All ones
    arr82 = [1] * n
    k82 = n
    expected82 = 1  # only full array sums to n
    new_tests.append((82, n, arr82, k82, expected82))

    # 83: Alternating 1 and -1
    arr83 = [1 if i % 2 == 0 else -1 for i in range(n)]
    k83 = 0
    # Expected output is tricky; many subarrays cancel to 0. Approx ~5000.
    # For demonstration, we compute it directly:
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
    new_tests.append((83, n, arr83, k83, expected83))

    # 84: All 1000s
    arr84 = [1000] * n
    k84 = 1000
    expected84 = n  # each single element counts
    new_tests.append((84, n, arr84, k84, expected84))

    # 85: Sparse non-zero (one 5 among zeros)
    arr85 = [0] * (n - 1)
    arr85.insert(n // 2, 5)  # put a 5 in the middle
    k85 = 5
    # Every subarray including that 5 counts
    expected85 = (n // 2 + 1) * (n - n // 2)
    new_tests.append((85, n, arr85, k85, expected85))

    # 86: Repeated mixed pattern
    pattern = [3, 4, 7, 2, -3, 1, 4, 2]
    arr86 = (pattern * (n // len(pattern)))[:n]
    k86 = 7
    # Compute expected output
    prefix_sum = 0
    count = 0
    freq = defaultdict(int)
    freq[0] = 1
    for num in arr86:
        prefix_sum += num
        count += freq[prefix_sum - k86]
        freq[prefix_sum] += 1
    expected86 = count
    new_tests.append((86, n, arr86, k86, expected86))


    ''' For New Tests
    Ith: New Test
    arrI = Generate array
    kI = k value
    expectedI =  calculate expected value
    new_tests.append((I, n, arrI, kI, expectedI))'''

    # --- Append only new tests ---
    test_file = "tests/testcases.txt"
    existing_ids = set()

    if os.path.exists(test_file):
        with open(test_file, "r") as f:
            for line in f:
                parts = line.strip().split()
                if parts:
                    try:
                        existing_ids.add(int(parts[0]))
                    except ValueError:
                        pass  # skip malformed lines

    with open(test_file, "a") as f:
        for tid, n, arr, k, expected in new_tests:
            if tid not in existing_ids:
                line = f"{tid} {n} " + " ".join(map(str, arr)) + f" {k} {expected}\n"
                f.write(line)
                print(f"Added test {tid}")
            else:
                print(f"Skipped test {tid} (already exists)")

if __name__ == "__main__":
    generate_testcases()
