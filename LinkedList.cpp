// LinkedList.cpp

#include "LinkedList.h"

int main()
{
	LinkedList list;

	// Add nodes to list
	list.AddNode( 10 );
	list.AddNode( 20 );
	list.AddNode( 30 );

	// Display list
	list.Display();

	// Delete node from list
	list.DeleteNode( 2 );

	// Display list
	printf( "\r\nAfter Deleting Node: \r\n\r\n" );
	list.Display();

	return 0;

} // End of function main
