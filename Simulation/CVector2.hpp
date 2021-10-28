#include <string.h>
#include <math.h>


#include <iostream>

#ifndef __CVector2__
#define __CVector2__

class CVector2 {

   public:

      float x, y;

      CVector2   (const CVector2 &a) {   x = a.x; y = a.y; }
      CVector2   (double a, double b) {x = a; y = b;}
      CVector2   () {;}

      friend double   operator * (const CVector2 &a, const CVector2 &b) {
         return a.x * b.x + a.y * b.y;
      }


      friend CVector2 operator + (const CVector2 &a, const CVector2 &b) { return CVector2 (a.x+b.x, a.y+b.y); }
      friend CVector2 operator - (const CVector2 &a, const CVector2 &b) { return CVector2 (a.x-b.x, a.y-b.y); }
      friend CVector2 operator - (const CVector2 &a)                    { return CVector2 (-a.x, -a.y); }
      friend CVector2 operator * (const CVector2 &a, const double n)    { return CVector2 (a.x * n, a.y * n); }

      CVector2& operator=(const CVector2&);
      CVector2& operator=(const char *);

      double length () { return sqrt (x*x + y*y);}

      void normalise (void) { double n = length(); x /= n; y /= n;};

      void rotate (double beta) {

         double l = length();

         double alpha = atan2 (y,x);

         x = l * cos (alpha + beta);
         y = l * sin (alpha + beta);
      }

      void rotate (int beta) {

         rotate (beta * 0.0174533);
      }

      void print   () { std::cout << x << "," << y; }
      void println () { std::cout << x << "," << y << "\n"; }

};

#endif
