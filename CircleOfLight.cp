#include<iostream>
using namespace std;

//C++ program to find 
//the minimum number of
//switches to be turned in 
//a circle of bulbs of n > 2

int circleLights(int n,int *lights)
{
	if (n % 3 == 0)
	{
		lights[0] = 1;
		lights[3] = 1;
		int bulb = 2;
		for (int k = 3 ; k <= n / 3; k++)
		{
			lights[(3 * k) + 1] = 1;
			bulb++;
		}
		return bulb;
	}
	else
		return n;
}
//driver code
int main()
{
	int x = 12;
	int arr[12] = { 0 };
	cout << "In case of n divisible by 3: " << circleLights(x, arr) << endl;
	int y = 10;
	int ar[10] = { 0 };
	cout << "In case of n not divisible by 3: " << circleLights(y, ar);
}