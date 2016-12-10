#include<iostream>

#include<DoubleKey.h>
#include <map>
#include <stdlib.h>

int main()
{

DoubleKey *dk[300];
string str1,str2;
str1.assign("ref");
str2.assign("ctx");
for(int i=0;i<300;i++)
{
str1.append("a");
str2.append("b");
dk[i] = new DoubleKey(str1,str2);
//dk[i]->print();
}

map<DoubleKey*,bool> lMap;

for(int i=0;i<10;i++)
{
lMap[dk[i]]=true;
}

DoubleKey *pk[300];
str1.assign("ref1");
str2.assign("ctx1");
for(int i=0;i<50;i++)
{
str1.append("a");
str2.append("b");
pk[i] = new DoubleKey("",str2);
//pk[i]->print();
}

system("date");
for(int j=0;j<200000;j++)
{
for(int i=0;i<50;i++)
{
map<DoubleKey*,bool>::iterator it=lMap.begin();
for(;it!=lMap.end();it++)
{
if(*(it->first) == *pk[i])
{
cout << "Match found for" ;
pk[i]->print();
}
}
}
}
system("date");
system("date");
for(int j=0;j<200000;j++)
{
for(int i=0;i<50;i++)
{
if(lMap.find(pk[i]) !=lMap.end())
{
cout << "Match found for" ;
pk[i]->print();
}
}
}
system("date");

}
