#include <iostream>
using namespace std;

enum enColor { Red, Green, Yellow, Blue };
enum enGendor { Male, Female };
enum enMaritalStatus { Single, Married};


struct stAddress
{
    string StreetName;
    string BuildingNo;
    string POBox;
    string ZipCode;
};


struct  stContactInfo
{
    string Phone;
    string Email;
    stAddress Address;
};


struct stPerson
{

    string FirstName;
    string LastName;

    stContactInfo ContactInfo;

    enMaritalStatus MaritalStatus;
    enGendor Gendor;
    enColor FavourateColor;
};


int main()
{

    stPerson Person1;

    Person1.FirstName = "Adam";
    Person1.LastName = "youssef";

    Person1.ContactInfo.Email = "adnor.animation@gmail.com";
    Person1.ContactInfo.Phone = "01558218281";
    Person1.ContactInfo.Address.POBox = "777";
    Person1.ContactInfo.Address.ZipCode = "11194";
    Person1.ContactInfo.Address.StreetName = "Queen1 Street";
    Person1.ContactInfo.Address.BuildingNo = "313";

    Person1.Gendor = enGendor::Male;
    Person1.MaritalStatus = enMaritalStatus::Single;
    Person1.FavourateColor = enColor::Blue;


    cout << Person1.FirstName << endl;
    cout << Person1.LastName << endl;

    cout << Person1.ContactInfo.Email << endl;
    cout << Person1.ContactInfo.Phone << endl;
    cout << Person1.ContactInfo.Address.POBox << endl;
    cout << Person1.ContactInfo.Address.ZipCode << endl;
    cout << Person1.ContactInfo.Address.StreetName << endl;
    cout << Person1.ContactInfo.Address.BuildingNo << endl;

    cout << Person1.Gendor << endl;
    cout << Person1.MaritalStatus << endl;
    cout << Person1.FavourateColor << endl;




    return 0;
}