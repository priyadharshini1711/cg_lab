#include<stdio.h>

#include<conio.h>

#include<graphics.h>

#include<math.h>

int ch, x, y, az, i, w, ch1, ch2, xa, ya, ra, ra1, a[10], b[10], da, db;
float x1, y1, az1, w1, dx1, dy1, dx2, dy2, theta, theta1, x1s, y1s, sx2, sy2, sx1, sy1, a1[10], b1[10];
void main() {
  int gd, gm;
  clrscr();
  detectgraph( & gd, & gm);
  initgraph( & gd, & gm, "c:\\tc\\bgi");
  printf("\nEnter the upper left corner of the rectangle:");
  scanf("%d%d", & x, & y);
  printf("\nEnter the lowest right corner of the rectangle:");
  scanf("%d%d", & az, & w);
  rectangle(x, y, az, w);
  da = az - x;
  db = w - y;
  a[0] = x;
  b[0] = y;
  a[1] = x + da;
  b[1] = y;
  a[2] = x + da;
  b[2] = y + db;
  a[3] = x;
  b[3] = y + db;
  while (1) {
    printf("\n*****Composite 2D Transformations******");
    printf("\n1.Translation\n2.Rotation\n3.Scaling\n4.Exit\n Enter your choice:");
    scanf("%d", & ch);
    switch (ch) {
    case 1:
      detectgraph( & gd, & gm);
      initgraph( & gd, & gm, "c:\\tc\\bgi");
      rectangle(x, y, az, w);
      printf("\n*****Translation******");
      printf("\nEnter the value of 1st shift factor:");
      scanf("%f%f", & dx1, & dy1);
      printf("\nEnter the value of 2nd shift factor:");
      scanf("%f%f", & dx2, & dy2);
      x1 = x + dx1;
      y1 = y + dy1;
      az1 = az + dx1;
      w1 = w + dy1;
      rectangle(x1, y1, az1, w1);
      x1 = x1 + dx2;
      y1 = y1 + dy2;
      az1 = az1 + dx2;
      w1 = w1 + dy2;
      rectangle(x1, y1, az1, w1);
      break;
    case 2:
      detectgraph( & gd, & gm);
      initgraph( & gd, & gm, "c:\\tc\\bgi");
      rectangle(x, y, az, w);
      printf("\n*****Rotation******");
      printf("\nEnter the value of fixed point:");
      scanf("%d%d", & xa, & ya);
      printf("\nEnter the value of angle of rotation 1 & rotation 2:");
      scanf("%d%d", & ra, & ra1);
      theta = (float)(ra * (3.14 / 180));
      for (i = 0; i < 4; i++) {
        a1[i] = (xa + ((a[i] - xa) * cos(theta) - (b[i] - ya) * sin(theta)));
        b1[i] = (ya + ((a[i] - xa) * sin(theta) + (b[i] - ya) * cos(theta)));
      }
      for (i = 0; i < 4; i++) {
        if (i != 3)
          line(a1[i], b1[i], a1[i + 1], b1[i + 1]);
        else
          line(a1[i], b1[i], a1[0], b1[0]);
      }
      theta1 = theta + (float)(ra1 * (3.14 / 180));
      for (i = 0; i < 4; i++) {
        a1[i] = (xa + ((a[i] - xa) * cos(theta1) - (b[i] - ya) * sin(theta1)));
        b1[i] = (ya + ((a[i] - xa) * sin(theta1) + (b[i] - ya) * cos(theta1)));
      }
      for (i = 0; i < 4; i++) {
        if (i != 3)
          line(a1[i], b1[i], a1[i + 1], b1[i + 1]);
        else
          line(a1[i], b1[i], a1[0], b1[0]);
      }
      break;
    case 3:
      detectgraph( & gd, & gm);
      initgraph( & gd, & gm, "c:\\tc\\bgi");
      rectangle(x, y, az, w);
      printf("\n*****Scaling******");
      printf("\nEnter the value of Scaling factor1:");
      scanf("%f%f", & sx1, & sy1);
      printf("\nEnter the value of Scaling factor2:");
      scanf("%f%f", & sx2, & sy2);
      x1 = x * sx1;
      y1 = y * sy1;
      az1 = az * sx1;
      w1 = w * sy1;
      rectangle(x, y, az1, w1);
      x1 = x1 * sx2;
      y1 = y1 * sy2;
      az1 = az1 * sx2;
      w1 = w1 * sy2;
      rectangle(x1, y1, az1, w1);
      break;
    case 4:
      exit(0);
    }
    getch();
  }
}