#include <graphics.h>
#include <conio.h>
#include <math.h>
#define PI 3.141
#include <iostream>
using namespace std;
class Computer_Graphics
{
public:
    void Rotation(int angle, int n, bool AntiClockWiseOrNot)
    {
        int i;
        int arr[2 * n];
        int rotate[2 * n];
        for (i = 0; i < 2 * n; i += 2)
        {
            cout << "Enter Points Coordinates : ";
            cin >> arr[i] >> arr[i + 1];
        }
        if (AntiClockWiseOrNot == false)
        {
            double static anti[2][2] = {
                {cos(angle * PI / 180), sin(angle * PI / 180)},
                {-sin(angle * PI / 180), cos(angle * PI / 180)}};
            for (i = 0; i < 2 * n; i += 2)
            {
                rotate[i] = arr[i] * anti[0][0] + arr[i + 1] * anti[1][0];
                rotate[i + 1] = arr[i] * anti[0][1] + arr[i + 1] * anti[1][1];
            }
        }
        else
        {
            double anti[2][2] = {
                {cos(angle * PI / 180), -sin(angle * PI / 180)},
                {sin(angle * PI / 180), cos(angle * PI / 180)}};
            for (i = 0; i < 2 * n; i += 2)
            {
                rotate[i] = arr[i] * anti[0][0] + arr[i + 1] * anti[1][0];
                rotate[i + 1] = arr[i] * anti[0][1] + arr[i + 1] * anti[1][1];
            }
        }
        setcolor(RED);
        for (i = 0; i < 2 * n - 2; i += 2)
        {
            line(arr[i], arr[i + 1], arr[i + 2], arr[i + 3]);
        }
        i -= 2;
        line(arr[i + 2], arr[i + 3], arr[0], arr[1]);
        setcolor(GREEN);
        for (i = 0; i < 2 * n - 2; i += 2)
        {
            line(rotate[i] + 200, rotate[i + 1] + 200, rotate[i + 2] + 200, rotate[i + 3] + 200);
        }
        i -= 2;
        line(rotate[i + 2] + 200, rotate[i + 3] + 200, rotate[0] + 200, rotate[1] + 200);
        setcolor(LIGHTGREEN);
        outtextxy(300, 1000, "Green Image Is Original, Red Is Rotated Image");
    }
    void Translate(int Tx, int Ty, int n)
    {
        int i;
        int arr[2 * n];
        int trans[2 * n];
        for (i = 0; i < 2 * n; i += 2)
        {
            cout << "Enter Points Coordinates : ";
            cin >> arr[i] >> arr[i + 1];
        }
        setcolor(RED);
        for (i = 0; i < 2 * n - 2; i += 2)
        {
            line(arr[i], arr[i + 1], arr[i + 2], arr[i + 3]);
        }
        i -= 2;
        line(arr[i + 2], arr[i + 3], arr[0], arr[1]);
        for (i = 0; i <= 2 * n; i += 2)
        {
            trans[i] = arr[i] + Tx;
            trans[i + 1] = arr[i + 1] + Ty;
        }
        setcolor(GREEN);
        for (i = 0; i < 2 * n - 2; i += 2)
        {
            line(trans[i], trans[i + 1], trans[i + 2], trans[i + 3]);
        }
        i -= 2;
        line(trans[i + 2], trans[i + 3], trans[1], trans[0]);
        setcolor(LIGHTGREEN);
        outtextxy(300, 1000, "Green Image Is Original, Red Is Translated Image.");
    }
    void Scale(int Sx, int Sy, int n)
    {
        int i;
        int arr[2 * n];
        int scale[2 * n];
        for (i = 0; i < 2 * n; i += 2)
        {
            cout << "Enter Points Coordinates : ";
            cin >> arr[i] >> arr[i + 1];
        }
        setcolor(RED);
        for (i = 0; i < 2 * n - 2; i += 2)
        {
            line(arr[i], arr[i + 1], arr[i + 2], arr[i + 3]);
        }
        i -= 2;
        line(arr[i + 2], arr[i + 3], arr[0], arr[1]);
        for (i = 0; i <= 2 * n; i += 2)
        {
            scale[i] = arr[i] * Sx;
            scale[i + 1] = arr[i + 1] * Sy;
        }
        setcolor(GREEN);
        for (i = 0; i < 2 * n - 2; i += 2)
        {
            line(scale[i], scale[i + 1], scale[i + 2], scale[i + 3]);
        }
        i -= 2;
        line(scale[i + 2], scale[i + 3], scale[1], scale[0]);
        setcolor(LIGHTGREEN);
        outtextxy(300, 1000, "Green Image Is Original, Red Is Scaled Image.");
    }
    void Shearing(int Shx, int Shy, int n, bool Xaxis)
    {
        int i;
        int arr[2 * n];
        int shear[2 * n];
        for (i = 0; i < 2 * n; i += 2)
        {
            cout << "Enter Points Coordinates : ";
            cin >> arr[i] >> arr[i + 1];
        }
        setcolor(RED);
        for (i = 0; i < 2 * n - 2; i += 2)
        {
            line(arr[i], arr[i + 1], arr[i + 2], arr[i + 3]);
        }
        i -= 2;
        line(arr[i + 2], arr[i + 3], arr[0], arr[1]);
        if (Xaxis == true)
        {

            for (i = 0; i <= 2 * n; i += 2)
            {
                shear[i] = arr[i + 1] * Shx + arr[i];
                shear[i + 1] = arr[i + 1];
            }
        }
        else
        {
            for (i = 0; i <= 2 * n; i += 2)
            {
                shear[i] = arr[i];
                shear[i + 1] = arr[i] * Shy + arr[i + 1];
            }
        }
        setcolor(GREEN);
        for (i = 0; i < 2 * n - 2; i += 2)
        {
            line(shear[i], shear[i + 1], shear[i + 2], shear[i + 3]);
        }
        i -= 2;
        line(shear[i + 2], shear[i + 3], shear[0], shear[1]);
        setcolor(LIGHTGREEN);
        outtextxy(300, 1000, "Green Image Is Original, Red Is Sheared Image.");
    }
    void Reflection(int n, bool Xaxis)
    {
        int i;
        int arr[2 * n];
        int reflex[2 * n];
        for (i = 0; i < 2 * n; i += 2)
        {
            cout << "Enter Points Coordinates : ";
            cin >> arr[i] >> arr[i + 1];
        }
        setcolor(RED);
        for (i = 0; i < 2 * n - 2; i += 2)
        {
            line(arr[i], arr[i + 1], arr[i + 2], arr[i + 3]);
        }
        i -= 2;
        line(arr[i + 2], arr[i + 3], arr[0], arr[1]);
        if (Xaxis == true)
        {

            for (i = 0; i <= 2 * n; i += 2)
            {
                reflex[i + 1] = -arr[i + 1];
                reflex[i] = arr[i];
            }
        }
        else
        {
            for (i = 0; i <= 2 * n; i += 2)
            {
                reflex[i] = -arr[i];
                reflex[i + 1] = arr[i + 1];
            }
        }
        setcolor(GREEN);
        for (i = 0; i < 2 * n - 2; i += 2)
        {
            line(reflex[i] + 300, reflex[i + 1] + 300, reflex[i + 2] + 300, reflex[i + 3] + 300);
        }
        i -= 2;
        line(reflex[i + 2] + 300, reflex[i + 3] + 300, reflex[0] + 300, reflex[1] + 300);
        setcolor(LIGHTGREEN);
        outtextxy(300, 1000, "Green Image Is Original, Red Is Reflected Image.");
    }
    void DDA(int x1, int y1, int x2, int y2)
    {
        float dx, dy, xin, yin, x, y;
        int step, i;
        i = 1;
        dx = x2 - x1;
        dy = y2 - y1;
        step = dx > dy ? dx : dy;
        xin = dx / step;
        yin = dy / step;
        x = x1;
        y = y1;
        while (i <= step)
        {
            putpixel(x += xin, y += yin, LIGHTCYAN);
            i += 1;
        }
        outtextxy(300, 1000, "DDA Line Drawing Algorithm");
    }
    void Bresenham(int x1, int y1, int x2, int y2)
    {
        int p, dx, dy;
        dx = x2 - x1;
        dy = y2 - y1;
        p = 2 * dy - dx;
        if (dy < dx)
        {
            while (x1 <= x2)
            {
                x1 += 1;
                if (p < 0)
                {
                    p += 2 * dy;
                }
                else
                {
                    y1 += 1;
                    p += 2 * dy - 2 * dx;
                }
                putpixel(x1, y1, LIGHTCYAN);
            }
        }
        else
        {
            while (y1 <= y2)
            {
                y1 += 1;
                if (p < 0)
                {
                    p += 2 * dx;
                }
                else
                {
                    x1 += 1;
                    p += 2 * dx - dy;
                }
                putpixel(x1, y1, LIGHTCYAN);
            }
        }
    }
    void Bresenham_Circle(int radius)
    {
        int x, y, p;
        x = 0;
        y = radius;
        p = 3 - 2 * radius;
        while (x <= y)
        {
            if (p <= 0)
            {
                x += 1;
                p += 4 * x + 6;
            }
            else
            {
                x += 1;
                y -= 1;
                p += 4 * (x - y) + 10;
            }
            putpixel(x + 960, y + 540, WHITE);
            putpixel(-x + 960, y + 540, WHITE);
            putpixel(x + 960, -y + 540, WHITE);
            putpixel(-x + 960, -y + 540, WHITE);
            putpixel(y + 960, x + 540, WHITE);
            putpixel(-y + 960, x + 540, WHITE);
            putpixel(y + 960, -x + 540, WHITE);
            putpixel(-y + 960, -x + 540, WHITE);
        }
    }
};
void Program_Handler()
{
    int op, Factor_x, Factor_y, x1, x2, y1, y2, radius, angle, n;
    while (true)
    {
        Computer_Graphics avik;
        cout << "\n(1) DDA LINE DRAWING  ";
        cout << "\n(2) BRSENHAM LINE DRAWING  ";
        cout << "\n(3) BRESENHAM CIRCLE DRAWING  ";
        cout << "\n(4) TRANSLATE  ";
        cout << "\n(5) SCALLING";
        cout << "\n(6) SHEARING";
        cout << "\n(7) REFLECTION";
        cout << "\n(8) ROTATION";
        cout << "\n(9) EXIT";
        cout << "\nChoose An Option : ";
        cin >> op;
        switch (op)
        {
        case 1:
            cout << "Enter Starting & Ending Point Coordinates : ";
            cin >> x1 >> y1 >> x2 >> y2;
            avik.DDA(x1, y1, x2, y2);
            break;
        case 2:
            cout << "Enter Starting & Ending Point Coordinates : ";
            cin >> x1 >> y1 >> x2 >> y2;
            avik.Bresenham(x1, y1, x2, y2);
            break;
        case 3:
            cout << "Enter Circle Radius : ";
            cin >> radius;
            avik.Bresenham_Circle(radius);
            break;
        case 4:
            cout << "Enter Translate-X & Translate-Y Factor : ";
            cin >> Factor_x >> Factor_y;
            cout << "No Of Sides Of Polygon : ";
            cin >> n;
            avik.Translate(Factor_x, Factor_y, n);
            break;
        case 5:
            cout << "Enter Scale-X & Scale-Y Factor : ";
            cin >> Factor_x >> Factor_y;
            cout << "No Of Sides Of Polygon : ";
            cin >> n;
            avik.Scale(Factor_x, Factor_y, n);
            break;
        case 6:
            cout << "Enter Shearing-X & Shearing-Y Factor : ";
            cin >> Factor_x >> Factor_y;
            cout << "No Of Sides Of Polygon : ";
            cin >> n;
            avik.Shearing(Factor_x, Factor_y, n, true);
            break;
        case 7:
            cout << "No Of Sides : ";
            cin >> n;
            avik.Reflection(n, true);
            break;
        case 8:
            cout << "Enter Rotation Angle : ";
            cin >> angle;
            avik.Rotation(angle, n, true);
            break;
        case 9:
            exit(0);
        default:
            cout << "Choose A Correct Option Or Press 9 For Exit The Program";
            break;
        }
    }
}
int main()
{
    int gd = DETECT, gm;
    int sides, angle;
    initgraph(&gd, &gm, NULL);
    initwindow(1920, 1080);
    Program_Handler();
    getch();
    closegraph();
}