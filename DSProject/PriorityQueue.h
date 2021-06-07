#ifndef PRIORITY_QUEUE_
#define PRIORITY_QUEUE_

#include "PQNode.h"
#include <vector>
using namespace std;

template <typename T>
class PriorityQueue
{
private:

	PQNode<T>* backPtr;
	PQNode<T>* frontPtr;
public:
	PriorityQueue();
	bool isEmpty() const;
    void enqueue(const T& newEntry, const int& significance);
	bool dequeue(T& frntEntry);
	~PriorityQueue();

	//copy constructor
	PriorityQueue(const PriorityQueue<T>& PQ);
};

template <typename T>
PriorityQueue<T>::PriorityQueue()
{
	backPtr=nullptr;
	frontPtr=nullptr;

}

template <typename T>
bool PriorityQueue<T>::isEmpty() const
{
	return (frontPtr == nullptr);
}

template <typename T>
void PriorityQueue<T>::enqueue(const T& i, const int& p) 
{
	PQNode<T>* t;
	PQNode<T>* q;
	t = new PQNode<T>(i, p);
    if (frontPtr == nullptr || p > frontPtr->getPriority())
    {
		t->setNext(frontPtr);
        frontPtr = t;
    }
    else
    {
        q = frontPtr;
        while (q->getNext() != nullptr && q->getNext()->getPriority() >= p)
            q = q->getNext();
		t->setNext(q->getNext());
		q->setNext(t);
    }
}  

template <typename T>
bool PriorityQueue<T>::dequeue(T& frntEntry)
{
	if (isEmpty())
		return false;

	PQNode<T>* nodeToDeletePtr = frontPtr;
	frntEntry = frontPtr->getItem();
	frontPtr = frontPtr->getNext();
	// Queue is not empty; remove front
	if (nodeToDeletePtr == backPtr)	 // Special case: last node in the queue
		backPtr = nullptr;

	// Free memory reserved for the dequeued node
	delete nodeToDeletePtr;

	return true;
}

template <typename T>
PriorityQueue<T>::~PriorityQueue()
{
	T temp;

	//Free (Dequeue) all nodes in the queue
	while (dequeue(temp));
}

template <typename T>
PriorityQueue<T>::PriorityQueue(const PriorityQueue<T>& PQ)
{
	PQNode<T>* NodePtr = PQ.frontPtr;
	if (!NodePtr) //PQ is empty
	{
		frontPtr = backPtr = nullptr;
		return;
	}

	//insert the first node
	PQNode<T>* ptr = new PQNode<T>(NodePtr->getItem());
	frontPtr = backPtr = ptr;
	NodePtr = NodePtr->getNext();

	//insert remaining nodes
	while (NodePtr)
	{
		PQNode<T>* ptr = new PQNode<T>(NodePtr->getItem());
		backPtr->setNext(ptr);
		backPtr = ptr;
		NodePtr = NodePtr->getNext();
	}
}

#endif