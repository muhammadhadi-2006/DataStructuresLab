#include<iostream>
#include<iomanip>

using namespace std;

class Node {

public:

	int data;
	Node* next;
	Node* prev;


	Node(int value)
	{
		this->data = value;
		this->next = nullptr;
		this->prev = nullptr;

	}



};

class DLL
{

public:

	Node* head;
	Node* tail;


	DLL()
	{
		head = nullptr;
		tail = nullptr;
	}

	//Task 1: Create a destructor
	~DLL() {
		Node* current = head;
		while (current != nullptr) {
			Node* next = current->next;
			delete current;
			current = next;
		}
		head = nullptr;
		tail = nullptr;
	}



	/*
	* display(): This function is used to display the linked list elements.
	* It will also check if the list is empty
	*/
	void display()
	{
		Node* current = head;

		if (current == nullptr)
		{
			cout << "List is Empty" << endl;
			return;
		}

		while (current != nullptr)
		{
			cout << current->data << endl;
			current = current->next;
		}
	}

	/*Display():
	*	This function is used to display the nodes.
	*	Prev Address: Contains the Address to the Previous Node
	*	Data: Contains the Values
	*	Next Address: Contians the Address of the Next Node
	*	Node Address: Address of the Complete Node
	*/
	void Display() {
		Node* temp = head;
		cout << "\n------------------------------------------------------\n";
		cout << "     Prev Address        |   Data   |     Next Address |   Node Address\n";
		cout << "------------------------------------------------------\n";

		while (temp != nullptr) {
			cout << setw(20) << temp->prev   // shows prev pointer address
				<< " | " << setw(7) << temp->data   // data field
				<< " | " << setw(18) << temp->next  // shows next pointer address
				<< " | " << setw(20) << temp
				<< endl;
			temp = temp->next;
		}
		cout << endl << "Tail: " << tail << endl;
		cout << "------------------------------------------------------\n";
	}



	/*
	* insertAtBegin():
	*	This function is used to insert the Node at the begining.
	*/
	void insertAtBegin(int value)
	{
		Node* newNode = new Node(value);

		newNode->next = head;

		if (head != nullptr)
		{
			head->prev = newNode;
		}
		head = newNode;

		if (head->next == nullptr)
		{
			tail = newNode;
		}
	}

	/* insertAtPos()
	*	This function is used to insert values at specific position
	*	This function will contains your task 2.
	*/
	void insertAtPos(int position, int value)
	{
		if (position == 1) {
			insertAtBegin(value);
			return;
		}

		Node* current = head;
		for (int i = 1; i < position; i++) {
			if (current == nullptr) {
				cout << "Invalid Index..!!" << endl;
				return;
			}
			current = current->next;
		}

		Node* newNode = new Node(value);
		if (current == nullptr) {
			insertAtEnd(value);
		} else {
			newNode->prev = current;
			newNode->next = current->next;
			if (current->next != nullptr) {
				current->next->prev = newNode;
			} else {
				tail = newNode;
			}
			current->next = newNode;
		}

		/*Task 2
		* Add four items in the linked list
		* And try to add the 5th Item in the linked List.
		* Do you see all the 5 element?
		* If No Fix the code segement.
		*/

	}

	/*
	* deleteFB()
	*	This function is used to delete the node from the front.
	*/

	void deleteFB() {


		if (head == nullptr)
		{
			cout << "List is Empty" << endl;
			return;
		}
		else if (head->next == nullptr)
		{
			delete head;
			head = nullptr;
			tail = nullptr;
		}
		else
		{
			Node* temp = head;
			head = head->next;
			head->prev = nullptr;
			delete temp;

			/*Task 3:
			* This code delete the elements from the begining of the list
			* Run this function you will see the first the node is deleted.
			* Can you see the problem with the head pointing to the new node?
			* Fix the code segement if you see the problem
			*/

		}
	}
	/*DisplayNode()
	*	The purpose of this function to display the content of the single node.
	*	Run this function you will see the content of more then one node.
	*	Task 4: Fix this.
	*/
	void DisplayNode(Node* node) {
		if (node == nullptr) {
			cout << "Node is null" << endl;
			return;
		}
		cout << "\n------------------------------------------------------\n";
		cout << "     Prev Address        |   Data   |     Next Address |   Node Address\n";
		cout << "------------------------------------------------------\n";

		cout << setw(20) << node->prev   // shows prev pointer address
			<< " | " << setw(7) << node->data   // data field
			<< " | " << setw(18) << node->next  // shows next pointer address
			<< " | " << setw(20) << node
			<< endl;
		cout << "------------------------------------------------------\n";
	}
	void search(int value)
	{
		Node* current = head;

		while (current != nullptr)
		{
			if (current->data == value)
			{
				cout << "Node found...";
				DisplayNode(current);
			}
			current = current->next;
		}
	}

	void insertAtEnd(int value)
	{
		if (tail == nullptr)
		{
			insertAtBegin(value);
		}
		else
		{
			Node* current = tail;
			Node* newNode = new Node(value);


			current->next = newNode;
			newNode->prev = current;
			newNode->next = nullptr;
			tail = newNode;

		}
	}


};

int main()
{
	/*
	* You need to complete the four task today.
	*
	*/

	//Add four elements to the Linked List to Solve Task 2
	DLL list;
	list.insertAtPos(1, 10);
	list.insertAtPos(2, 20);
	list.insertAtPos(3, 30);
	list.insertAtPos(4, 40);
	list.insertAtPos(5, 50); // Try to add 5th

	list.Display();

	//Delete the element from the begining, call the function to Solve Task 3
	list.deleteFB();
	list.Display();




}
