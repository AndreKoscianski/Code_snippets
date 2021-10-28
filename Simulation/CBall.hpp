
#include "CVector2.hpp"

#ifndef __BALL__
#define __BALL__

class CBall {

   // Why everything public?
   // - this is a one-person code,
   // - there's no programming by contract, 
   //   neither interface standardization among members of a team;
   // - did you really asked that? How boring.

   public:

   double m,r;

   CVector2 p;
   CVector2 v;
   CVector2 a;

   CBall () {v.x = v.y = r = 0;}

   CBall (double a, double b, double c) {p.x=a; p.y=b; r=c; v.x = v.y = 0;}

   void run (double dt) {
      // Implicit Euler
      v = v + (a * dt);
      p = p + (v * dt);
   }

   //---------------------------------------------------------
   // Collision with a line
   //---------------------------------------------------------
   bool collided (double x1, double y1, double x2, double y2) {

      // Translation to origin
      CVector2 L (x2-x1, y2-y1);

      L.normalise ();

      CVector2 P = p - CVector2 (x1, y1);

      // Compute projection and translate back.
      CVector2 R = (P * (P*L)) + CVector2 (x1, y1);

      return R.length() < r;
   }      


   //---------------------------------------------------------
   // Collision with a line
   //---------------------------------------------------------
   double when_collide (double x3, double y3, double x4, double y4) {

      double x1,x2,y1,y2;

      x1 = p.x; x2 = p.x+v.x;
      y1 = p.y; y2 = p.y+v.y;

      double d = (x1-x2)*(y3-y4) - (y1-y2)*(x3-x4);

      if (fabs(d) < 1e-5) return -1;

      double a = (x1*y2 - y1*x2);
      double b = (x3*y4 - y3*x4);

      CVector2 w ((a*(x3-x4) - b*(x1-x2)) / d, (a*(y3-y4) - b*(y1-y2)) / d);

      return ((w - p).length() - r) / v.length();    
   }

   //---------------------------------------------------------
   // Collision with another Ball
   //---------------------------------------------------------
   bool collided (CBall &B) {

      return (B.p - p).length() < (B.r + r);
   }      

   //---------------------------------------------------------
   // Collision with another Ball
   //---------------------------------------------------------
   double when_collide (CBall &B) {

      // https://stackoverflow.com/questions/11369616/circle-circle-collision-prediction

      double npx = p.x - B.p.x;
      double npy = p.y - B.p.y;
      double nvx = v.x - B.v.x;
      double nvy = v.y - B.v.y;

      double a2 = 2.0 * (nvx*nvx + nvy*nvy);

      double b  = 2.0 * (npx*nvx + npy*nvy);

      double c  = npx*npx + npy*npy - ((r + B.r)*(r + B.r));

      if ((fabs(a) > 1e-5) && (b*b >= 2.0*a2*c)) {

         double del = sqrt(b*b - 2.0*a2*c);
         double s1  = (-b + del) / a;
         double s2  = (-b - del) / a;

         return (s1 < s2) ? s1 : s2;

      } else
         return -1;
   }

};

#endif
