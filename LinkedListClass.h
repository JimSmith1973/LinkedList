// LinkedListClass.h

#pragma once

#include <windows.h>
#include <stdio.h>

typedef class Node
{
public:
	Node( LPARAM lIdentifier, int nValue );

public:
	LPARAM m_lIdentifier;
	int m_nData;
	Node *m_lpNextNode;

} NODE, *LPNODE; // End of class Node

class LinkedList
{
public:
	LinkedList();

	~LinkedList();

	void AddNode( int value );

	void DeleteNode( LPARAM lIdentifier );

	void Display();

	LPNODE GetNode( LPARAM lIdentifier );

	int Integer( LPARAM lIdentifier );

private:
	Node* m_lpHeadNode;
	LPARAM m_lNextIdentifier;

}; // End of class LinkedList
