# ER Queue Management System

A C++ implementation of a Doubly Linked List to manage an Emergency Room (ER) patient queue. This program demonstrates basic operations like inserting patients at the beginning, end, or specific positions, deleting from the beginning, and printing the queue in various formats.

## Features

- **Doubly Linked List Structure**: Each node contains a Patient ID, with pointers to previous and next nodes.
- **Insertion Operations**:
  - Insert at the beginning of the queue.
  - Insert at the end of the queue.
  - Insert at a specific position in the queue.
- **Deletion Operations**:
  - Delete the patient at the beginning of the queue.
- **Traversal and Display**:
  - Print the queue forward (from head to tail).
  - Print the queue backward (from tail to head).
  - Graphical representation showing nodes connected with arrows.
- **Utility Functions**:
  - Get the Patient ID at the head.
  - Get the Patient ID at the tail.



## Usage Example

The `main()` function in `er_queue.cpp` provides a sample usage:

- Starts with an empty queue.
- Inserts patients with IDs 101 and 102 at the end.
- Inserts patient 200 at the beginning.
- Inserts patient 150 at position 2.
- Deletes the patient from the beginning.
- Inserts patient 300 at the end.
- Displays the final head and tail IDs, and prints the queue forward and backward.

## Code Structure

- **Node Struct**: Represents a patient in the queue with `PatientId`, `prev`, and `next` pointers.
- **DoublyLinkedList Class**: Manages the queue with private members `head`, `tail`, and `size`.
  - Public methods for insertion, deletion, and printing.

## Graphical Representation of Linked List After Performing Each Step

### Initial Empty List
```
NULL
```

### After insertAtEnd(101)
```
[101] <-> NULL
```

### After insertAtEnd(102)
```
[101] <-> [102] <-> NULL
```

### After insertAtBeginning(200)
```
[200] <-> [101] <-> [102] <-> NULL
```

### After insertAtPosition(150, 2)
```
[200] <-> [150] <-> [101] <-> [102] <-> NULL
```

### After deleteFromBeginning()
```
[150] <-> [101] <-> [102] <-> NULL
```

### After insertAtEnd(300)
```
[150] <-> [101] <-> [102] <-> [300] <-> NULL
