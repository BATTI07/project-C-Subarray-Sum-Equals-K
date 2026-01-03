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
### Previous (Brute Force / Prefix Sum)
- Iterate over all possible subarrays.
- For each subarray, compute the sum and check if it equals `k`.
- Count the number of valid subarrays.

This method is simple to implement and works correctly, but is not optimal for large inputs.

### Current (Prefix Sum + Hash Map)
- Maintain a running prefix sum while traversing the array.
- Use a hash map to store the frequency of prefix sums encountered.
- For each new prefix sum, check if `(current_sum - k)` exists in the hash map.
- If it does, add the frequency to the count of valid subarrays.
- Update the hash map with the current prefix sum.

This approach reduces the time complexity to linear and scales well for large datasets.


---

## ⏱️ Complexity Analysis
- **Brute Force (previous solution):**
  - Time Complexity: **O(n²)** — two nested loops to check all subarrays.
  - Space Complexity: **O(n)** — prefix sums in an array.

- **Prefix Sum + Hash Map (current solution):**
  - Time Complexity: **O(n)** — single pass with hash lookups.
  - Space Complexity: **O(n)** — hash map stores prefix sums.


---

## 📂 Project Files
- `src/main.c` → Program entry point (reads input, calls solver).
- `src/source.c` → Implementation of the subarray sum algorithm.
- `src/Headers.h` → Function prototypes and shared definitions.
- `tests/testcases.txt` → Sample test inputs.
- `tests/large_test_generator.py` → Python script to generate large random test cases.
- `build/` → Output directory containing compiled binaries (e.g., `main.exe`).
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
## ✅ Continuous Integration (CI)

This project uses **GitHub Actions** to automate testing:
- Workflow files are located in `.github/workflows/`.
- On every push or pull request, the tests in `tests/` are executed automatically.
- The CI ensures that new changes do not break existing functionality.

You can view the status badge below:

![CI](https://github.com/BATTI07/repo/actions/workflows/ci.yml/badge.svg)
## 🤝 Contributing
- Fork the repository and create a new branch.
- Make your changes and commit them.
- Push your branch and open a pull request.
- GitHub Actions will automatically run tests to validate your changes.