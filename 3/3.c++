#include <iostream>
using namespace std;

enum Color { Red, Green, Yellow, Blue };
enum Direction { North, South, East, West };
enum Week { Sat, Sun, Mon, Tue, Wed, Thu, Fri };
enum Gendor { Male, Female };
enum Status { Single, Married};


int main()
{
    Color MyColor;
    Direction MyDirection;
    Week Today;
    Status MyStatus;

    MyColor = Color::Yellow;

    MyDirection = Direction::North;
    Today = Week::Sun;
    MyStatus = Status::Single;

    cout << "Color is: " << MyColor << endl;
    cout << "Direction is: " << MyDirection << endl;
    cout << "Today is: " << Today << endl;
    cout << "Status is: " << MyStatus << endl;

    return 0;
}