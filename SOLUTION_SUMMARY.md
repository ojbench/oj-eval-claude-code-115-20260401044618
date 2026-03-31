# Problem 115 - 古明地恋的指针 - Solution Summary

## Problem Description
Implement a C++ smart pointer class `unique_ptr` that automatically manages memory and prevents memory leaks.

## Implementation
The implementation is in `src.hpp` and includes:

1. **Basic Constructor**: Creates an empty pointer (nullptr)
2. **Parametrized Constructor**: Takes ownership of a raw pointer
3. **Move Constructor**: Transfers ownership from another unique_ptr
4. **Move Assignment**: Transfers ownership while cleaning up current pointer
5. **Destructor**: Automatically deletes the managed pointer
6. **reset()**: Releases current pointer and sets to nullptr
7. **release()**: Returns the raw pointer and gives up ownership
8. **get()**: Returns the raw pointer without giving up ownership
9. **operator***: Dereferences the pointer
10. **operator->**: Provides member access
11. **make_unique()**: Factory function to create unique_ptr instances

### Key Design Decisions
- Single member variable `_Tp *ptr` to satisfy `sizeof(unique_ptr<int>) <= sizeof(void*)`
- Copy constructor and copy assignment are deleted (prevents double ownership)
- Move semantics properly implemented with nullptr assignment after transfer
- Destructor safely handles nullptr (as `delete nullptr` is safe in C++)
- Bonus: Implemented variadic template version of `make_unique` with perfect forwarding

## Test Results

### Local Testing
Created comprehensive test program (`test_main.cpp`) that validates:
- Basic construction and destruction
- Move constructor
- Move assignment
- Reset functionality
- Release functionality
- make_unique factory function
- Custom class support
- sizeof constraint verification

All local tests passed successfully.

### ACMOJ Submission Results
- **Submission ID**: 767188
- **Status**: Accepted
- **Score**: 50/50 (100%)
- **Test Groups**: 5/5 passed
- **Submission Attempt**: 1/5 (first attempt successful!)

#### Test Group Details:
1. Test 1: Accepted (603ms, 47.4MB)
2. Test 2: Accepted (1044ms, 65.2MB)
3. Test 3: Accepted (1007ms, 67.3MB)
4. Test 4: Accepted (590ms, 47.3MB)
5. Test 5: Accepted (576ms, 47.2MB)

Total execution time: 3820ms
Peak memory usage: 67.3MB

## Repository Structure
```
/workspace/problem_115/
├── README.md                    # Problem description
├── src.hpp                      # Main solution (unique_ptr implementation)
├── test_main.cpp                # Local test program
├── test_main                    # Compiled test binary
├── SOLUTION_SUMMARY.md          # This file
├── submit_acmoj/
│   ├── acmoj_client.py          # Submission script (fixed)
│   └── EVALUATION_GUIDE.md      # Evaluation documentation
└── .git/                        # Git repository
```

## Git Commits
1. `9a4ea6d` - Initial commit: Problem 115 setup
2. `717b516` - Initial implementation of unique_ptr smart pointer class
3. `763e021` - Fix acmoj_client.py: Add missing submit_code method

## Conclusion
The implementation successfully passes all test cases on the first attempt, achieving a perfect score of 50/50 (100%). The solution correctly implements all required functionality of a unique_ptr smart pointer with proper memory management, move semantics, and adherence to the size constraint.
