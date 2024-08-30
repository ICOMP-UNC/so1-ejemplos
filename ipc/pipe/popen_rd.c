#include <stdio.h>

#define PATH_MAX 70

/* Using popen() with ls Utility */
int main ()
{
    FILE *fp;
    int status;
    char path[PATH_MAX];

    /* Open a read-only pipe stream from command ls*/
    fp = popen("ls *", "r");
    if (fp == NULL) {
        /* Handle error */;
    }

    printf("CWD Content:\n");
    while (fgets(path, PATH_MAX, fp) != NULL) {
        printf("- %s", path);
    }

    status = pclose(fp);
    if (status == -1) {
        /* Error reported by pclose() */
    } 
    else {
        /* Use macros described under wait() to inspect `status' in
        order to determine success/failure of command executed by popen() */
    }
}
