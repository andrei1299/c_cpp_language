#include <iostream>

using namespace std;

int main()
{
    int x,y,n;
    int a,z,h;
    cin>>x>>y>>n;
    a = n/(y*x);
    z = (n-a*(y*x))/y;
    h = n-a*(y*x)-z*y;
    cout<<a<<"\n"<<z<<"\n"<<h;
    return 0;
}
