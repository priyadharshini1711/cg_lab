#include&quot;stdio.h&quot;

#include&quot;conio.h&quot;

#include&quot;graphics.h&quot;

#include&quot;stdlib.h&quot;

void main() {
  float xwmin, xwmax, ywmax, ywmin;
  float xvmin, xvmax, yvmax, yvmin;
  float x[10], y[10], yv, xv, sx, sy;
  int gd = DETECT, gm, i;
  clrscr();
  printf( & quot;\ n enter window port coordinates: \n(xwmin, ywmin, xwmax, ywmax): & quot;);
  scanf( & quot; % f % f % f % f & quot;, & amp; xwmin, & amp; ywmin, & amp; xwmax, & amp; ywmax);
  printf( & quot;\ n enter view port coordinates: \n(xvmin, yvmin, xvmax, yvmax): & quot;);
  scanf( & quot; % f % f % f % f & quot;, & amp; xvmin, & amp; yvmin, & amp; xvmax, & amp; yvmax);
  printf( & quot;\ n enter vertices
    for triangle: & quot;);
  for (i = 0; i & lt; 3; i++) {
    printf( & quot;\ n enter(x % d, y % d): & quot;, i, i);
    scanf( & quot; % f % f & quot;, & amp; x[i], & amp; y[i]);
  }
  sx = ((xvmax - xvmin) / (xwmax - xwmin));
  sy = ((yvmax - yvmin) / (ywmax - xwmin));
  initgraph( & amp; gd, & amp; gm, & quot; & quot;);
  outtextxy(80, 30, & quot; window port & quot;);
  rectangle(xwmin, ywmin, xwmax, ywmax);
  for (i = 0; i & lt; 2; i++) {
    line(x[i], y[i], x[i + 1], y[i + 1]);
  }
  line(x[2], y[2], x[0], y[0]);
  getch();
  cleardevice();
  for (i = 0; i & lt; 3; i++)

  {
    x[i] = xvmin + ((x[i] - xwmin) * sx);
    y[i] = yvmin + ((y[i] - ywmin) * sy);
  }
  outtextxy(150, 10, & quot; view port & quot;);
  rectangle(xvmin, yvmin, xvmax, yvmax);
  for (i = 0; i & lt; 2; i++) {
    line(x[i], y[i], x[i + 1], y[i + 1]);
  }
  line(x[2], y[2], x[0], y[0]);
  getch();
}