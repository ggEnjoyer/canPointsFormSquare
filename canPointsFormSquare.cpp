#include <iostream>
#include <conio.h>

using namespace std;

struct Point
{
    int
        x,
        y;
};

bool isSquare(Point p1, Point p2, Point p3, Point p4 )
{
    int
        xtop,
        xbot,
        xalmosttop,
        xalmostbot,
        i,
        xes[] = { p1.x, p2.x, p3.x, p4.x },
        yes[] = { p1.y, p2.y, p3.y, p4.y };
    Point
        A,
        B,
        C,
        D;

    if ((p1.x == p2.x && p1.x == p3.x) || (p4.x == p2.x && p4.x == p3.x) || (p1.y == p2.y && p1.y == p3.y) || (p4.y == p2.y && p4.y == p3.y)
        || (p1.x == p2.x && p1.y == p2.y) || (p2.x == p3.x && p2.y == p3.y) || (p3.x == p4.x && p3.y == p4.y) || (p1.x == p4.x && p1.y == p4.y)) return false;

    i = 1;
    xtop = p1.x;
    while (i < 3)
    {
        if (xtop < xes[i])xtop = xes[i];
        i++;
    }

    i = 1;
    xbot = p1.x;
    while (i < 3)
    {
        if (xtop < xes[i])xtop = xes[i];
        i++;
    }
}

int main()
{
    Point p1, p2, p3, p4;
    while (_getch() != 27)
    {
        cout << "\n--------------------------------------------------";
        cout << "\nEnter X and Y coordinates of point 1: ";
        cin >> p1.x >> p1.y;
        cout << "\nEnter X and Y coordinates of point 2: ";
        cin >> p2.x >> p2.y;
        cout << "\nEnter X and Y coordinates of point 3: ";
        cin >> p3.x >> p3.y;
        cout << "\nEnter X and Y coordinates of point 4: ";
        cin >> p4.x >> p4.y;
        if (isSquare(p1, p2, p3, p4) == 0)cout << "They totally cant make square";
        else cout << "\nThere is a possibility that these points can make square";
    }
}
