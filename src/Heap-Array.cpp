#include<Heap-Array.h>
#include<Util.h>

Heap_Array::Heap_Array(int l_size)
{
if(l_size <= 0)
{
l_size=10;
}
p = new int[l_size];
size = l_size;
length=0;
}

void Heap_Array::print_heap()
{
cout << "heap elements: " << endl;
for(int i=0; i< length; i++) 
cout << *(p+i) << " ";
cout << endl;
}

void Heap_Array::up_heapify(int pos)
{
cout << "node number for up_heapify" << pos+1 << endl;
if(pos <= 0)
{
return;
}
int parent_index=get_parent_index(pos);
if(*(p+pos) < *(p+parent_index))
{
Util::swap(*(p+pos),*(p+parent_index));
} 
else
{
return;
}
up_heapify(parent_index);
}

void Heap_Array::down_heapify(int pos_index)
{
int left_index=get_left_child_index(pos_index);
int right_index=left_index+1;
cout << "node number for down_heapify" << pos_index+1 << endl;
if(left_index+1>= length) //Leaf node
{
//Can't go further
return;
}
int small_index = right_index;
if(*(p+left_index) < *(p+right_index))
{
 small_index=left_index;
}
if(*(p+small_index) < *(p+pos_index))
{
cout << "root is swapped with node " << *(p+small_index) << endl;
swap(*(p+small_index), *(p+pos_index));
down_heapify(small_index);
}
else
{
return;
}
}

void Heap_Array::push(int value)
{
if(length+1 >= size)
{
//No re-sizing required;
}
else
{
//re-size;
}
*(p+length)=value;

up_heapify(length++);
cout << "push ";
print_heap();
}


int Heap_Array::pop()
{
int retval = *(p+0);
*(p+0)=*(p+length-1);
length--;
down_heapify(0);
cout << "pop ";
print_heap();
return retval;
}

void test1(Heap_Array & ha)
{
ha.push(100);
ha.push(30);
ha.push(60);
ha.push(80);
ha.push(50);
ha.push(51);
ha.print_heap();
cout << "ha.pop result " << ha.pop() << endl;
cout << "ha.pop result " << ha.pop() << endl;
cout << "ha.pop result " << ha.pop() << endl;
cout << "ha.pop result " << ha.pop() << endl;
cout << "ha.pop result " << ha.pop() << endl;
cout << "ha.pop result " << ha.pop() << endl;
}
int main()
{
Heap_Array ha(20);
test1(ha);
}
