/*
  Here is an example of the proper way to free all
  the blocks in a chain, and the strings that they point to.

  source:
  https://www.gnu.org/software/libc/manual/html_node/Malloc-Examples.html
  source: https://www.gnu.org/software/libc/manual/html_node/Freeing-after-Malloc.html
*/
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>

/*
subroutine that calls malloc and reports an error if the value
is a null pointer, returning only if the value is nonzero.
This function is conventionally called xmalloc. 
*/
void *
xmalloc (size_t size)
{
  void *addr = malloc (size);
  if (addr == 0) {
    // fatal ("virtual memory exhausted");
    fprintf(stderr, "malloc failed: %s\n", strerror(errno));
  }

  return addr;
}

/*
The function savestring will copy a sequence of characters
into a newly allocated null-terminated string
*/
char *
savestring (const char *ptr, size_t len)
{
  char *addr = (char *) xmalloc (len + 1);
  addr[len] = '\0';
  
  return (char *) memcpy (addr, ptr, len);
}

struct chain
{
  struct chain *next;
  char *name;
};

void
print_chain (struct chain *chain)
{
  while (chain != 0) {
    struct chain *next = chain->next;
    printf("%s\n", chain->name);
    chain = chain->next;
  }
}

void
free_chain (struct chain *chain)
{
  while (chain != 0) {
      struct chain *next = chain->next;
      free (chain->name);
      free (chain);
      chain = next;
    }
}

int 
main()
{
  /* Normally you would cast the value as a pointer to the kind of object
     that you want to store in the block.
  */
  struct chain * c = (struct chain *) xmalloc(sizeof(struct chain));
  struct chain * c1 = (struct chain *) xmalloc(sizeof(struct chain));

  /* initializing the space with zeros */
  memset (c, 0, sizeof (struct chain));
  memset (c1, 0, sizeof (struct chain));

  /*link nodes*/  
  c->next = c1;

  char local_name_1[] = "mynode-1";
  char local_name_2[] = "mynode-2";

  c->name = savestring(local_name_1, strlen(local_name_1));
  c1->name = savestring(local_name_2, strlen(local_name_2));

  print_chain(c);
  free_chain(c);

  // don't access object after free()
  // print_chain(c);
}
