//ArTaZ-MergeSort implementation // april 28 , 2022 // cPlusPlus
#include <iostream>
using namespace std;
void merge(int *array,int left,int mid,int right)
{
    int left_size = mid - left + 1;
    int right_size = right - mid;
    int *L = new int[left_size];
    int *R = new int[right_size];
    for (int i = 0; i < left_size;i++)
    {
        L[i] = array[left + i];
    }
    for (int i = 0; i < right_size; i++)
    {
        R[i] = array[mid + i + 1];
    }
    int i = 0 , j = 0 , k = left;
    while (i < left_size && j < right_size)
    {
        if (L[i] <= R[j])
        {
            array[k] = L[i];
            i++;
        }
        else
        {
            array[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < left_size)
    {
        array[k] = L[i];
        i++;
        k++;
    }
    while (j < right_size)
    {
        array[k] = R[j];
        j++;
        k++;
    }
    delete []L;
    delete []R;
    return;
}
void mergesort(int *array,int left,int right)
{
    if ( left >= right )
    {
        return;
    }
    else
    {
        int mid = left + ((right - left) / 2);
        mergesort(array,left,mid);
        mergesort(array,mid + 1,right);
        merge(array,left,mid,right);
        return;
    }
}
void print_array(int *array,int size)
{
    for (int i = 0 ; i < size; i++)
    {
        cout << i + 1 << "'th Element : " << array[i] <<endl;
    }
}
int main(void)
{
    int size = 0;
    cout << "Enter Size Of Array :" <<endl;
    cin >> size;
    int *array = new int[size];
    cout <<"Enter array Elements :" << endl;
    for (int i = 0 ; i < size; i++)
    {
        cout << i + 1 << "'th Element : ";
        cin >> array[i];
    }
    mergesort(array,0,size - 1);
    cout << "------After Sorting------" << endl;
    print_array(array,size);
    delete []array;
    return 0;
}
