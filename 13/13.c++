#include <iostream>
#include <string>

using namespace std;

struct strInfo
{
    string FirstName;
    string LastName;
    int Age;
    string Phone;
};


void ReadInfo(strInfo &Info)
{

    cout << "Please enter your FirstName?\n";
    cin >> Info.FirstName;

    cout << "Please enter your LastName?\n";
    cin >> Info.LastName;

    cout << "Please enter your Age?\n";
    cin >> Info.Age;

    cout << "Please enter your Phone?\n";
    cin >> Info.Phone;


}

void PrintInfo(strInfo Info)
{

    cout << "\n***********************************\n";

    cout << "FirstName: " << Info.FirstName << endl;
    cout << "LastName: " << Info.LastName << endl;
    cout << "Age: " << Info.Age << endl;
    cout << "Phone: " << Info.Phone << endl;

    cout << "\n***********************************\n";


}



int main()
{
    
    strInfo Person1Info;
    ReadInfo(Person1Info);
    PrintInfo(Person1Info);


    strInfo Person2Info;
    ReadInfo(Person2Info);
    PrintInfo(Person2Info);


    return 0;
}