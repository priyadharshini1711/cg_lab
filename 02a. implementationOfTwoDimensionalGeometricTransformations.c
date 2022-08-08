 #include<graphics.h>

 #include<stdlib.h>

 #include<stdio.h>

 #include<conio.h>

 int x1, x2, x3, y1, y2, y3, t, tx, sx, sy, shx, shy, ch;
 float rx1, rx2, rx3, ry1, ry2, ry3;
 float ang, theta;
 int main(void) {
   int gdriver = DETECT, gmode, errorcode;
   initgraph( & gdriver, & gmode, "C:\\TC\\BGI");
   /* request for auto detection*/
   errorcode = graphresult();
   if (errorcode != grOk)
   /* if error occours*/
   {
     printf("Graphics error: %s\n", grapherrormsg(errorcode));
     printf("Press any key to halt:");
     getch();
     exit(1);
   } else {
     do {
       printf("\n1.Translation\n2.Reflection\n3.Rotation\n4.Scaling\n5.Shearing\n");
       printf("\nEnter Your choice");
       /* get the choice from the user*/
       scanf("%d", & ch);
       switch (ch) {
       case 1:
         printf("\n Enter all coordinates values :");
         /* get the coordinate values*/
         scanf("%d %d %d %d %d %d", & x1, & y1, & x2, & y2, & x3, & y3);
         printf("\n Before Translation ");
         line(x1, y1, x2, y2);
         line(x2, y2, x3, y3);
         line(x3, y3, x1, y1);
         printf("\n Enter the value tranlsation factor :");
         scanf("%d", & tx);
         /* get the value for the translation factor*/
         printf("\n After Translation\n ");
         line(x1 + tx, y1, x2 + tx, y2);
         /* draw the new translated image*/
         line(x2 + tx, y2, x3 + tx, y3);
         line(x3 + tx, y3, x1 + tx, y1);
         break;
       case 2:
         printf("\n Enter all coordinates values :");
         scanf("%d %d %d %d %d %d", & x1, & y1, & x2, & y2, & x3, & y3);
         printf("\n Before Reflection ");
         /* draw the image before reflection*/
         line(x1, y1, x2, y2);
         line(x2, y2, x3, y3);
         line(x3, y3, x1, y1);
         t = abs(y1 - y3);
         /* find the value of the reflection factor*/
         printf("\n After Reflection ");
         line(x1, y1 + 10 + (2 * t), x2, y2 + 10);
         /* draw the reflected object*/
         line(x2, y2 + 10, x3, y3 + 10);
         line(x3, y3 + 10, x1, y1 + 10 + (2 * t));
         break;
       case 3:
         printf("\n Enter all coordinates values :");
         scanf("%d %d %d %d %d %d", & x1, & y1, & x2, & y2, & x3, & y3);
         printf("\n Before Rotation ");
         /* get the original coordinates*/
         line(x1, y1, x2, y2);
         line(x2, y2, x3, y3);
         line(x3, y3, x1, y1);
         printf("\n Enter the rotation angle :");
         /* get the angle for rotation*/
         scanf("%f", & ang);
         theta = ((ang * 3.14) / 180);
         /* convert the given angle*/
         rx1 = x1 * cos(theta) - y1 * sin(theta);
         rx2 = x2 * cos(theta) - y2 * sin(theta);
         rx3 = x3 * cos(theta) - y3 * sin(theta);
         ry1 = x1 * sin(theta) + y1 * cos(theta);
         ry2 = x2 * sin(theta) + y2 * cos(theta);
         ry3 = x3 * sin(theta) + y3 * cos(theta);
         printf("\n After Rotation ");
         /* draw the rotated image*/
         line(rx1, ry1, rx2, ry2);
         line(rx2, ry2, rx3, ry3);
         line(rx3, ry3, rx1, ry1);
         break;
       case 4:
         printf("\n Enter all coordinates values :");
         scanf("%d %d %d %d %d %d", & x1, & y1, & x2, & y2, & x3, & y3);
         printf("\n Before Scaling ");
         /* get the scale factor*/
         line(x1, y1, x2, y2);
         line(x2, y2, x3, y3);
         line(x3, y3, x1, y1);
         printf("\n Enter the Scale factor :");
         scanf("%d %d", & sx, & sy);
         printf("\n After Scaling ");
         /* draw the object after scaling*/
         line(x1 + sx, y1 + sy, x2 + sx, y2 + sy);
         line(x2 + sx, y2 + sy, x3 + sx, y3 + sy);
         line(x3 + sx, y3 + sy, x1 + sx, y1 + sy);
         break;
       case 5:
         printf("\n Enter all coordinates values :");
         scanf("%d %d %d %d %d %d", & x1, & y1, & x2, & y2, & x3, & y3);
         printf("\n Before Shearing ");
         /* get the values for shearing*/
         line(x1, y1, x2, y2);
         line(x2, y2, x3, y3);
         line(x3, y3, x1, y1);
         printf("\n Enter 0 for x-axis and 1 for y-axis: ");
         scanf("%d", & ch);
         if (ch == 0) {
           printf("\n Enter the x-SHEAR (^.^) Value: ");
           scanf("%d", & shx);
           x1 = x1 + shx * y1;
           x2 = x2 + shx * y2;
           x3 = x3 + shx * y3;
         } else {
           printf("\n Enter the y-SHEAR (^.^) Value: ");
           scanf("%d", & shy);
           y1 = y1 + shy * x1;
           y2 = y2 + shy * x2;
           y3 = y3 + shy * x3;
         }
         printf("\n After Shearing ");
         line(x1, y1, x2, y2);
         /* draw the final object after shearing*/
         line(x2, y2, x3, y3);
         line(x3, y3, x1, y1);
         break;
       default:
         exit(0);
         break;
       }
     }
     while (ch != 0);
   }
   getch();
   closegraph();
   return 0;
 }