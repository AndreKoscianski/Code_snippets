
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <signal.h>


void tratar (char *s) {

   FILE *arq;

   if (!isdigit (*s)) return;

   char s2[500];

   char s_aux[200];
   long long int  i_aux;
   char c_aux;
   int  pid;
   
   sprintf (s2, "/proc/%s/stat", s);

   pid = atoi (s);
   
   arq =  fopen (s2, "rt");
   fgets  (s2, 490, arq);
   fclose (arq);
   
   sscanf (s2, "%lld %s %c", &i_aux, s_aux, &c_aux);
   
   if ('Z' == c_aux) {      
      arq = fopen ("log", "a+"); 
      fprintf (arq, "find %d \n", pid);
      fclose (arq);

      waitpid (pid, NULL, 0);

   }
   
}



void hunt () {
   
   struct dirent **namelist;

   int n;

   n = scandir ("/proc", &namelist, 0, alphasort);

   while (n--)
      tratar (namelist[n]->d_name);      
}




int main () {

   pid_t pid = 0;
   pid_t sid = 0;

   pid = fork();

   if (pid < 0) { puts ("nao funcionou"); exit(1);}
   if (pid > 0) { printf ("Daemon ID = %d\n", pid); exit(0);}

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

   FILE *arq = fopen ("log", "a+");
   fprintf (arq, "started \n");
   fclose (arq);

   while (1) {
      sleep (10);
      hunt  ();
   }

   return 0;

}
