#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main() {
    string filename;
    cin>>filename;
    ifstream readfile;
    readfile.open(filename);
    int sizeX, sizeY, max, i, k, h;
    readfile >> sizeX >> sizeY;
    if (sizeY > sizeX) {
        max=sizeY;
    }
    else {
        max=sizeX;
    }
    int TirednessMap[40][40];
    int Map[40][40];
    for (i=0; i<sizeY; i++) {
        for (k=0; k<sizeX; k++) {
            Map[i][k]=0;
        }
    }
    for (i=0; i<max; i++) {
        for (k=0; k<max; k++) {
            TirednessMap[i][k]=0;
        }
    }
    int platingCount, currentYear, year;
    int startXCoord, startYCoord, endXCoord, endYCoord;
    readfile >> currentYear >> platingCount;
    year=currentYear;
    while (year < 2018) {
        for (i=0; i<max; i++) {
            for (k=0; k<max; k++) {
                TirednessMap[i][k] = TirednessMap[i][k]-1;
            }
        }
        if (platingCount != 0) {
            for (h=0; h<platingCount; h++) {
                readfile >> startXCoord >> startYCoord >> endXCoord >> endYCoord;
                for (i=startYCoord; i<=endYCoord; i++) {
                    for (k=startXCoord; k<=endXCoord; k++) {
                        TirednessMap[i][k] = TirednessMap[i][k]+2;
                    }
                }
            }
        }
        if (currentYear!=2017) {
            readfile >> currentYear >> platingCount;
        }
        for (i=0; i<max; i++) {
            for (k=0; k<max; k++) {
                if (TirednessMap[i][k] < 0) {
                    TirednessMap[i][k]=0;
                }
            }
        }
        year++;
    }
    readfile.close();
    for (i=0; i<sizeY; i++) {
        for (k=0; k<sizeX; k++) {
            Map[i][k] = TirednessMap[i][k];
            cout << Map[i][k] << " ";
        }
        cout << endl;
    }
    return 0;
}