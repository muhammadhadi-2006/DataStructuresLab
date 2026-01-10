# 🎮 Player Management System using Binary Search Tree (BST)

**Author:** Muhammad Hadi  
**Language:** C++  
**Data Structure:** Binary Search Tree (BST)

---

## 📌 Project Overview

This project implements a **Player Management System** using a **Binary Search Tree (BST)**. Each player is stored as a node in the tree based on their **rating**, allowing fast searching, ranking, and advanced queries.

The system is fully **command-driven**, making it suitable for:
- Data Structures assignments
- Algorithm practice
- Competitive programming preparation
- Academic projects

---

## 🧩 Player Node Structure

Each player contains:

- 🎯 Rating (used as BST key)
- 🧑 Name
- ❤️ Health Points (HP)
- 🌿 Left & Right child pointers
- 👨‍👩‍👧 Parent pointer
- 📏 Subtree size (for rank & k-th queries)

---

## ⚙️ Supported Commands & Features

### 🟢 Basic Operations

| Command | Description |
|--------|-------------|
| JOIN | Insert a new player |
| LEAVE | Remove a player |
| STATUS | Show player information |

### 🔧 Health Management

| Command | Description |
|---------|-------------|
| DAMAGE | Reduce player HP |
| HEAL | Increase player HP |

### 🔍 Search & Navigation

| Command | Description |
|---------|-------------|
| MATCH | Find closest rating player |
| NEXT | Find next higher rating |
| PREV | Find previous lower rating |

### 📊 Advanced Queries

| Command | Description |
|---------|-------------|
| RANGE | List players in rating range |
| RANK | Find rank of rating |
| KTH | Find k-th smallest player |
| DUEL | Distance between two players |
| STATS | Tree statistics |

---

## 🌳 Tree Statistics Provided

- Total number of players
- Minimum rating
- Maximum rating
- Height of BST
- Number of leaf nodes

---

## 🧠 Algorithms Used

- Binary Search Tree insertion & deletion
- Tree traversal (in-order)
- Lowest Common Ancestor (LCA)
- Subtree size maintenance
- Rank & k-th order statistics
- Tree height and leaf counting

---

## ▶️ How to Run

1. Compile the program:

```bash
g++ -std=gnu++17 main.cpp -o player_system
```

2. Run the program:

```bash
./player_system
```

3. Enter number of queries followed by commands.

---

## 📥 Sample Input

```
5
JOIN 150 Alex 80
JOIN 100 Bob 60
STATUS 150
RANK 120
STATS
```

---

## 📤 Sample Output

```
JOINED
JOINED
150 Alex 80
1
PLAYERS 2
MIN 100
MAX 150
HEIGHT 1
LEAVES 1
```

---

## ✨ Why This Project is Useful

- Demonstrates real-world use of BST
- Covers advanced tree operations
- Clean object-oriented design
- Efficient time complexity
- Easy to extend (AVL / Red-Black Tree)

---

## 🚀 Possible Enhancements

- Self-balancing tree (AVL or Red-Black)
- File input/output support
- GUI or web interface
- Player sorting by HP
- Multiplayer battle simulation

---

## 🏷️ Tags

`C++` `Binary Search Tree` `Data Structures` `Algorithms` `Ranking System` `Command Line Project`

---

## 👨‍💻 Author

**Muhammad Hadi**  
Computer Science Student / Developer

---

⭐ If you like this project, feel free to enhance it and use it in your assignments or portfo