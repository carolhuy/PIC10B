//I, Caroline Huynh, declare that this work is my own. I did this work honestly and can fully stand behind
//everything that I am submitting.
//None of the code submitted is copied from another person’s work.
//Section 3A

#include <string>
#include <iostream>

//allows assert to be called, which used to abort
#include <cassert>

using namespace std;

class List;
class Iterator;

class Node
{
public:
	/**
	   Constructs a node with a given data value.
	   @param s the data to store in this node
	*/
	Node(string s);
private:
	string data;
	Node* previous;
	Node* next;
	friend class List;
	friend class Iterator;
};

class List
{
public:
	/**
	   Constructs an empty list;
	*/
	List();
	/**
	   Appends an element to the list.
	   @param data the value to append
	*/
	void push_back(string data);
	/**
	   Inserts an element into the list.
	   @param iter the position before which to insert
	   @param s the value to append
	*/
	void insert(Iterator iter, string s);
	/**
	   Removes an element from the list.
	   @param iter the position to remove
	   @return an iterator pointing to the element after the
	   erased element
	*/
	Iterator erase(Iterator iter);
	/**
	   Gets the beginning position of the list.
	   @return an iterator pointing to the beginning of the list
	*/
	Iterator begin();
	/**
	   Gets the past-the-end position of the list.
	   @return an iterator pointing past the end of the list
	*/
	Iterator end();

	//to reverse the nodes in a list without creating a new list object
	void reverse();

	//add an element to the beginning of a list
	void push_front(string s);

	//swap two elements
	void swap(Iterator i1, Iterator i2);

private:
	Node* first;
	Node* last;
	friend class Iterator;
};

class Iterator
{
public:
	/**
	   Constructs an iterator that does not point into any list.
	*/
	Iterator();
	/**
	   Looks up the value at a position.
	   @return the value of the node to which the iterator points
	*/
	string get() const;
	/**
	   Advances the iterator to the next node.
	*/
	void next();
	/**
	   Moves the iterator to the previous node.
	*/
	void previous();
	/**
	   Compares two iterators
	   @param b the iterator to compare with this iterator
	   @return true if this iterator and b are equal
	*/
	bool equals(Iterator b) const;
private:
	Node* position;
	List* container;
	friend class List;
};

Node::Node(string s)
{
	data = s;
	previous = NULL;
	next = NULL;
}

List::List()
{
	first = NULL;
	last = NULL;
}

void List::push_back(string data)
{
	Node* new_node = new Node(data);
	if (last == NULL) // List is empty
	{
		first = new_node;
		last = new_node;
	}
	else
	{
		new_node->previous = last;
		last->next = new_node;
		last = new_node;
	}
}

void List::insert(Iterator iter, string s)
{
	if (iter.position == NULL)
	{
		push_back(s);
		return;
	}

	Node* after = iter.position;
	Node* before = after->previous;
	Node* new_node = new Node(s);
	new_node->previous = before;
	new_node->next = after;
	after->previous = new_node;
	if (before == NULL) // Insert at beginning
		first = new_node;
	else
		before->next = new_node;
}

void List::reverse() {

	//create three separate node pointers to move through the linked list and store data
	Node* next = NULL;
	Node* curr = first;
	Node* prev = NULL;

	//while not at the end of the list 
	while (curr != last) {

		//assign the next pointer to point at what the next pointer of curr is pointing at 
		//prevents losing the ability to access this node 
		next = curr->next; 

		//REVERSING MOTION 
		//assign the next pointer of curr to point at prev 
		curr->next = prev;

		//the previous pointer of curr point to next
		//previous and next pointers are both reverse 
		curr->previous = next;
		
		//MOVING POINTER ALONG LINKED LIST 
		//assign prev to point at curr and curr to move to the next node 
		prev = curr;
		curr = next;
}
	//moving the first pointer to reverse the direction 
	first = prev;
}

void List::push_front(string s) {
	//need to do the left side 
	//make a new node and pointer to new node 
	Node* newOne = new Node(s);
	Node* newLeft = new Node(s);
	
	//if there is nothing in the list 
	if(first==0){
		//make this the first item 
		first = newOne;
	}
	else {
	//if there is something in the linked list 
		//point the pointer of node to what the first is pointing at 
		newLeft = first; 
		newOne->next = first; 
		newLeft->previous = newOne; 

		//need to have the first pointer pointer to newOne because will disappear later  
		first = newOne; 
	}
}

void List::swap(Iterator i1, Iterator i2) {
	//making nullpointers to store the values to the left and right of the first and second iterators 
	Node* iteratorOneLeft = NULL;
	Node* iteratorOneRight = NULL; 
	Node* iteratorTwoLeft = NULL;
	Node* iteratorTwoRight = NULL;
	
	//moving the position of iterators to store the ones to the left and right of the first and second iterators 
	iteratorTwoRight = i2.position->next; 
	iteratorTwoLeft = i2.position->previous;
	iteratorOneRight = i1.position->next;
	iteratorOneLeft = i1.position->previous;

	//if the first iterator is the first (or head) object in the linked list 
	if (i1.position == first){

		//move the head to point at the iterator two's node
		first = i2.position;

		//move the next pointer first to point at the node to the right of the iterator one 
		first->next = iteratorOneRight;

		//move the next pointer of iterator one to point at the right of iterator two 
		i1.position->next = iteratorTwoRight;

		//move the previous pointer of iterator one to point at the left of iterator two 
		i1.position->previous = iteratorTwoLeft;

		//move the previous pointer of the right of iterator two to point at iterator one's node 
		iteratorTwoRight->previous = i1.position;

		//move the next pointer of the left of iterator two to point at iterator one's node 
		iteratorTwoLeft->next = i1.position;

		//move the previous pointer of the left of iterator two to point at the first 
		iteratorTwoLeft->previous = first;
	}
			
	//if the second iterator is the first node in the linked list
	else if (i2.position == first){
		//move the head to point at the iterator one's node
		first = i1.position;

		//move the next pointer first to point at the node to the right of the iterator two 
		first->next = iteratorTwoRight;
		
		//move the next pointer of iterator two to point at the right of iterator one
		i2.position->next = iteratorOneRight;

		//move the previous pointer of iterator two to point at the left of iterator one 
		i2.position->previous = iteratorOneLeft;

		//move the previous pointer of the right of iterator one to point at iterator two's node 
		iteratorOneRight->previous = i2.position;

		//move the next pointer of the left of iterator one to point at iterator two's node 
		iteratorOneLeft->next = i2.position;

		//move the previous pointer of the left of iterator one to point at the first 
		iteratorOneLeft->previous = first;
	}

	//if the first iterator is the last node 
	else if (i1.position == last) {
	
		//assign last to point at the node of iterator two 
		last = i2.position;

		//assign the previous pointer belonging to last to point at the left of iterator one 
		last->previous = iteratorOneLeft;

		//next pointer to the left of iterator one points to last  
		iteratorOneLeft->next = last; 

		//next pointer of iterator one point to the right of iterator two 
		i1.position->next = iteratorTwoRight;

		//previous pointer of iterator one point at the left of iterator two 
		i1.position->previous = iteratorTwoLeft;

		//the next pointer of left of iterator two point at the node of iterator one 
		iteratorTwoLeft->next = i1.position; 

		//the previous pointer of right of iterator two point at the node of iterator one
		iteratorTwoRight->previous = i1.position;
	}

	//if the second iterator is the last node 
	else if (i2.position == last) {

		//assign last to point at the node of iterator one
		last = i1.position;

		//assign the previous pointer belonging to last to point at the left of iterator two
		last->previous = iteratorTwoLeft;

		//next pointer to the left of iterator two points to last 
		iteratorTwoLeft->next = last;

		//next pointer of iterator two point to the right of iterator one 
		i2.position->next = iteratorOneRight;

		//previous pointer of iterator two point at the left of iterator one 
		i2.position->previous = iteratorOneLeft;

		//the next pointer of left of iterator one point at the node of iterator two
		iteratorOneLeft->next = i2.position;

		//the previous pointer of right of iterator one point at the node of iterator two
		iteratorOneRight->previous = i2.position;
	}

	//if the two nodes are not pointing to the first or last node 
	else {

	//assign the next pointer of iterator one to point at the right of iterator two 
		i1.position->next = iteratorTwoRight;

		//assign the previous pointer of iterator one to point at left of iterator two 
		i1.position->previous = iteratorTwoLeft; 

		//assign the next pointer of iterator two to point at the right of iterator one 
		i2.position->next = iteratorOneRight;

		//assign previous pointer of iterator two to point at the node left of iterator one 
		i2.position->previous = iteratorOneLeft;

		//assign the previous pointer of the node right of iterator two to point at iterator one 
		iteratorTwoRight->previous = i1.position;

		//assign the next pointer of the node left of iterator two to point at iterator one 
		iteratorTwoLeft->next = i1.position;

		//assign the next pointer of the node left of iterator one to point at iterator two 
		iteratorOneLeft->next = i2.position;

		//assign the previous pointer of the node right of iterator one to point at iterator two 
		iteratorOneRight->previous = i2.position;
	}
}

Iterator List::erase(Iterator iter)
{
	assert(iter.position != NULL);
	Node* remove = iter.position;
	Node* before = remove->previous;
	Node* after = remove->next;
	if (remove == first)
		first = after;
	else
		before->next = after;
	if (remove == last)
		last = before;
	else
		after->previous = before;
	delete remove;
	Iterator r;
	r.position = after;
	r.container = this;
	return r;
}

Iterator List::begin()
{
	Iterator iter;
	iter.position = first;
	iter.container = this;
	return iter;
}

Iterator List::end()
{
	Iterator iter;
	iter.position = NULL;
	iter.container = this;
	return iter;
}

Iterator::Iterator()
{
	position = NULL;
	container = NULL;
}

string Iterator::get() const
{
	assert(position != NULL);
	return position->data;
}

void Iterator::next()
{
	assert(position != NULL);
	position = position->next;
}

void Iterator::previous()
{
	assert(position != container->first);
	if (position == NULL)
		position = container->last;
	else
		position = position->previous;
}

bool Iterator::equals(Iterator b) const
{
	return position == b.position;
}

int main()
{
	List staff;
	Iterator pos;
	staff.push_front("Tom");
	staff.push_front("Dick");
	staff.push_front("Harry");
	staff.push_front("Juliet");

	cout << "******* Initial List *******\n";
	for (pos = staff.begin(); !pos.equals(staff.end()); pos.next())
		cout << pos.get() << "\n";

	// reverse the list
	cout << "******* Reverse List *******\n";
	staff.reverse();
	for (pos = staff.begin(); !pos.equals(staff.end()); pos.next())
		cout << pos.get() << "\n";

	// swap two elements
	Iterator pos1, pos2;
	pos1 = staff.begin();
	pos2 = staff.begin();
	pos2.next();
	pos2.next();
	staff.swap(pos1, pos2);
	cout << "******* After Swapping *******\n";
	for (pos = staff.begin(); !pos.equals(staff.end()); pos.next())
		cout << pos.get() << "\n";
	return 0;
}

