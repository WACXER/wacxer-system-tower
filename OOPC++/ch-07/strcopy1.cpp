//Copyimg String the hardway 
//strcopy1.cpp

#include <iostream> 
#include <cstring>

using namespace std;

int main ()
{
    char str1[] = "oh, Captain, my Captain"
                "our fearful trip is done!";

    const int MAX = 80;  //size of str2 buffer 
    char str2[MAX];    //empty 
    int j;
    for ( j =0; j<strlen(str1); j++)  //copy strlen characters 
      str2[j] = str1[j];
    str2[j] ='\0';
    cout << str2 << str1;
    return 0;

    //copy string the easy way 
    char str3[] = "Tiger, tiger, burning bright\n"
                    "In the forest of the night";
    const int MAX = 80;
    char str4 [MAX];

    strcpy(str2, str1);  //copy str1 to str2
    cout << str2 << endl;
    return 0;

    //signature
    //strcpy(destination, source )




}
