//ArTaZ-large int mult implementation // april 28 , 2022 // cPlusPlus
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
typedef long long ll;
int countDigit(long long n)
{
  return floor(log10(n) + 1);
}
ll modBigNumber(string num, ll m)
{
    vector<int> vec;
    ll mod = 0;
    for (int i = 0; i < num.size(); i++) {

        int digit = num[i] - '0';
        mod = mod * 10 + digit;
        int quo = mod / m;
        vec.push_back(quo);
        mod = mod % m;
    }
    return mod;
}
ll large_integer_mult(ll first, ll second)
{
    ll x,y,w,z,r,p,q;
    int n,m;
    n = max(countDigit(first),countDigit(second));
    if (first == 0 || second == 0)
    {
        return 0;
    }
    else if (n <= 5)
    {
        return first*second;
    }
    else
    {
        m = floor(n/2);
        x = first / pow(10,m);
        y = second / pow(10,m);
        w = modBigNumber(to_string(first),pow(10,m));
        z = modBigNumber(to_string(second),pow(10,m));
        r = large_integer_mult(x + w,y + z);
        p = large_integer_mult(x,y);
        q = large_integer_mult(w,z);
        return p * pow(10,2*m) + (r - p - q) * pow(10,m) + q;
    }
}
int main(void)
{
    ll first = 0,second = 0;
    cin >> first >> second;
    cout << large_integer_mult(first,second) << endl;
    return 0;
}
