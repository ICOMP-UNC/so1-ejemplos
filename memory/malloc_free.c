#include <stdlib.h>

typedef struct 
{
    int field1;
    char* field2;
} SomeStruct;


void do_stuff(SomeStruct * somestruct)
{
    // do something with SomeStruct
}

/*
 how a C program might allocate, use, and later free
 a structure on the heap
*/
int main()
{
    SomeStruct* myObject = (SomeStruct*) malloc (sizeof(SomeStruct));
    
    if(myObject != NULL)
    {
        myObject->field1 = 1234;
        myObject->field2 = "Hello World!";
        
        do_stuff(myObject);
        
        free (myObject);
    }
    
    return 0;
}
