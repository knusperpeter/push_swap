# 🔄 Push_swap
A highly efficient sorting algorithm implementation using two stacks, developed as part of the 42 school curriculum. This project challenges students to create a sorting program with a limited set of operations while optimizing for the minimum number of moves.

## ⚠️ Notice to 42 Students
This repository serves as a reference. Please:
- Understand the algorithm before using any code
- Don't copy without comprehension
- Use it to learn concepts, not to bypass learning

## 🎯 Project Overview
Push_swap is a program that sorts a stack of integers using two stacks (stack A and stack B) and a specific set of operations. The challenge lies in finding the most efficient sequence of operations to sort the numbers.

### Available Operations
| Operation | Description |
|-----------|-------------|
| `sa` | Swap first two elements of stack A |
| `sb` | Swap first two elements of stack B |
| `ss` | `sa` and `sb` at the same time |
| `pa` | Push top element from stack B to stack A |
| `pb` | Push top element from stack A to stack B |
| `ra` | Rotate stack A up by one |
| `rb` | Rotate stack B up by one |
| `rr` | `ra` and `rb` at the same time |
| `rra` | Rotate stack A down by one |
| `rrb` | Rotate stack B down by one |
| `rrr` | `rra` and `rrb` at the same time |

## ✨ Features
- Efficient sorting algorithm implementation
- Memory leak-free operation
- Error handling for invalid inputs
- Operation count optimization
- Support for various input sizes

## 🚀 Getting Started

### Prerequisites
- GCC compiler
- Make
- UNIX-based operating system

### Installation
```bash
# Clone the repository
git clone https://github.com/yourusername/push_swap.git

# Navigate to project directory
cd push_swap

# Compile the program
make
```

### Usage
```bash
# Sort integers provided as arguments
./push_swap 2 1 3 6 5 8

# Sort integers and count operations
./push_swap 2 1 3 6 5 8 | wc -l

# Test sorting with checker (if available)
ARG="2 1 3 6 5 8"; ./push_swap $ARG | ./checker $ARG
```

## 💡 Algorithm
The sorting algorithm implements the following strategies:
- Initial stack analysis
- Chunk-based sorting for large datasets
- Optimization for small sets (3-5 numbers)
- Position calculation for efficient moves

## 🎯 Performance Targets
| Number of Elements | Maximum Operations |
|-------------------|-------------------|
| 3 | 2-3 |
| 5 | 12 |
| 100 | 700 |
| 500 | 5500 |

## 🔍 Input Validation
The program handles various error cases:
- Duplicate numbers
- Non-numeric input
- Numbers exceeding INT_MAX/INT_MIN
- Empty input

## 💻 Implementation Details
- Written in C
- Modular code structure
- Efficient memory management
- Comprehensive error handling
- Algorithm complexity optimization

## 🤝 Contributing
Feel free to submit issues and enhancement requests.

## 📜 License
This project is open source and available under the [MIT License](LICENSE).

---
*Built with focus on algorithmic efficiency* 💫
