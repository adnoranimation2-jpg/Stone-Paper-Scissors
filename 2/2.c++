#include <iostream>
using namespace std;

struct  stAddress
{
    string Street1;
    string POBOX;
};


struct  stOwner
{
    string FullName;
    string Phone;
    stAddress Address;


};


struct Car{
    string Brand;
    string Model;
    int Year;
    stOwner Owner;

};

int main()
{
    // // 1
    // Car MyCar1;

    // MyCar1.Brand = "BMW";
    // MyCar1.Model = "X5";
    // MyCar1.Year = 2000;

    // cout << MyCar1.Brand << " " << MyCar1.Model<< " " << MyCar1.Year << "\n";

    // return 0;



    // // 2
    // Car MyCar1, MyCar2, x;


    // MyCar1.Brand = "BMW";
    // MyCar1.Model = "X5";
    // MyCar1.Year = 2000;

    // MyCar1.Owner.FullName = "Adam Youssef";
    // MyCar1.Owner.Phone = "01558218281";

    // MyCar2.Brand = "Ford";
    // MyCar2.Model = "Mustang";
    // MyCar2.Year = 2022;

    // x.Brand = "Toyota";
    // x.Model = "xhjasdhf";
    // x.Year = 1980;

    // // Outputting the results
    // cout << MyCar1.Brand << " " << MyCar1.Model << " " << MyCar1.Year << endl;
    // cout << MyCar2.Brand << " " << MyCar2.Model << " " << MyCar2.Year << endl;
    // cout << x.Brand << " " << x.Model << " " << x.Year << endl;

    // return 0;

    // // 3
    Car MyCar1, MyCar2, x;


    MyCar1.Brand = "BMW";
    MyCar1.Model = "X5";
    MyCar1.Year = 2000;

    MyCar1.Owner.FullName = "Adam Youssef";
    MyCar1.Owner.Phone = "01558218281";

    MyCar1.Owner.Address.POBOX = "";
    
    cout << MyCar1.Brand << " " << MyCar1.Model << " " << MyCar1.Year << endl;
    cout << MyCar1.Owner.FullName << endl;
    cout << MyCar1.Owner.Phone << endl;
}