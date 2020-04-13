#include <iostream>

using namespace std;

int main()
{
    int B,S;
    cin>>B>>S;
    cout<<S/B<<" "<<B-(S-(S/B)*B);
    return 0;
}
