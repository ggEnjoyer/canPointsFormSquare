#include <iostream>
#include <conio.h>
#include <math.h>

using namespace std;

struct Point
{
    int
        x,
        y;
};

bool isSquare(Point p1, Point p2, Point p3, Point p4 )
{
    double
        AB,
        BC,
        CD,
        DA,
        AC,
        BD;
    int
        xtop,
        xbot,
        ytop,
        ybot,
        i,
        id,
        xes[] = { p1.x, p2.x, p3.x, p4.x },
        yes[] = { p1.y, p2.y, p3.y, p4.y };
    Point
        A,
        B,
        C,
        D;

    //if ((p1.x == p2.x && p1.y == p2.y) || (p2.x == p3.x && p2.y == p3.y) || (p3.x == p4.x && p3.y == p4.y) || (p1.x == p4.x && p1.y == p4.y)) return false;
    //define xtop
    i = 1;
    id = 0;
    xtop = xes[0];
    while (i < 4)
    {
        if (xtop < xes[i]) 
        {
            xtop = xes[i]; 
            id = i;
        }
        i++;
    }
    A.x = xtop; 
    A.y = yes[id];
    cout << endl << A.x << " " << A.y;

    //define xbot
    i = 1;
    id = 0;
    xbot = xes[0];
    while (i < 3)
    {
        if (xbot > xes[i])
        {
            xbot = xes[i];
            id = i;
        }
        i++;
    }
    B.x = xbot;
    B.y = yes[id];
    cout << endl << B.x << " " << B.y;

    //define ytop
    i = 1;
    id = 0;
    ytop = yes[0];
    while (i < 4)
    {
        if (ytop < yes[i])
        {
            ytop = yes[i];
            id = i;
        }
        i++;
    }
    C.y = ytop;
    C.x = xes[id];
    cout << endl << C.x << " " << C.y;

    //define ybot
    i = 1;
    id = 0;
    ybot = yes[0];
    while (i < 3)
    {
        if (ybot > yes[i])
        {
            cout << endl << ybot << " > " << yes[i];
            ybot = yes[i];
            id = i;
        }
        i++;
    }
    D.y = ybot;
    D.x = xes[id];
    cout << endl << D.x << " " << D.y;

    AC = sqrt(pow((A.x - C.x), 2) + pow((A.y - C.y), 2));
    cout << endl << AC;
    BC = sqrt(pow((B.x - C.x), 2) + pow((B.y - C.y), 2));
    cout << endl << BC;
    BD = sqrt(pow((B.x - D.x), 2) + pow((B.y - D.y), 2));
    cout << endl << BD;
    DA = sqrt(pow((D.x - A.x), 2) + pow((D.y - A.y), 2));
    cout << endl << DA;

    AB = sqrt(pow((A.x - B.x), 2) + pow((A.y - B.y), 2));
    cout << endl << AB;
    CD = sqrt(pow((C.x - D.x), 2) + pow((C.y - D.y), 2));
    cout << endl << CD;
    
    if ((AB == CD) && (AC == BC) && (BC == BD) && (DA == AC) && (AC == DA) && (AC != 0)) return 1;
       /* if (AB == CD)
        {
            cout << "\nab = cd...";
            if (AC == BC)
            {
                cout << "\nac = cd...";
                if (BC == BD)
                {
                    cout << "\nbc = bd...";
                    if (DA == AC)
                    {
                        cout << "\nda = ac...";
                        if (AC == DA)
                        {
                            cout << "\nac = da...";
                            if (AC != 0)
                            {
                                cout << "\nac is not 0...\nso it`s true!";
                                return 1;
                            }
                            cout << "\nbut ac is 0, so it is false.";
                        }
                        cout << "\n but ac != da";
                    }
                    cout << "\nbut da != ac";
                }
                cout << "\nbut bc != bd";
            }
            cout << "\nbut ac != bc";
        }
        cout << "\nab != cd";*/
    return 0;
}

void Sort(int i[], int &f)
{
    int j = 1, net;
    bool b = false;
    while (!b)
    {
        b = true;
        j = 1;
        while (j < 4)
        {
            if (i[j - 1] > i[j])
            {
                net = i[j - 1];
                i[j - 1] = i[j];
                i[j] = net;
                b = false;
            }
            j++;
        }
    }
}

int main()
{
    int i[4];
    Point p1, p2, p3, p4;
    while (_getch() != 27)
    {
        cout << "\n--------------------------------------------------\n";
        cout << "\nEnter X and Y coordinates of point 1: ";
        cin >> p1.x >> p1.y;
        cout << "\nEnter X and Y coordinates of point 2: ";
        cin >> p2.x >> p2.y;
        cout << "\nEnter X and Y coordinates of point 3: ";
        cin >> p3.x >> p3.y;
        cout << "\nEnter X and Y coordinates of point 4: ";
        cin >> p4.x >> p4.y;
        if (isSquare(p1, p2, p3, p4) == 0)cout << "\nThey totally cant make square";
        else cout << "\nThere is a possibility that these points can make square";
    }
}
