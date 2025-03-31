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
	printf( "Linked List: " );
	list.Display();

	// Delete node from list
	list.DeleteNodeWithValue(20);

	// Display list
	printf( "After Deleting 20: " );
	list.Display();

	return 0;

} // End of function main
