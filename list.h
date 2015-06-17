/*
 * list.h
 *
 *  Created on: Jun 10, 2015
 *      Author: Shaked
 */

#ifndef LIST_H_
#define LIST_H_


using namespace std;

template<class T>
class Node{
	T data;
	Node<T>* next;

public:
//shai

	Node(const T newData)
	{
		this->data = new T (newData);
		this->next = nullptr;
	}

	~Node()
	{
		delete this->data;
	}


	Node getNext()
	{
		return this->next;
	}

	void setNext(Node nextNode)
	{
		this->next = nextNode;
	}

	T getData()
	{
		return new T(this->data);
	}
};
//~shai

template<class T>
class Iterator{
	Node<T>* current;

public:
//shaked
	Iterator<T>& operator++();
	Iterator<T>& operator++(int);

	T operator*(); //
// ~shaked
// shai
	//TODO this
	bool operator==(const Iterator<T>& other);
	bool operator!=(const Iterator<T>& other);
	Iterator<T>& operator=(Iterator<T>& other);

	Iterator(Node* pointedNode)
	{
		this->current = pointedNode;
	}

//~shai
};

template<class T>
class List{
	friend class Node;
	Node<T>* first;
	int size;

public:
//shai
	List()
	{
		Node(nullptr);
		this->first = &Node;
		this->size = 0;
	}

	~List()
	{
		Node* current = this->first;
		Node* nextNode = nullptr;
		while (&current->next != nullptr){ //why isn't there a next here?
			nextNode = &current->next; //same
			delete current;
			Node* current = nextNode;
		}
	}
//~shai
//shaked
	Iterator<T> begin();
	Iterator<T> end();
	void insert(const T& data, Iterator<T> iterator);
	void remove(Iterator<T> iterator);
//~shaked
//shai
	Iterator<T> find (const Predicate& predicate); //TODO this
	void sort (const Comapre& comparer); //TODO this

	int getSize()
	{
		return this->size;
	}
//~shai

};

//predicate and compare need to be created in the cpp file where they are used.
//should we fix the way compare is spelled? i used the way he wrote in the exercise file because i dont want us to loose sync with external files


#endif /* LIST_H_ */
