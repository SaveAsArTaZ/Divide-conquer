//ArTaZ-QuickSort implementation // 28 april , 2022 // cPlusPlus
#include <iostream>
using namespace std;
void swap(int &a,int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
    return;
}
int partition(int *array,int low,int high)
{
    int pivot = array[high];
    int i = (low - 1);
    for (int j = low; j < high ; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            if (i != j)
            {
                swap(array[i],array[j]);
            }
        }
    }
    swap(array[i + 1],array[high]);
    return (i + 1);
}
void QuickSort(int *array,int low,int high)
{
    if (low >= high)
    {
        return;
    }
    else
    {
        int pi = partition(array,low,high);
        QuickSort(array,low,pi - 1);
        QuickSort(array,pi + 1,high);
    }
}
void print_array(int *array,int size)
{
    for (int i = 0 ; i < size ; i++)
    {
        cout << i + 1 << "'th element : " << array[i] << endl;
    }
}
int main(void)
{
    int size = 0;
    cout << "Enter Size Of Array :" <<endl;
    cin >> size;
    int *array = new int[size];
    cout <<"Enter array Elements :" << endl;
    for (int i = 0 ; i < size ; i++)
    {
        cout << i + 1 << "'th Element : ";
        cin >> array[i];
    }
    QuickSort(array,0,size - 1);
    print_array(array,size);
    return 0;
}
