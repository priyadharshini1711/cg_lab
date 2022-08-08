#include<iostream.h>

#include<graphics.h>

#include<math.h>

#include<conio.h>

#include<stdlib.h>

class cube {
  public:
    void drawcube(int x1[], int y1[]) {
      int i;
      for (i = 0; i < 4; i++) {
        if (i < 3)
          line(x1[i], y1[i], x1[i + 1], y1[i + 1]);
        line(x1[0], y1[0], x1[3], y1[3]);
      }
      for (i = 4; i < 8; i++) {
        if (i < 7)
          line(x1[i], y1[i], x1[i + 1], y1[i + 1]);
        line(x1[4], y1[4], x1[7], y1[7]);
      }
      for (i = 0; i < 4; i++) {
        line(x1[i], y1[i], x1[i + 4], y1[i + 4]);
      }
    }
};

void main() {
  int i, x1[8], y1[8], x2[8], y2[8], z1[8], x3[8], y3[8], z3[8], x4[8], y4[8];
  int theta, op, ch, tx, ty, tz, sx, sy, sz, xf, yf, zf, x, y, z, size;
  int driver = DETECT;
  int mode;
  initgraph( & driver, & mode, "c:\\tc\\bgi");
  cout << "enter the points on the cube:";
  cin >> x >> y >> z;
  cout << "enter the size of the edge:";
  cin >> size;
  x1[0] = x1[3] = x;
  x1[1] = x1[2] = x + size;
  x1[4] = x1[7] = x;
  x1[5] = x1[6] = x + size;
  y1[0] = y1[1] = y;
  y1[2] = y1[3] = y + size;
  y1[4] = y1[5] = y;
  y1[6] = y1[7] = y + size;
  z1[1] = z1[2] = z1[3] = z1[0] = z;
  z1[4] = z1[5] = z1[6] = z1[7] = z - size;
  for (i = 0; i < 8; i++) {
    x2[i] = x1[i] + z1[i] / 2;
    y2[i] = y1[i] + z1[i] / 2;
  }
  cube c;
  getch();
  cleardevice();
  do {
    cout << "menu" << endl;
    cout << "\n 1.Translation\n 2.Rotation\n 3.Scaling\n 4.Exit\n";
    cout << "enter the choice:";
    cin >> ch;
    switch (ch) {
    case 1:
      cout << "enter the translation vector:";
      cin >> tx >> ty >> tz;
      for (i = 0; i < 8; i++) {
        x3[i] = x1[i] + tx;
        y3[i] = y1[i] + ty;
        z3[i] = z1[i] + tz;
      }
      for (i = 0; i < 8; i++) {
        x4[i] = x3[i] + z3[i] / 2;
        y4[i] = y3[i] + z3[i] / 2;
      }
      cleardevice();
      cout << "before translation";
      c.drawcube(x2, y2);
      getch();
      cleardevice();
      cout << "after translation";
      c.drawcube(x4, y4);
      getch();
      cleardevice();
      break;
    case 2:
      cout << "enter the rotation angle:";
      cin >> theta;
      theta = (theta * 3.14) / 180;
      cout << "enter the direction" << endl;
      cout << "1.Rotation about x axis" << endl << "2.Rotation about y axis" << endl << "3.Rotation about z axis";
      cin >> op;
      if (op == 1) {
        for (i = 0; i < 8; i++) {
          x3[i] = x1[i];
          y3[i] = y1[i] * cos(theta) - z1[i] * sin(theta);
          z3[i] = y1[i] * sin(theta) + z1[i] * cos(theta);
        }
      } else
      if (op == 2) {
        for (i = 0; i < 8; i++) {
          y3[i] = y1[i];
          x3[i] = z1[i] * cos(theta) - x1[i] * sin(theta);
          x3[i] = z1[i] * sin(theta) + x1[i] * cos(theta);
        }
      } else
      if (op == 3) {
        for (i = 0; i < 8; i++) {
          z3[i] = z1[i];
          x3[i] = x1[i] * cos(theta) - y1[i] * sin(theta);
          y3[i] = x1[i] * sin(theta) + y1[i] * cos(theta);
        }
      } else
        cout << "enter correct option";
      for (i = 0; i < 8; i++) {
        x4[i] = x3[i] + z3[i] / 2;
        y4[i] = y3[i] + z3[i] / 2;
      }
      cleardevice();
      cout << "before rotation";
      c.drawcube(x2, y2);
      getch();
      cleardevice();
      cout << "after rotation";
      c.drawcube(x4, y4);
      getch();
      cleardevice();
      break;
    case 3:
      cout << "enter scaling factor:";
      cin >> sx >> sy >> sz;
      cout << "enter the reference point:";
      cin >> xf >> yf >> zf;
      for (i = 0; i < 8; i++) {
        x3[i] = xf + (x1[i] * sx) + xf * (1 - sx);
        y3[i] = yf + (y1[i] * sy) + yf * (1 - sy);
        z3[i] = zf + (z1[i] * sz) + zf * (1 - sz);
      }
      for (i = 0; i < 8; i++) {
        x4[i] = x3[i] + z3[i] / 2;
        y4[i] = y3[i] + z3[i] / 2;
      }
      cleardevice();
      cout << "before scaling";
      c.drawcube(x2, y2);
      getch();
      cleardevice();
      cout << "after scaling";
      c.drawcube(x4, y4);
      getch();
      break;
    case 4:
      exit(0);
      break;
    }
  }
  while (op != 4);
  getch();
}