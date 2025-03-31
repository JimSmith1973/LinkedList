// LinkedListClass.h

#pragma once

#include <windows.h>
#include <stdio.h>

class Node
{
public:
	Node( int nValue );

	int m_nData;
	Node *m_lpNextNode;

}; // End of class Node

class LinkedList
{
public:
	LinkedList();

	~LinkedList();

	void AddNode( int value );

	void DeleteNodeWithValue( int value );

	void Display();

private:
	Node* m_lpHeadNode;

}; // End of class LinkedList
