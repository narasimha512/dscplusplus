#include<iostream>

using namespace std;

int main()
{

int min=2;
int max=11;

int min_index = 0;
int max_index = 0;

min_index %= min;
max_index %= max;

cout << "min index" << min_index << endl;
cout << "max index" << max_index << endl;
min_index++;
max_index++;

min_index %= min;
max_index %= max;

cout << "min index" << min_index << endl;
cout << "max index" << max_index << endl;
}
