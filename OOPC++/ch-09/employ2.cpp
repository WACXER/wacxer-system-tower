//employ2.cpp
//multiple level of inheritance 
#iclude <iostream> 
using namespace std;
const int 80; 
///////////////////////////////////////////////////////
class employee
{
private:
    char name[LEN]; //employee name 
    unsigned long number; //employee number
public: 
    void getdata()
    {
        cout << "\n enter last name: "; cin >> name;
        cout << "   Enter number: "; cin >> number;

    }

    void putdata() const 
    {
        cout << "\n Name: " << name;
        cout << "\n Number:" << number;
    }
}
///////////////////////////////////////////////////////////////
