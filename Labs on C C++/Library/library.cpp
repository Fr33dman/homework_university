#include "iostream"
using namespace std;

struct flat
{
    char *owner;
    int stage;
    int amountRooms;
    double price;
    char *city;
};

int main()
{
   flat flat1;
   flat1 = {(char*)"Ivanov", 15, 2, 4000000, (char*)"Zelenograd"};
   cout << flat1.owner;
}