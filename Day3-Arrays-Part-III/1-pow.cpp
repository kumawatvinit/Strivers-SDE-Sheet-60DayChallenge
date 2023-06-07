#include <bits/stdc++.h>
using namespace std;

double myPow(double x, int n)
{
    bool pos = n > 0;
    double ans = 1;

    for (; n != 0; n /= 2)
    {
        if (abs(n) % 2)
        {
            ans = ans * x;
        }
        x *= x;
    }

    if (pos)
        return ans;
    return 1 / ans;
}


// with modulo
int modularExponentiation(int x, int n, int m) {
  bool pos = n > 0;
  int ans = 1;
  x%=m;

  for (; n != 0; n /= 2) {
    if (abs(n) % 2) {
      ans = (1ll*ans*x)%m;
    }
    x = (1ll*x*x)%m;
  }

  if (pos)
    return ans;
  return 1 / ans;
}

int main()
{
    cout << myPow(2, 20) << endl;
    cout << modularExponentiation(2, 20, 1000000007) << endl;
    return 0;
}