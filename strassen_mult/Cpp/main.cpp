#include <iostream>
using namespace std;
int** initializeMatrix(int n)
{
    int** result = new int*[n];
    for(int i=0; i<n; i++)
        result[i] = new int[n];
    return result;
}
void input(int **matrix,int n)
{
    for (int i = 0; i < n ;i++)
    {
        for (int j = 0 ; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }
}
void setToZero(int **matrix,int n)
{
    for (int i = 0; i < n ;i++)
    {
        for (int j = 0 ; j < n; j++)
        {
            matrix[i][j] = 0;
        }
    }
}
int** add(int** M1, int** M2, int n) {
    int **c = new int *[n];
    for (int i = 0 ; i < n; ++i)
    {
        c[i] = new int[n];
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            c[i][j] = M1[i][j] + M2[i][j];
        }
    }
    return c;
}
int** sub(int** M1, int** M2, int n) {
    int **c = new int *[n];
    for (int i = 0 ; i < n; ++i)
    {
        c[i] = new int[n];
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            c[i][j] = M1[i][j] - M2[i][j];
        }
    }
    return c;
}
int** normal_mult(int **A, int **B,int n)
{
    int **c = new int *[n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0 ; j < n ; j++)
        {
            c[i][j] = 0;
            for (int k = 0 ; k < n; k++)
            {
                c[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return c;
}
int** strassen(int **A,int **B,int n)
{
    if (n <= 20)
    {
        int** c = initializeMatrix(n);
        setToZero(c,n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0 ; j < n; j++)
            {
                for (int k = 0 ; k < n; k++)
                {
                    c[i][j] += (A[i][k] * B[k][j]);
                }
            }
        }
        return c;
    }
    else
    {
        int **c = initializeMatrix(n);
        int **a11 = initializeMatrix(n/2);
        int **a12 = initializeMatrix(n/2);
        int **a21 = initializeMatrix(n/2);
        int **a22 = initializeMatrix(n/2);
        int **b11 = initializeMatrix(n/2);
        int **b12 = initializeMatrix(n/2);
        int **b21 = initializeMatrix(n/2);
        int **b22 = initializeMatrix(n/2);
        for(int i=0; i<n/2; i++)
        {
            for(int j=0; j<n/2; j++)
            {
                a11[i][j] = A[i][j];
                a12[i][j] = A[i][(n/2)+j];
                a21[i][j] = A[(n/2)+i][j];
                a22[i][j] = A[(n/2)+i][(n/2)+j];
                b11[i][j] = B[i][j];
                b12[i][j] = B[i][(n/2)+j];
                b21[i][j] = B[(n/2)+i][j];
                b22[i][j] = B[(n/2)+i][(n/2)+j];
            }
        }

        int** P1 = strassen(a11, sub(b12, b22, (n/2)), (n/2));
        int** P2 = strassen(add(a11, a12, (n/2)), b22, (n/2));
        int** P3 = strassen(add(a21, a22, (n/2)), b11, (n/2));
        int** P4 = strassen(a22, sub(b21, b11, (n/2)), (n/2));
        int** P5 = strassen(add(a11, a22, (n/2)), add(b11, b22, (n/2)), (n/2));
        int** P6 = strassen(sub(a12, a22, (n/2)), add(b21, b22, (n/2)), (n/2));
        int** P7 = strassen(sub(a11, a21, (n/2)), add(b11, b12, (n/2)), (n/2));
        int** C11 = sub(add(add(P5, P4, n/2), P6, n/2), P2, (n/2));
        int** C12 = add(P1, P2, (n/2));
        int** C21 = add(P3, P4, (n/2));
        int** C22 = sub(sub(add(P5, P1, (n/2)), P3, (n/2)), P7, (n/2));

        for(int i=0; i<n/2; i++)
        {
            for(int j=0; j<n/2; j++)
            {
                c[i][j] = C11[i][j];
                c[i][j+(n/2)] = C12[i][j];
                c[(n/2)+i][j] = C21[i][j];
                c[(n/2)+i][n/2+j] = C22[i][j];
            }
        }

        for(int i=0; i<n/2; i++)
        {
            delete[] a11[i];
            delete[] a12[i];
            delete[] a21[i];
            delete[] a22[i];
            delete[] b11[i];
            delete[] b12[i];
            delete[] b21[i];
            delete[] b22[i];
            delete[] P1[i];
            delete[] P2[i];
            delete[] P3[i];
            delete[] P4[i];
            delete[] P5[i];
            delete[] P6[i];
            delete[] P7[i];
            delete[] C11[i];
            delete[] C12[i];
            delete[] C21[i];
            delete[] C22[i];
        }
        delete[] a11;
        delete[] a12;
        delete[] a21;
        delete[] a22;
        delete[] b11;
        delete[] b12;
        delete[] b21;
        delete[] b22;
        delete[] P1;
        delete[] P2;
        delete[] P3;
        delete[] P4;
        delete[] P5;
        delete[] P6;
        delete[] P7;
        delete[] C11;
        delete[] C12;
        delete[] C21;
        delete[] C22;
        return c;
    }
}
void print_array(int **array,int size)
{
    for (int i = 0 ; i < size ; i++)
    {
        for (int j = 0 ; j < size ; j++)
        {
            cout <<array[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    int size = 0;
    cin >> size;
    int **A = initializeMatrix(size);
    int **B = initializeMatrix(size);
    int **C = initializeMatrix(size);
    input(A,size);
    input(B,size);
    setToZero(C,size);
    C = strassen(A,B,size);
    print_array(C,size);
    for (int i = 0 ; i < size ; i++)
    {
        delete[] A[i];
        delete[] B[i];
        delete[] C[i];
    }
    return 0;
}
