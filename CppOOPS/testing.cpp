#include "stdio.h"
#include "OrderedList.h"
#include "Stack.h"
#include "Queue.h"
#include "UnorderedList.h"
int main()
{
OrderedList list = OrderedList();
list.insert(1);
list.insert(7);
list.insert(4);
list.insert(5);
list.insert(3);
printf("stack:%s\n", list.toString());
return 1;
}