//----------------------------------------------------
//  Exemplo
//    ./a.out valor1=12.34 arq=/tmp/teste.dat flag3
//    12.34 = atof (arg2str("valor1"))
//    (NULL != arg2str ("flag3"))
//----------------------------------------------------
char *arg2str (char *argv[], const char *nome) {

   static char buffer[512];

   int n = strlen (nome);

   int k = 0;

   while (argv[k]) {
      if (!strncmp (nome, argv[k], n)) {
         if ('=' == *(argv[k] + n))
            strcpy (buffer, argv[k] + n + 1);
         return buffer;
      }
      ++k;
   }
   return NULL;
}
