#  BST Game Manager

## Description

This C++ program implements a Binary Search Tree (BST) to manage game players. Each player has a rating (used as key), name, and HP (health points). The BST supports various operations for adding, removing, updating, and querying players efficiently.

## Features

- **JOIN**: Add a new player with rating, name, and HP.
- **LEAVE**: Remove a player by rating.
- **STATUS**: Get details of a player by rating.
- **DAMAGE**: Reduce HP of a player.
- **HEAL**: Increase HP of a player.
- **MATCH**: Find the player with rating closest to a given value.
- **NEXT**: Find the player with the smallest rating greater than a given value.
- **PREV**: Find the player with the largest rating less than a given value.
- **RANGE**: List all players with ratings in a given range.
- **RANK**: Get the number of players with rating less than a given value.
- **KTH**: Find the Kth smallest rated player.
- **DUEL**: Calculate the distance between two players in the BST.
- **STATS**: Display statistics like number of players, min/max rating, height, and leaves.



Commands and parameters:

- `JOIN rating name hp`: rating (int), name (string), hp (int)
- `LEAVE rating`: rating (int)
- `STATUS rating`: rating (int)
- `DAMAGE rating amount`: rating (int), amount (int)
- `HEAL rating amount`: rating (int), amount (int)
- `MATCH X`: X (int)
- `NEXT X`: X (int)
- `PREV X`: X (int)
- `RANGE L R`: L (int), R (int)
- `RANK X`: X (int)
- `KTH k`: k (int)
- `DUEL A B`: A (int), B (int)
- `STATS`: No parameters

## Output Format

For each query, the program outputs specific results:

- JOIN: "JOINED" or "DUPLICATE"
- LEAVE: "LEFT" or "NOT FOUND"
- STATUS: "rating name hp" or "NOT FOUND"
- DAMAGE: "DAMAGED hp"
- HEAL: "HEALED hp"
- MATCH: "rating name hp" or "EMPTY"
- NEXT: "rating name hp" or "NONE"
- PREV: "rating name hp" or "NONE"
- RANGE: List of "rating name hp" or "EMPTY"
- RANK: An integer
- KTH: "rating name hp" or "OUT OF RANGE"
- DUEL: "DIST distance" or "NOT FOUND"
- STATS: Multiple lines with PLAYERS, MIN, MAX, HEIGHT, LEAVES

## Sample Input

See `sample_input.txt` for an example.

## Sample Output

Run the program with `sample_input.txt` to see the outputs.

## Notes

- Ratings are unique.
- HP cannot go below 0.
- The BST maintains order by rating.
- Time complexities are O(log N) for most operations due to BST properties.
