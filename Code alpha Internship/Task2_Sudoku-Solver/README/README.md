
CodeAlpha_SudokuSolver

# 🔢 Sudoku Solver – C++ Project (CodeAlpha Internship)

This project is part of my submission for the **CodeAlpha C++ Programming Internship**.

It demonstrates a fully functional **Sudoku Solver** using the **backtracking algorithm** in C++. The program takes a predefined Sudoku grid and fills in the empty spaces while ensuring all Sudoku rules are followed.

---

## 🎯 Features

- Solves any standard 9x9 Sudoku puzzle
- Uses **backtracking** to try numbers recursively
- Checks validity of each move (row, column, and 3x3 subgrid)
- Displays the completed Sudoku grid
- Modular and clean code with comments

---

## 💡 How Sudoku Works

Sudoku is a logic-based puzzle game played on a **9×9 grid**, divided into **nine 3×3 boxes**. The objective is to fill the empty cells such that:

- Every row has all digits from 1 to 9 (no repetition)
- Every column has all digits from 1 to 9
- Every 3×3 subgrid has all digits from 1 to 9

---

## 🧮 Sample Puzzle (Input Grid)

```text
5 3 0 | 0 7 0 | 0 0 0
6 0 0 | 1 9 5 | 0 0 0
0 9 8 | 0 0 0 | 0 6 0
---------------------
8 0 0 | 0 6 0 | 0 0 3
4 0 0 | 8 0 3 | 0 0 1
7 0 0 | 0 2 0 | 0 0 6
---------------------
0 6 0 | 0 0 0 | 2 8 0
0 0 0 | 4 1 9 | 0 0 5
0 0 0 | 0 8 0 | 0 7 9
✅ Output (Solved Grid)
Copy
Edit
5 3 4 6 7 8 9 1 2
6 7 2 1 9 5 3 4 8
1 9 8 3 4 2 5 6 7
8 5 9 7 6 1 4 2 3
4 2 6 8 5 3 7 9 1
7 1 3 9 2 4 8 5 6
9 6 1 5 3 7 2 8 4
2 8 7 4 1 9 6 3 5
3 4 5 2 8 6 1 7 9
🧠 How It Works
The grid is stored as a 2D array.

The solveSudoku() function applies backtracking:

It searches for an empty cell.

It tries numbers from 1 to 9 in that cell.

If the move is valid (checked by isSafe()), it proceeds.

If stuck, it backtracks and tries another number.

Once solved, the grid is printed using printGrid().

🛠️ Technologies Used
Language: C++

Concepts: Backtracking, 2D Arrays, Recursion, Input/Output

Tools: Any standard compiler (e.g., g++, VS Code, Code::Blocks)

📂 Files
sudoku_solver.cpp — Full C++ source code

README.md — Project documentation


🔗 GitHub Repository
📌 Link: https://github.com/sanaullah23569/CodeAlpha_SudokuSolver
