#include <iostream>
using namespace std;

int sum(int n)
{
    if (n == 0)
    {
        return 0;
    }
    int s = 0;
    s = sum(n - 1);
    int ans = n + s;
    return ans;
}

int main()
{
    cout << sum(4) << endl;
}