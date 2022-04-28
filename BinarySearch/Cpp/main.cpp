//ArTaZ-binary search implementation // april 28 , 2022 // cPlusPlus // 1 = FOUND // 0 = NOT FOUND
#include <iostream>
using namespace std;
int BinarySearch(int array[10],int x,int left,int right)
{

    if (left > right)
    {
        return 0;
    }
    else
    {
        int mid = (left + right) / 2;
        if (array[mid] == x)
        {
            return 1;
        }
        else
        {
            if (array[mid] > x)
            {
                BinarySearch(array,x,left,mid - 1);
            }
            else
            {
                BinarySearch(array,x,mid + 1,right);
            }
        }
    }
    return -1;
}
int main(void)
{
    int array[10] = {0,1,3,5,7,9,11,13,15,17};
    int x = 0;
    cin >> x;
    cout << BinarySearch(array,x,0,9) << endl;
}
