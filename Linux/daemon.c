
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

int main () {

   pid_t pid = 0;
   pid_t sid = 0;

   pid = fork();

   if (pid < 0) { puts ("nao funcionou"); exit(1);}
   if (pid > 0) { printf ("Child ID = %d\n", pid); exit(0);}

   //umask(0);

   sid = setsid();

   if (sid < 0) { puts ("sid erro"); exit (1);}

   printf ("SID  = %d\n", sid);
   printf ("PID  = %d\n", getpid());
   printf ("PPID = %d\n", getppid());

   //chdir ("/");

   puts ("Daemon alive!");

   close (STDIN_FILENO);
   close (STDOUT_FILENO);
   close (STDERR_FILENO);

   while (1)
      sleep (20);

   return 0;

}
