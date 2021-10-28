
#include <vector>
#include <string>
#include <string.h>

const std::vector<std::string> explode (const std::string &str, const char c) {

   std::vector<std::string> v;

   char sep[] = "," ;

   sep[0] = c;

   char *pch = strtok ((char *) str.c_str () ,  sep);

   while (pch != NULL) {
      v.push_back (std::string (pch));
      pch = strtok (NULL, sep);
   }

   return v;
}   


std::vector<std::vector<double>> readCSV (char *filename, char sep, int &nrow, int &ncol) {

   std::vector<std::vector<double>> M;
    
   FILE *arq = fopen(filename, "r");

   if (NULL == arq)
      return M;

   char buf[500];

   while (fgets (buf, sizeof(buf), arq)) {

      std::vector<std::string> res = explode (buf, sep);

      std::vector<double> v;

      for (auto word : res)
         v.push_back (std::stod (word, NULL));
      
      M.push_back (v);

   }

   fclose (arq);

   nrow = M.size();
   ncol = M[0].size();

   return M;

}


void writeCSV (char *filename, char sep, std::vector<std::vector<double>> M, int nrow, int ncol) {
    
   std::string s;

   FILE *arq = fopen(filename, "w");

   if (NULL == arq)
      return;

   char buf[500];

   for (auto r : M) {

      s = "";

      for (int c = 0; c < ncol; ++c) {

         s = s + std::to_string (r[c]);

         if (c < ncol) s = s + std::to_string(sep);
      }

      fputs (s.c_str(), arq);
   } 

   fclose (arq);

}


