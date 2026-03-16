#include <iostream>
#include <string>

using namespace std;

int main() {
    // // 1

    // string str= "123.4567";

    // // convert string to Integer
    // int num_int = stoi(str);

    // // convert string to float
    // float num_float = stof(str);

    // // convert string to double
    // double num_double = stod(str);

    // cout << "num_int = " << num_int << endl;
    // cout << "num_float = " << num_float << endl;
    // cout << "num_double = " << num_double << endl;

    // return 0 ;


    // // 2
    int Num1 = 123;
    double Num2 = 18.99;
    
    string St1, St2;
    St1 = to_string(Num1);
    St2 = to_string(Num2);

    cout << St1 << endl;
    cout << St2 << endl;

    return 0;
}