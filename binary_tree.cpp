#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

struct treeNode 
{ 
   struct treeNode *leftPtr;
   int data;
   struct treeNode *rightPtr;
};

typedef struct treeNode TreeNode;
typedef TreeNode *TreeNodePtr;

void insertNode( TreeNodePtr *, int );
bool binaryTreeSearch(TreeNodePtr , int ); 
void inOrder( TreeNodePtr );
void preOrder( TreeNodePtr );
void postOrder( TreeNodePtr );
TreeNodePtr getNewNode(int value );

int main()
{ 
   int i, item;
   TreeNodePtr rootPtr = NULL;

   srand( time( NULL ) );

   /* insert random values between 1 and 15 in the tree */
   cout << "The numbers being placed in the tree are:\n" ;

   for ( i = 1; i <= 10; i++ ) 
   { 
      item = rand() % 100;
      cout <<  " " << item ;
      insertNode( &rootPtr, item );
   }

   /* traverse the tree preOrder */
   cout << "\n\nThe preOrder traversal is:\n" ;
   preOrder( rootPtr );

   /* traverse the tree inOrder */
   cout << "\n\nThe inOrder traversal is:\n" ;
   inOrder( rootPtr );

   /* traverse the tree postOrder */
   cout << "\n\nThe postOrder traversal is:\n" ;
   postOrder( rootPtr );

   cout << "\n\nSearch for a tree node? ";
   cin >> i;
   while (i!=100)
   {
      cout << "\n" << (binaryTreeSearch(rootPtr, i )? "Found": "Not Found" );
      cout << "\n\nSearch for a tree node? ";
      cin >> i;
    } 
   return 0;
}

void insertNode( TreeNodePtr *treePtr, int value )
{ 
   if ( *treePtr == NULL )    /* Sucessfuly get a new node*/
         *treePtr= getNewNode( value);
	  else if ( value < ( *treePtr )->data )
         insertNode( &( ( *treePtr )->leftPtr ), value );
      else if ( value > ( *treePtr )->data )
         insertNode( &( ( *treePtr )->rightPtr ), value );
      else 
         cout << "\nDuplicated Value " << value <<" not inserted\n";
}

bool binaryTreeSearch(TreeNodePtr rootPtr, int value)
{
	TreeNodePtr currentPtr = rootPtr;
    while (currentPtr != NULL) 
	{
		if (value == currentPtr->data)
			return true;
	    else if (value < currentPtr->data)                      
            currentPtr = currentPtr->leftPtr;
        else 
            currentPtr = currentPtr->rightPtr;
    }
    return false;
}

void inOrder( TreeNodePtr treePtr )
{ 
   if ( treePtr != NULL ) { 
      inOrder( treePtr->leftPtr );
      cout << " " << treePtr->data ;
      inOrder( treePtr->rightPtr );
   }
}

void preOrder( TreeNodePtr treePtr )
{ 
   if ( treePtr != NULL ) { 
      cout << " " << treePtr->data ;
      preOrder( treePtr->leftPtr );
      preOrder( treePtr->rightPtr );
   }
}

void postOrder( TreeNodePtr treePtr )
{ 
   if ( treePtr != NULL ) { 
      postOrder( treePtr->leftPtr );
      postOrder( treePtr->rightPtr );
      cout << " " << treePtr->data ;
   }
}

TreeNodePtr getNewNode(int value )
{
      TreeNodePtr newPtr = (TreeNodePtr) new (TreeNode);
      if ( newPtr != NULL ) {     /* is space available */
      newPtr->data = value;
      newPtr->leftPtr = NULL;
      newPtr->rightPtr = NULL;
      } 
	  return newPtr;
}
