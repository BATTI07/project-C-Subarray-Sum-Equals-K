# 📘 Project: Subarray Sum Equals K

## 🔎 Problem Statement
This project solves the **LeetCode Problem 560: Subarray Sum Equals K**  
👉 [LeetCode Reference](https://leetcode.com/problems/subarray-sum-equals-k/)

**Task:** Given an integer array `nums` and an integer `k`, return the total number of continuous subarrays whose sum equals `k`.

---

## 🌍 Real-Life Use Case
Detecting target sums in sequential data is useful in many domains:
- **Finance:** Finding consecutive days where net cash flow equals a threshold.
- **IoT/Sensors:** Identifying contiguous readings that accumulate to a calibration target.
- **Healthcare:** Detecting periods where patient metrics sum to a critical value.

---

## 🧠 Approach
Currently implemented: **Brute Force / Prefix Sum approach**
- Iterate over all possible subarrays.
- For each subarray, compute the sum and check if it equals `k`.
- Count the number of valid subarrays.

This is simple to implement and works correctly, but is not optimal for large inputs.

**Planned improvement:** Replace brute force with a **prefix sum + hash map** approach to achieve linear time complexity.

---

## ⏱️ Complexity Analysis
- **Current solution (brute force):**
  - Time Complexity: **O(n²)** — two nested loops to check all subarrays.
  - Space Complexity: **O(1)** — only a few variables used.

- **Future solution (prefix sum + hash map):**
  - Time Complexity: **O(n)**
  - Space Complexity: **O(n)**

---

## 📂 Project Files
- `main.c` → Program entry point (reads input, calls solver).
- `source.c` → Implementation of the subarray sum algorithm.
- `Headers.h` → Function prototypes and shared definitions.
- `testcases.txt` → Sample test inputs.
- `large_test_generator.py` → Python script to generate large random test cases.
- `Makefile` → Automates build and run.
- `README.md` → Documentation (this file).

---

## 🛠️ Build Instructions

### Linux / macOS (or Windows with make installed via MSYS2/Chocolatey/WSL)
If you have `make` available, the executable will be created in the `build/` folder:

```bash
# Build
make

# Run with sample test cases
make run

# Clean build artifacts
make clean

### Windows (without make)

By default, Windows does not include `make`. If you don’t want to install it, you can compile manually using `gcc`:

```bash
# Compile into build/ folder
gcc -Wall -Wextra -O2 src/main.c src/source.c -o build/main.exe

# Run with sample test cases
build\main.exe < tests\testcases.txt
