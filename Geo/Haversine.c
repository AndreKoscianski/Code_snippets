#include <math.h>
#include <stdio.h>

#define radians(x) (x*M_PI/180.0)

double Haversine (double lat1, double lon1, 
                  double lat2, double lon2) {

   double a = 
      powl (sin (radians ((lat2-lat1)) / 2.0) , 2.0) 
      +
      cos (radians (lat1)) * 
      cos (radians (lat2)) * 
      powl (sin (radians ((lon2-lon1)) / 2.0) , 2.0); 

   return 6371.0 * 2.0 * atan2 (sqrt (a), sqrt (1.0 - a)); 
}


int main () {

   return printf ("%lf\n", 
      Haversine (-23.421, -51.9331, -25.0994, -50.1383));
}
