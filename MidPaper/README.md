<h2>ER Queue Management System</h2>

A C++ implementation of a Doubly Linked List to manage an Emergency Room (ER) patient queue. This program demonstrates basic operations like inserting patients at the beginning, end, or specific positions, deleting from the beginning, and printing the queue in various formats.

<h2> Features</h2>

<h2>- Doubly Linked List Structure: </h2>
Each node contains a Patient ID, with pointers to previous and next nodes.
<h3>- Insertion Operations:</h3>
  - Insert at the beginning of the queue.
  - Insert at the end of the queue.
  - Insert at a specific position in the queue.
<h3>- Deletion Operations:</h3>
  - Delete the patient at the beginning of the queue.
<h3>- Traversal and Display:</h3>
  - Print the queue forward (from head to tail).
  - Print the queue backward (from tail to head).
  - Graphical representation showing nodes connected with arrows.
<h3>- Utility Functions:</h3>
  - Get the Patient ID at the head.
  - Get the Patient ID at the tail.


<h2>Usage Example</h2> 

<h4>The `main()` function in `er_queue.cpp` provides a sample usage:</h4>

- Starts with an empty queue.
- Inserts patients with IDs 101 and 102 at the end.
- Inserts patient 200 at the beginning.
- Inserts patient 150 at position 2.
- Deletes the patient from the beginning.
- Inserts patient 300 at the end.
- Displays the final head and tail IDs, and prints the queue forward and backward.

<h2>Code Structure</h2> 

- Node Struct**: Represents a patient in the queue with `PatientId`, `prev`, and `next` pointers.
- DoublyLinkedList Class**: Manages the queue with private members `head`, `tail`, and `size`.
  - Public methods for insertion, deletion, and printing.
<h2>step by step process</h2>
Initial Empty List
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



