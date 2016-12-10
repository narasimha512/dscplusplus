#include <iostream>


using namespace std;


class DoubleKey
{
private:
string key1;
string key2;

public:
DoubleKey(string s1,string s2);

bool operator==(const DoubleKey& obj1);

void print();
};

