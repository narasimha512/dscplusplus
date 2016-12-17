#include <iostream>

using namespace std;


class Heap_Array
{
private:
int size;
int length;
int *p;

void up_heapify(int pos);
void down_heapify(int pos);

public:
Heap_Array(int p_size);
void push(int value);
int  pop();
bool is_empty();
void p_length()
{
 cout << "length is " << length << endl; 
 cout << "size is " << size << endl; 
}

void print_heap();

int get_parent_index(int pos)
{
return (pos+1)/2-1;
}

int get_left_child_index(int pos)
{
return 2*(pos+1)-1;
}

int get_right_child_index(int pos)
{
return 2*(pos+1);
}

};
