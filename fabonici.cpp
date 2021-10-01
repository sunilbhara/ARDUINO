#include<iostream>
using namespace std;

int fabo(int a)
{
    if(a<2)
    {
        return 1;
    }
    return (fabo(a-2) + fabo(a-1));
}
int main()
{
    int n;
    cout<<"Enter the nth turm of febonic series "<<endl;
    cin>>n;
    cout<<"In febonic series "<<n<<"th element is : "<<fabo(n)<<endl;
    return 0;
}