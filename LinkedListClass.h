// LinkedListClass.h

#pragma once

#include <windows.h>
#include <stdio.h>

typedef class Node
{
public:
	int GetData();

	LPARAM GetIdentifier();

	Node *GetNextNode();

	Node( LPARAM lIdentifier, int nValue );

	void SetNextNode( Node *lpNextNode );

public:

private:
	LPARAM m_lIdentifier;
	Node *m_lpNextNode;
	int m_nData;

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
