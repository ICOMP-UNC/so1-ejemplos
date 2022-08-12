#include <sys/types.h>
#include <unistd.h>
#include <malloc.h>
#include <stdlib.h>

void *dummy_malloc(size_t size)
{
	void *p;
	p = sbrk (0); 
	/* If sbrk fails , we return NULL */
	if (sbrk(size) == (void*)-1)  
		return NULL;
	
	return p;
}

int
main()
{
  printf("Initial\n");
	
	void * p = dummy_malloc(100000);
	if (p == NULL) {
       perror("malloc");
       exit(EXIT_FAILURE);
    }

    printf("After malloc\n");
}
