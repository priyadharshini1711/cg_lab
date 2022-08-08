#include<iostream.h>

#include<graphics.h>

#include<conio.h>

#include<stdlib.h>

typedef struct coord {
  int x, y;
  char code[4];
}
pt;
class sulc {
  public:
    void drawwindow();
  void drawline(pt p1, pt p2, int c1);
  pt setcode(pt p);
  int visibility(pt p1, pt p2);
  pt resetendpt(pt p1, pt p2);
};
void sulc::drawwindow() {
  setcolor(12);
  line(150, 100, 450, 100);
  line(450, 100, 450, 350);
  line(450, 350, 150, 350);
  line(150, 350, 150, 100);
}
void sulc::drawline(pt p1, pt p2, int c1) {
  setcolor(c1);
  line(p1.x, p1.y, p2.x, p2.y);
}
pt sulc::setcode(pt p) {
  pt ptemp;
  if (p.y < 100)
    ptemp.code[0] = '1';
  else
    ptemp.code[0] = '0';
  if (p.y > 350)
    ptemp.code[1] = '1';
  else
    ptemp.code[1] = '0';
  if (p.x > 450)
    ptemp.code[2] = '1';
  else
    ptemp.code[2] = '0';
  if (p.x < 150)
    ptemp.code[3] = '1';
  else
    ptemp.code[3] = '0';
  ptemp.x = p.x;
  ptemp.y = p.y;
  return (ptemp);
}
int sulc::visibility(pt p1, pt p2) {
  int i, flag = 0;
  for (i = 0; i < 4; i++) {
    if ((p1.code[i] != '0') || (p2.code[i] != '0'))
      flag = 1;
  }
  if (flag == 0)
    return (0);
  for (i = 0; i < 4; i++) {
    if ((p1.code[i] == p2.code[i]) && (p1.code[i] == '1'))
      flag = 0;
  }
  if (flag == 0)
    return (1);
  return (2);
}
pt sulc::resetendpt(pt p1, pt p2) {
  pt temp;
  int x, y, i;
  float m, k;
  if (p1.code[3] == '1')
    x = 150;
  if (p1.code[2] == '1')
    x = 450;
  if ((p1.code[3] == '1') || (p1.code[2] == '1')) {
    m = (float)(p2.y - p1.y) / (p2.x - p1.x);
    k = (p1.y + (m * (x - p1.x)));
    temp.y = k;
    temp.x = x;
    for (i = 0; i < 4; i++)
      temp.code[i] = p1.code[i];
    if (temp.x <= 450 && temp.x >= 150)
      return (temp);
  }
  if (p1.code[0] == '1')
    y = 100;
  if (p1.code[1] == '1')
    y = 350;
  if ((p1.code[0] == '1') || (p1.code[1] == '1')) {
    m = (float)(p2.y - p1.y) / (p2.x - p1.x);
    k = (float) p1.x + (float)(y - p1.y) / m;
    temp.x = k;
    temp.y = y;
    for (i = 0; i < 4; i++)
      temp.code[i] = p1.code[i];
    if (temp.y <= 350 && temp.y > 100)
      return (temp);
  } else
    return (p1);
}

void main() {
  int gd = DETECT, gm, v;
  sulc c1;
  pt p1, p2, ptemp;
  initgraph( & gd, & gm, "c:\\tc\\bgi");
  int x1[10], y1[10], x2[10], y2[10];
  cleardevice();
  int i, n;
  settextstyle(4, 0, 4);
  outtext("\n*****Cohen Sutherland Line Clipping*****");
  cout << "\n\n\nEnter the no. of lines:";
  cin >> n;
  for (i = 0; i < n; i++) {
    cout << "\nEnter end point1(x1,y1):";
    cin >> x1[i] >> y1[i];
    cout << "\nEnter end point2(x2,y2):";
    cin >> x2[i] >> y2[i];
  }
  cleardevice();
  settextstyle(0, 0, 3);
  outtext("\nBefore Clipping");
  c1.drawwindow();
  for (i = 0; i < n; i++) {
    p1.x = x1[i];
    p1.y = y1[i];
    p2.x = x2[i];
    p2.y = y2[i];
    c1.drawline(p1, p2, 15);
  }
  getch();
  cleardevice();
  settextstyle(0, 0, 3);
  outtext("\nAfter Clipping");
  for (i = 0; i < n; i++) {
    p1.x = x1[i];
    p1.y = y1[i];
    p2.x = x2[i];
    p2.y = y2[i];
    p1 = c1.setcode(p1);
    p2 = c1.setcode(p2);
    v = c1.visibility(p1, p2);
    switch (v) {
    case 0:
      c1.drawwindow();
      c1.drawline(p1, p2, 15);
      break;
    case 1:
      c1.drawwindow();
      break;
    case 2:
      p1 = c1.resetendpt(p1, p2);
      p2 = c1.resetendpt(p2, p1);
      c1.drawwindow();
      c1.drawline(p1, p2, 15);
      break;
    }
  }
  getch();
  closegraph();
}