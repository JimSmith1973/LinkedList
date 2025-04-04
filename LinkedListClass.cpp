// LinkedListClass.cpp

#include "LinkedListClass.h"

Node::Node( int nValue )
{
	m_nData			= nValue;
	m_lpNextNode	= NULL;

} // End of function Node::Node

LinkedList::LinkedList()
{
	// Clear head node
	m_lpHeadNode = NULL;

} // End of function LinkedList::LinkedList

LinkedList::~LinkedList()
{
	Node *lpWhichNode;

	// Loop while head node exists
	while( m_lpHeadNode )
	{
		// Store head node
		lpWhichNode = m_lpHeadNode;

		// Advance head node to next
		m_lpHeadNode = m_lpHeadNode->m_lpNextNode;

		// Delete stored head node
		delete lpWhichNode;

	}; // End of loop while head node exists

} // End of function LinkedList::~LinkedList

void LinkedList::AddNode( int value )
{
	// Create new node
	Node* lpNewNode = new Node( value );

	// See if list is empty
	if( m_lpHeadNode == NULL )
	{
		// List is empty

		// Add new node at head of list
		m_lpHeadNode = lpNewNode;

	} // End of list is empty
	else
	{
		// List is not empty

		// Get first node
		Node *lpWhichNode = m_lpHeadNode;

		// Loop through all nodes
		while( lpWhichNode->m_lpNextNode != NULL )
		{
			// Get next node
			lpWhichNode = lpWhichNode->m_lpNextNode;

		}; // End of loop through all nodes

		// Add new node to end of list
		lpWhichNode->m_lpNextNode = lpNewNode;

	} // End of list is not empty

} // End of finction LinkedList::AddNode

void LinkedList::DeleteNodeWithValue( int value )
{
	// Ensure that list is not empty
	if( m_lpHeadNode )
	{
		// List is not empty

		// See if head node has the required value
		if( m_lpHeadNode->m_nData == value )
		{
			// Head node has the required value

			// Store head node
			Node *lpWhichNode = m_lpHeadNode;

			// Move head to next node
			m_lpHeadNode = m_lpHeadNode->m_lpNextNode;

			// Delete stored head node
			delete lpWhichNode;

		} // End of head node has the required value
		else
		{
			// Head node does not have the required value

			// Get first node
			Node *lpWhichNode = m_lpHeadNode;

			// Loop through all nodes
			while( lpWhichNode->m_lpNextNode && lpWhichNode->m_lpNextNode->m_nData != value )
			{
				// Get next node
				lpWhichNode = lpWhichNode->m_lpNextNode;

			}; // End of loop through all nodes

			// Ensure that next node is valid
			if( lpWhichNode->m_lpNextNode )
			{
				// Next node is valid

				// Store node to delete
				Node *lpNodeToDelete = lpWhichNode->m_lpNextNode;

				// Unlink node
				lpWhichNode->m_lpNextNode = lpWhichNode->m_lpNextNode->m_lpNextNode;

				// Delete node
				delete lpNodeToDelete ;

			} // End of next node is valid

		} // End of head node does not have the required value

	} // End of list is not empty

} // End of function LinkedList::DeleteNodeWithValue

void LinkedList::Display()
{
	// Get first node
	Node *lpWhichNode = m_lpHeadNode;

	// Loop through all nodes
	while( lpWhichNode != NULL )
	{
		// Print node
		printf( "%d->", lpWhichNode->m_nData );

		// Get next node
		lpWhichNode = lpWhichNode->m_lpNextNode;

	} // End of loop through all nodes

	// Print last node
	printf( "NULL\r\n" );

} // End of function LinkedList::Display

