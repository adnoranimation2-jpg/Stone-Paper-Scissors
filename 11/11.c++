#include <iostream>
#include <string>

using namespace std;

int x = 300;

int MyFunction1()
{
    int x = 500;

    cout << "The value of x inisde function is: "<< x << endl;
    return 0;
}

int main()
{
    int x = 10;

    cout << "The local value of x inisde Main is: " << x <<  endl;
    MyFunction1();

    ::x = 7000;

    cout << "The Global Value of x is: " << ::x << endl;
    
    return 0;
}
