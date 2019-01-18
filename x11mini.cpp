#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xos.h>
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 



int main (int argc, char** argv) {
   
   char    str[200];
 
   // *display = conexão com X11
   Display *display = XOpenDisplay(NULL);
   
   if (display == NULL) {
     puts ("Falha com display");
     exit (1);
   }
 
   // screen = "tela".
   int screen = DefaultScreen (display);
   
   // Abra Janela.   
   Window win = XCreateSimpleWindow (display, RootWindow(display, screen), 10, 10, 660, 200, 1,
                                    BlackPixel(display, screen), WhitePixel(display, screen));
   
   // Título
   XStoreName   (display, win, "Janela X11 em Linux");

   // Avise X11 q vc quer receber certos dados.
   XSelectInput (display, win, ExposureMask | KeyPressMask);
   
   // Mostrar Janela   (XUnmapWindow esconde).
   XMapWindow   (display, win);
 
   // Avise X11 que se usuário clicar para fechar janela,
   //   este programa irá tratar isso.
   // Sem as 2 linhas a seguir, o mouse fecha a janela mas causa erro.
   Atom WM_DELETE_WINDOW = XInternAtom(display, "WM_DELETE_WINDOW", False); 
   XSetWMProtocols(display, win, &WM_DELETE_WINDOW, 1);  
    
   while (1) {
     
      XEvent e;
      XNextEvent (display, &e);
    
      if (e.type == KeyPress)  {
        char buf[128] = "";
        KeySym keysym;
        int len = XLookupString(&e.xkey, buf, sizeof buf, &keysym, NULL);
        if (keysym == XK_Escape)
           break;
      }
 
      // mouse clicado p fechar janela
      if ((e.type == ClientMessage) && ((int)(e.xclient.data.l[0]) == WM_DELETE_WINDOW))
         break;
       
      // hora de mostrar coisas na tela
      if (e.type == Expose) {
 
         XWindowAttributes  wa;
         XGetWindowAttributes (display, win, &wa);

         strcpy      (str, "Teste de X11 em Linux");
         XDrawString (display, win, DefaultGC(display, screen), 10, 20, str, strlen (str));

         sprintf     (str, "Tamanho da janela: %dx%d", wa.width, wa.height);
         XDrawString (display, win, DefaultGC(display, screen), 10, 40, str, strlen (str));
       
         XFillRectangle(display, win, DefaultGC(display, screen), 20, 20, 10, 10); 
      }
   }
 
   XDestroyWindow (display, win);
   XCloseDisplay  (display);
   
   return 0;
}