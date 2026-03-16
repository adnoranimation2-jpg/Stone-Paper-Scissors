#include <iostream>
#include <string>

using namespace std;

void myFunction()
{
    cout << "This is my first function, it got executed :-)" << endl;
}

string myFunction2()
{
    return "This is my first returning value function, this is the value";
}

int MyFunction3()
{
    int x = 10;
    int y = 20;

    return x * y;

}

int main()
{
    int Result;

    Result = MyFunction3();
    
    

    cout << Result << endl;

    // myFunction();
    // cout << myFunction2() << endl;

    return 0;
}