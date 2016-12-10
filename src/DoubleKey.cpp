#include<iostream>

#include<DoubleKey.h>

DoubleKey::DoubleKey(string s1,string s2):key1(s1),key2(s2)
{
}

bool DoubleKey::operator==(const DoubleKey& obj1)
{
if(!obj1.key1.empty())
return this->key1 == obj1.key1;
else if(obj1.key2.empty())
return this->key2 == obj1.key2;
else
return false;
}

void DoubleKey::print()
{
 cout << "key1:" << key1 << " key2:" << key2 << endl;
}
