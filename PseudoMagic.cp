#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int magicsq[3][3];
    int i, j, x;

    int row = 0;
    int col = 3 / 2;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
            magicsq[i][j] = 0;
    }

    magicsq[row][col] = 1;

    for (x = 2; x <= 3 * 3; x++)
    {
        int r = row - 1, c = col - 1;
        if (r < 0) r += 3;
        if (c < 0) c += 3;
        if (magicsq[r][c] > 0)
        {
            row++;
            if (row >= 3) row -= 3;
        }
        else
        {
            row = r;
            col = c;
        }
        magicsq[row][col] = x;
    }

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
            cout << magicsq[i][j] << " ";
        cout << endl;
    }

    int mcg = 3;
    int** pseudo;
    int y;
    int z;
    cin >> z;
    cin >> y;
    pseudo = new int* [z];

    for (int i = 0; i < z; i++) {
        pseudo[i] = new int[y];
    }


    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            pseudo[i][j] = magicsq[i][j];
        }
    }

    for (int i = 0; i < z; i++) {                          
        for (int j = 0; j < z; j++) {                         
            int m = i;                              
            int n = j;                              

            if (n % 3 == 0) {
                n = 0;
            }
            else if ((n - 1) % 3 == 0) {
                n = 1;
            }
            else if ((n - 2) % 3 == 0) {
                n = 2;
            }
            if (m % 3 == 0) {
                m = 0;
            }
            else if ((m - 1) % 3 == 0) {
                m = 1;
            }
            else if ((m - 2) % 3 == 0) {
                m = 2;
            }
            pseudo[i][j] = magicsq[m][n];

        }
    }

    for (int i = 0; i < z; i++) {
        for (int j = 0; j < y; j++) {
            cout << setw(5) << pseudo[i][j];
        }
        cout << endl;
    }
}