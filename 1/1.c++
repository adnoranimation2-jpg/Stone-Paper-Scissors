#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    // sqrt

    double x = 64;
    cout << sqrt(x) << endl; // gives 8
    cout << sqrt(50) << endl; // gives 7.07107

    // return 0;


    // round

    cout << round(2.4) << endl; // gives 2
    cout << round(2.5) << endl; // gives 3
    cout << round(2.7) << endl; // gives 3

    cout << sqrt(50) << endl; // gives 7.07107
    cout << round(sqrt(50)) << endl; // gives 7

    // return 0 ;


    // pow

    x = 2;
    int y = 4;

    cout << pow(x, y) << endl; // gives 16
    cout << pow(4, 3) << endl; // gives 64


    // return 0 ;


    // ceil & floor

    cout << ceil(2.9) << endl; // gives 3
    cout << floor(2.9) << endl; // gives 2

    cout << ceil(-2.9) << endl; // gives -2
    cout << floor(-2.9) << endl; // gives -3

    // return 0 ;


    // abs
    cout << abs(-10) << endl; // gives 10
    cout << abs(10) << endl; // gives 10

    // return 0 ;
}