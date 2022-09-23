/*
During  execution  of  the command, SIGCHLD will be blocked, and SIGINT
and SIGQUIT will be  ignored,  in  the  process  that  calls  system().
(These  signals  will be handled according to their defaults inside the
child process that executes command.)

As  mentioned, system() ignores SIGINT and SIGQUIT.  This may make pro‐
grams that call it from a loop uninterruptible, unless they  take  care
themselves to check the exit status of the child.

For example:
*/

int main (argc, argv)
{    
   while (something) {
       int ret = system("foo");

       if (WIFSIGNALED(ret) &&
           (WTERMSIG(ret) == SIGINT || WTERMSIG(ret) == SIGQUIT))
               break;
   }
}
