#include<iostream>
using namespace std;

void change(int i, int s, string x)
{
    while (i < s)
    {
        char* p;
        p = &x[i];
        if (i % 2 == 0)
        {
            if (*p >= 97 && *p <= 122)
            {
                *p = *p - 32;
            }
        }
        if (i % 2 != 0)
        {
            if (*p >= 65 && *p <= 90)
            {
                *p = *p + 32;
            }
        }
        cout << *p;
        i++;
    }
}
int main()
{
    int i = 0, s;
    string x;
    cin >> x;
    s = x.size();     
    change(i,s,x);

    return 0;
}