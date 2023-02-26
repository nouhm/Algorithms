 #include <stdio.h>
#include <iostream>
using namespace std;
int sum(int coins[], int start, int end)
{
	int sum = 0; 
	for (int i = start; i <= end; i++)
	{
		sum += coins[i];
	}
	return sum;
}
int Get_counterfeit(int coins[], int start, int end)
{
	int mid;
	int mid1;
	if ((end - start + 1) % 2 == 0)
	{
		mid = (end + start) / 2;
		mid1 = mid + 1;
		if (sum(coins, start, mid - 1) > sum(coins, mid1 + 1, end))
		{
			Get_counterfeit(coins, mid1 + 1, end);
		}
		else if (sum(coins, start, mid - 1) == sum(coins, mid1 + 1, end))
		{
			if (coins[mid] < coins[mid1])
			{
				return mid;
			}
			else if(coins[mid] > coins[mid1])
			{
				return mid1;
			}
		else {
			return -1;
		}
		}
		else {
			Get_counterfeit(coins, start, mid - 1);
		}
	}
	else {
		mid = (end + start) / 2;
		if (sum(coins, start, mid - 1) > sum(coins, mid + 1, end))
		{
			Get_counterfeit(coins, mid + 1, end);
		}
		else if (sum(coins, start, mid - 1) == sum(coins, mid + 1, end))
		{
			return mid;

		}
		else {
			Get_counterfeit(coins, start, mid - 1);
		}
	}
	
}
int main()
{
	int coins[10] = { 3,3,3,3,3,3,3,3,2,3};
	cout << "the counterfeit coin is at index:"; cout<<Get_counterfeit(coins, 0, 9) << endl;
	cout<<"Its weight ="; cout<<coins[Get_counterfeit(coins, 0, 9)]<<endl;


}