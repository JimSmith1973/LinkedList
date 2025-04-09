// LinkedListClass.cpp

#include "LinkedListClass.h"

int Node::GetData()
{
	// Get data
	return m_nData;

} // End of function Node::GetData

LPARAM Node::GetIdentifier()
{
	// Get identifier
	return m_lIdentifier;

} // End of function Node::GetIdentifier

LPNODE Node::GetNextNode()
{
	// Get next node
	return m_lpNextNode;

} // End of function Node::GetNextNode

Node::Node( LPARAM lIdentifier, int nValue )
{
	m_lIdentifier	= lIdentifier;
	m_nData			= nValue;
	m_lpNextNode	= NULL;

} // End of function Node::Node

void Node::SetNextNode( Node *lpNextNode )
{
	// Set next node
	m_lpNextNode = lpNextNode;

} // End of function Node::SetNextNode

LinkedList::LinkedList()
{
	// Clear head node
	m_lpHeadNode = NULL;

	// Initialise next identifier value
	m_lNextIdentifier = 0;

} // End of function LinkedList::LinkedList

LinkedList::~LinkedList()
{
	LPNODE lpWhichNode;

	// Loop while head node exists
	while( m_lpHeadNode )
	{
		// Store head node
		lpWhichNode = m_lpHeadNode;

		// Advance head node to next
		m_lpHeadNode = m_lpHeadNode->GetNextNode();

		// Delete stored head node
		delete lpWhichNode;

	}; // End of loop while head node exists

} // End of function LinkedList::~LinkedList

void LinkedList::AddNode( int value )
{
	// Create new node
	Node* lpNewNode = new Node( m_lNextIdentifier, value );

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
		LPNODE lpWhichNode = m_lpHeadNode;

		// Loop through all nodes
		while( lpWhichNode->GetNextNode() != NULL )
		{
			// Get next node
			lpWhichNode = lpWhichNode->GetNextNode();

		}; // End of loop through all nodes

		// Add new node to end of list
		lpWhichNode->SetNextNode( lpNewNode );

	} // End of list is not empty

	// Undate next identifier
	m_lNextIdentifier ++;

} // End of function LinkedList::AddNode

void LinkedList::DeleteNode( LPARAM lIdentifier )
{
	// Note that we can't just 'get' the node and delete it, as we need to update the previous node
	// to avoid the deleted one

	// Ensure that list is not empty
	if( m_lpHeadNode )
	{
		// List is not empty

		// See if head node has the required identifier
		if( m_lpHeadNode->GetIdentifier() == lIdentifier )
		{
			// Head node has the required identifier

			// Copy head node into temporary
			LPNODE lpTempNode = m_lpHeadNode;

			// Move head node to next item
			m_lpHeadNode = m_lpHeadNode->GetNextNode();

			// Free memory
			delete lpTempNode;

		} // End of head node has the required identifier
		else
		{
			// Head node does not have the required identifier

			// Copy head node into temporary
			LPNODE lpTempNode = m_lpHeadNode;

			// Find node to delete
			while( lpTempNode->GetNextNode() && lpTempNode->GetNextNode()->GetIdentifier() != lIdentifier )
			{
				// Get next node
				lpTempNode = lpTempNode->GetNextNode();

			}; // End of loop to find node to delete

			// Note that temp node is the node before the one to delete

			// Ensure that node to delete was found
			if( lpTempNode->GetNextNode() )
			{
				// Successfully found node to delete

				// Store node to delete
				LPNODE lpNodeToDelete = lpTempNode->GetNextNode();

				// Unlink node
				lpTempNode->SetNextNode( lpTempNode->GetNextNode()->GetNextNode() );

				// Free memory of deleted node
				delete lpNodeToDelete;

			} // End of successfully found node to delete

		} // End of head node does not have the required identifier

	} // End of list is not empty

} // End of function LinkedList::DeleteNode

void LinkedList::Display()
{
	// Get first node
	LPNODE lpWhichNode = m_lpHeadNode;

	// Identify start of linked list
	printf( "Start of Linked List:\r\n" );

	// Loop through all nodes
	while( lpWhichNode != NULL )
	{
		// Print node
		printf( "Node %lld, data %d\r\n", lpWhichNode->GetIdentifier(), lpWhichNode->GetData() );

		// Get next node
		lpWhichNode = lpWhichNode->GetNextNode();

	} // End of loop through all nodes

	// Print last node
	printf( "NULL\r\n" );

	// Identify end of linked list
	printf( "End of Linked List.\r\n" );

} // End of function LinkedList::Display

LPNODE LinkedList::GetNode( LPARAM lIdentifier )
{
	LPNODE lpNode = NULL;

	// Get first node
	LPNODE lpWhichNode = m_lpHeadNode;

	// Loop through all nodes
	while( lpWhichNode )
	{
		// See if this is the required node
		if( lpWhichNode->GetIdentifier() == lIdentifier )
		{
			// This is the required node

			// Update return value
			lpNode = lpWhichNode;

			// Force exit from loop
			lpWhichNode = NULL;

		} // End of this is the required node
		else
		{
			// This is not the required node

			// Get next node
			lpWhichNode = lpWhichNode->GetNextNode();

		} // End of this is not the required node

	}; // End of loop through all nodes

	return lpNode;

} // End of function LinkedList::GetNode

int LinkedList::Integer( LPARAM lIdentifier )
{
	int nResult = 0;

	LPNODE lpNode;

	// Get node
	lpNode = GetNode( lIdentifier );

	// Ensure that node was goto
	if( lpNode )
	{
		// Successfully got node

		// Update return value
		nResult = lpNode->GetData();

	} // End of successfully got node

	return nResult;

} // End of function LinkedList::Integer
