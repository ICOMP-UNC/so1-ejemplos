/*
*  Creating a copy-on-write mapped data file with the shmat subroutine
*/

#include <sys/shm.h>

if( ( fildes = open( filename , 2 ) ) < 0 )
{
      printf( "cannot open file\n" );
      exit(1);
}

// Map the file to a segment as copy-on-write, with the shmat subroutine: 
// The SHM_COPY constant is defined in the /usr/include/sys/shm.h file.
// This constant indicates that the file is a copy-on-write mapped file.
// Include this header file and other shared memory header files in a program with the following directives:
file_ptr = shmat( fildes, 0, SHM_COPY );

// Use file_ptr as a pointer to the start of the data file, and access the data as if it were in memory.
while ( file_ptr < eof)
{
      // .
      // .
      // .
      // (references to file using file_ptr)
}

// Use the fsync subroutine to write changes to the copy of the file on disk to save the changes:
fsync( fildes );

// Close the file when the program is finished working with it:
close( fildes );