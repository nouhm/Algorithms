//
//  main.cpp
//  Coding
//
//  Created by Maryam Nouh on 11/4/20.
//


//#include <bits/stdc++.h>
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <string.h>
#include <queue>
#include <stack>

using namespace std;


using namespace std;


void basicMagicSquare(int s[3][3])
{
    int n = 3;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            s[i][j] = 0;
    }

    // first position initialization (row and column)
    int c = n / 2;
    int r = n - 1;

    // inserting single values in magic square based on three conditions
    for (int count = 1; count <= n * n;) {
        // third condition is checked first
        if (c == -1 && r == n)
        {
            r = n - 2;
            c = 0;
        }
        else {
            // 1st condition helper if number goes outside the square's limits
            if (r == n)
                r = 0;
            if (c < 0)
                c = n - 1;
        }

        // second condition checked
        if (s[r][c])
        {
            r -= 2;
            c++;
            continue;
        }
        else
            s[r][c] = count++; // number in the cell

        // first condition
        r++;
        c--;
    }
}


void generalizedMagicSquare(int** array, int n)
{
    if (n < 3) {
        cerr << "The number entered has no magic square" << endl;
        return;
    }

    int a[3][3] = { 0 };
    basicMagicSquare(a);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            array[i][j] = a[i][j];
        }
    }

    int row = 3, column = 3;

    if (n % 3 == 0) {

       
            for (int i = 3; i < n; i++) {
                for (int j = 0; j < 3; j++) {
                    array[i][j] = a[i % 3][j];
                }
            }

            for (int j = 3; j < n; j++) {
                for (int i = 0; i < 3; i++) {
                    for (int x = 0; x < n / 3; x++) {
                    array[i+3*x][j] = a[i][j % 3];
                    }
                }
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    cout << array[i][j] << " ";
                }
                cout << endl;
            }
            return;


    }
    else if (n % 2 == 1) {
        int row = 3, column = 3;
        int counter[4] = { 1,0,1,2 };
        int x = 0;
        for (int i = 3; i < n; i++) {
            if (x == 4)
                x = 0;
            for (int j = 0; j < 3; j++) {
                array[i][j] = array[counter[x]][j];
            }
            x++;
        }
        x = 0;
        for (int j = 3; j < n; j++) {
            if (x == 4)
                x = 0;
            for (int i = 0; i < n; i++) {
                array[i][j] = array[i][counter[x]];
            }
            x++;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << array[i][j] << " ";
            }
            cout << endl;
        }
        return;

    }
    else {
        cerr << "n cannot have a magic square with numbers from 1 to 9" << endl;
        return;
    }


 }



int main() {


    int a[3][3] = { 0 };
    basicMagicSquare(a);

    int n;
    cout << "Enter a number for nxn matrix" << endl;
    cin >> n;

    int** ptr = new int* [n];
    for (int i = 0; i < n; ++i)
        ptr[i] = new int[n];

    generalizedMagicSquare(ptr, n);


    return 0;
}
