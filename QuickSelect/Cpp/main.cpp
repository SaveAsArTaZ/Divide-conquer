//ArTaz-QuickSelect implemtation // april 28 , 2022 // cPlusPlus
#include <iostream>
using namespace std;
void swap(int &a,int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
    return;
}
int partition(int *array,int left,int right)
{
    int pivot = right;
    int i = left;
    for (int j = left ; j < right ; j++)
    {
        if (array[j] <= array[pivot])
        {
           swap(array[i],array[j]);
           i++;
        }
    }
    swap(array[i],array[right]);
    return i;
}
int KthSmallest(int *array,int left,int right,int k)
{
    if (k > right - left + 1 || k < 0 )
    {
        return INT_FAST8_MAX;
    }
    else
    {
        int pi = partition(array,left,right);
        if (pi - left == k - 1)
        {
            return array[pi];
        }
        else if (pi - left > k - 1)
        {
            return KthSmallest(array,left,pi - 1,k);
        }
        return KthSmallest(array,pi + 1,right,k - pi + left - 1);
    }
}
int main(void)
{
    int size = 0, k = 0;
    cout << "Enter Size Of Array :" << endl;
    cin >> size;
    int *array = new int[size];
    cout <<"Enter array Elements :" << endl;
    for (int i = 0 ; i < size ; i++)
    {
        cout << i + 1 << "'th Element : ";
        cin >> array[i];
    }
    cout << "Enter k'th smallest number : ";
    cin >> k;
    cout << "Answer is : " << KthSmallest(array,0,size - 1,k) << endl;
}
