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

void buildTriangles (int array[15][15] , int n, int sz) {
    
    if (n == 2) {
        array[sz/2][sz/2] = 2;
        array [sz/2-1][sz/2] = 2;
        array [sz/2][sz/2+1] = 2;
        array [sz/2][sz/2-1] = 2;
        return;
    }
    buildTriangles (array, n-1, sz);
    
    for (int i = 0; i < sz ; i++) {
        for (int j = 0; j < sz ; j++) {
            if (array[i][j] == n-1)
            {
                if (array[i+1][j] != 0)
                {
                    if ((array[i][j+1] == n-1) && (array[i][j-1] == n-1))
                    {
                        if (array [i-1][j]== 0)
                            array [i-1][j] = n;
                    }
                    if (array [i][j+1]== 0)
                        array [i][j+1] = n;
                    if (array [i][j-1] == 0)
                        array [i][j-1] = n;

                }
                if (array[i][j+1] != 0)
                {
                    if ((array[i][j+1] != n-1) || (array[i][j-1] != n-1))
                    {
                        if (array [i+1][j] == 0)
                            array [i+1][j] = n;
                    }
                    if (array [i][j-1] == 0)
                        array [i][j-1] = n;
                }
                if (array[i][j-1] != 0)
                {
                    if ((array[i][j+1] != n-1) || (array[i][j-1] != n-1))
                    {
                        if (array [i+1][j] == 0)
                            array [i+1][j] = n;
                    }
                    if (array [i][j+1] == 0)
                        array [i][j+1] = n;
                }
            }
        }
    }
}


int countTriangles (int array[15][15], int n, int sz) {
    int count = 0;
    for (int i = 0; i < sz; i ++)
    {
        for (int j = 0; j < sz; j ++ )
        {
            if (array[i][j] != 0)
                count ++;
        }
    }
    return count;
}

int countTriangles2(int n){
    if (n <= 1)
        return 1;
    return countTriangles2(n-1) + 3*(n-1) ;
}


int main(int argc, const char * argv[]) {
    
    const int sz = 15;
    int n;
    cin >> n;
    int ptr[15][15];
    for (int i = 0; i < sz; i ++)
    {
        for (int j = 0 ; j < sz; j++)
        {
            ptr[i][j] = 0;
        }
    }
    buildTriangles(ptr, n, sz);

    for (int i = 0; i < sz; i++){
        for (int j = 0; j < sz; j++){
            cout << ptr[i][j] << " ";
        }
        cout << endl;
    }
    cout << "The number of small triangles: " <<  countTriangles2(n) << endl;
    
    return 0;
}
