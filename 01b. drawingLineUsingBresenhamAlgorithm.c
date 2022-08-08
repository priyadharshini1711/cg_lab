#include<stdio.h>

#include<conio.h>

#include<math.h>

#include<graphics.h>

main() {
  int gd = DETECT, gm;
  int xa, xb, ya, yb;
  int dx, dy, X, Y, Xend, p, b;
  initgraph( & gd, & gm, "c:\\tc\\bgi");
  printf("ENTER TWO LEFT  END POINTS");
  scanf("%d%d", & xa, & ya);
  printf("ENTER TWO RIGHT END POINTS ");
  scanf("%d%d", & xb, & yb);
  dx = abs(xa - xb);
  dy = abs(ya - yb);
  p = 2 * dy - dx;
  if (xa > xb) {
    X = xb;
    Y = yb;
    Xend = xa;
  } else {
    X = xa;
    Y = ya;
    Xend = xb;
  }
  putpixel(X, Y, b);
  while (X < Xend) {
    X = X + 1;
    if (p < 0) {
      p = p + 2 * dy;
    } else {
      Y = Y + 1;
      p = p + 2 * (dy - dx);
    }
    putpixel(X, Y, b);
  }
  getch();
  return (0);
}