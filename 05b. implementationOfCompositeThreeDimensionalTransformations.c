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
  int theta, theta1, xf1, yf1, zf1, op, ch, tx, ty, tz, tx1, ty1, tz1, sx1, sy1, sz1, sx, sy, sz, xf, yf, zf, x, y, z, size;
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
    cout << "\n1.translation\n2.rotation\n3.scaling\n4.exit\n";
    cout << "enter the choice:";
    cin >> ch;
    switch (ch) {
    case 1:
      cout << "enter the first translation vector:";
      cin >> tx >> ty >> tz;
      cout << "\n enter the second translation vector:";
      cin >> tx1 >> ty1 >> tz1;
      cleardevice();
      cout << "before translation";
      c.drawcube(x2, y2);
      getch();
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
      cout << "after first translation";
      c.drawcube(x4, y4);
      getch();
      for (i = 0; i < 8; i++) {
        x3[i] = x3[i] + tx1;
        y3[i] = y3[i] + ty1;
        z3[i] = z3[i] + tz1;
      }
      for (i = 0; i < 8; i++) {
        x4[i] = x3[i] + z3[i] / 2;
        y4[i] = y3[i] + z3[i] / 2;
      }
      cleardevice();
      cout << "after second translation";
      c.drawcube(x4, y4);
      getch();
      cleardevice();
      break;
    case 2:
      cout << "enter the first rotation angle:";
      cin >> theta;
      cout << "enter the second rotation angle:";
      cin >> theta1;
      theta = (theta * 3.14) / 180;
      theta1 = theta + (theta1 * 3.14) / 180;
      cout << "enter the direction" << endl;
      cout << "1.rotation about x axis" << endl << "2.rotation about y axis" << endl << "3.rotation about z axis";
      cin >> op;
      cleardevice();
      cout << "before rotation";
      c.drawcube(x2, y2);
      getch();
      if (op == 1) {
        for (i = 0; i < 8; i++) {
          x3[i] = x1[i];
          y3[i] = y1[i] * cos(theta) - z1[i] * sin(theta);
          z3[i] = y1[i] * sin(theta) + z1[i] * cos(theta);
        }
        for (i = 0; i < 8; i++) {
          x4[i] = x3[i] + z3[i] / 2;
          y4[i] = y3[i] + z3[i] / 2;
        }
        cleardevice();
        cout << "after first rotation";
        c.drawcube(x4, y4);
        getch();
        for (i = 0; i < 8; i++) {
          x3[i] = x1[i];
          y3[i] = y1[i] * cos(theta1) - z1[i] * sin(theta1);
          z3[i] = y1[i] * sin(theta1) + z1[i] * cos(theta1);
        }
        for (i = 0; i < 8; i++) {
          x4[i] = x3[i] + z3[i] / 2;
          y4[i] = y3[i] + z3[i] / 2;
        }
        cleardevice();
        cout << "after second rotation";
        c.drawcube(x4, y4);
        getch();
      } else
      if (op == 2) {
        for (i = 0; i < 8; i++) {
          y3[i] = y1[i];
          x3[i] = z1[i] * cos(theta) - x1[i] * sin(theta);
          x3[i] = z1[i] * sin(theta) + x1[i] * cos(theta);
        }
        for (i = 0; i < 8; i++) {
          x4[i] = x3[i] + z3[i] / 2;
          y4[i] = y3[i] + z3[i] / 2;
        }
        cleardevice();
        cout << "after first rotation";
        c.drawcube(x4, y4);
        getch();
        for (i = 0; i < 8; i++) {
          y3[i] = y1[i];
          x3[i] = z1[i] * cos(theta1) - x1[i] * sin(theta1);
          x3[i] = z1[i] * sin(theta1) + x1[i] * cos(theta1);
        }
        for (i = 0; i < 8; i++) {
          x4[i] = x3[i] + z3[i] / 2;
          y4[i] = y3[i] + z3[i] / 2;
        }
        cleardevice();
        cout << "after second rotation";
        c.drawcube(x4, y4);
        getch();
      } else
      if (op == 3) {
        for (i = 0; i < 8; i++) {
          z3[i] = z1[i];
          x3[i] = x1[i] * cos(theta) - y1[i] * sin(theta);
          y3[i] = x1[i] * sin(theta) + y1[i] * cos(theta);
        }
        for (i = 0; i < 8; i++) {
          x4[i] = x3[i] + z3[i] / 2;
          y4[i] = y3[i] + z3[i] / 2;
        }
        cleardevice();
        cout << "after first rotation";
        c.drawcube(x4, y4);
        getch();
        for (i = 0; i < 8; i++) {
          z3[i] = z1[i];
          x3[i] = x1[i] * cos(theta1) - y1[i] * sin(theta1);
          y3[i] = x1[i] * sin(theta1) + y1[i] * cos(theta1);
        }
        for (i = 0; i < 8; i++) {
          x4[i] = x3[i] + z3[i] / 2;
          y4[i] = y3[i] + z3[i] / 2;
        }
        cleardevice();
        cout << "after second rotation";
        c.drawcube(x4, y4);
        getch();
      } else
        cout << "enter correct option";
      cleardevice();
      break;
    case 3:
      cout << "enter the first scaling factor:";
      cin >> sx >> sy >> sz;
      cout << "enter the second scaling factor:";
      cin >> sx1 >> sy1 >> sz1;
      cout << "enter the first reference point:";
      cin >> xf >> yf >> zf;
      cout << "enter the second reference point:";
      cin >> xf1 >> yf1 >> zf1;
      cleardevice();
      cout << "before scaling";
      c.drawcube(x2, y2);
      getch();
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
      cout << "after first scaling";
      c.drawcube(x4, y4);
      getch();
      for (i = 0; i < 8; i++) {
        x3[i] = xf1 + (x1[i] * sx * sx1) + xf1 * (1 - sx - sx1);
        y3[i] = yf1 + (y1[i] * sy * sy1) + yf1 * (1 - sy - sy1);
        z3[i] = zf1 + (z1[i] * sz * sz1) + zf1 * (1 - sz - sz1);
      }
      for (i = 0; i < 8; i++) {
        x4[i] = x3[i] + z3[i] / 2;
        y4[i] = y3[i] + z3[i] / 2;
      }
      cleardevice();
      cout << "after second scaling";
      c.drawcube(x4, y4);
      getch();
      cleardevice();
      break;
    case 4:
      exit(0);
      break;
    }
  } while (op != 4);
  getch();
}