#pragma once

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <map>
#include <string>


/*-----------------------------------------------

# Example file
# Comments

key = value

ANumber = 123
Another_Number = 12.3
AString = Look at that!
ABoolean = TRUE

file {
 ./a directory/fileA.png
 ./a directory/fileB.png
 ./a directory/fileC.png
}

-----------------------------------------------

   CConfigFile config;

   config.read_file (argv[1]);

   bool   b = config.getb ("ABoolean");
   int    i = config.geti ("ANumber");
   double n = config.getd ("Another_Number");

   std::string s, s2;

   s  = config.gets ("AString");
   s2 = config.gets ("File2");

----------------------------------------------- */

class CConfigFile {
   public:

    std::map<std::string,std::string> _map;

    bool has (std::string s) {
       auto it = _map.find (s.c_str());

       return (it != _map.end());
    }

    void read_file (const char *filename) {

      std::ifstream thefile;

      thefile.open (filename);


      if (!thefile.is_open()) {
        std::cout << "\nCannot open file\n <" << filename << ">\n";
        exit (0);
      }

      std::string parm_name, parm_equal , parm_val;

      while (thefile >> parm_name ) {

         if ((parm_name[0] == '#') || (parm_name == "#") || (parm_name == "//")) {
            std::getline (thefile, parm_val);
            continue;
         }

         thefile >> parm_equal;

         if (parm_equal == "=") {
           thefile >> parm_val;
           _map.insert (std::pair<std::string,std::string>(parm_name,parm_val));
           //std::cout << parm_name << " = " << parm_val << "\n";
         }

         if (parm_equal == "{") {
            std::getline (thefile, parm_val);
            int k = 0;
            do {
               std::getline (thefile, parm_val);
               if (parm_val == "}")
                  break;

               _map.insert (std::pair<std::string,std::string>
                             (parm_name+std::to_string(k++), parm_val)
                            );

               //std::cout << parm_val << std::endl;
            } while (parm_val != "}");
         }
      }

      //thefile << "Writing this to a file.\n";

      thefile.close();

      // list content:
    //  for (std::map<std::string,std::string>::iterator it = _map.begin();
    //       it != _map.end();
    //       ++it)
    //    std::cout << it->first << " => " << it->second << '\n';
    }


    const char *gets (const char *key) {

       auto it = _map.find (key);

       if (it == _map.end()) return "";

       return (const char *) ((it->second).c_str());

    }


    bool getb (const char *key) {

       auto it = _map.find (key);

       if (it == _map.end()) return false;

       return ((it->second) == "YES") || ((it->second) == "TRUE");

    }

    double getd (const char *key) {

       auto it = _map.find (key);

       if (it == _map.end()) return 0;

       return strtod ((const char *) ((it->second).c_str()), NULL);
    }


    int geti (const char *key) {

       auto it = _map.find (key);

       if (it == _map.end()) return 0;

       return atoi ((const char *) (it->second).c_str());
    }

};

