#include "freeList.h"

freeList::freeList( long int*inRAM, int size ) {
  head = inRAM;
  head[0] = size - 2;
}

long int*
freeList::reserve_space( int reserve_size ) {
  long int* loc = NULL;
  int old_size = head[0];
  head[0] = reserve_size;
  head[1] = 123456;
  loc = head + 2;
  head = head + reserve_size + 2;
  head[0] = old_size - reserve_size - 2;

  return loc;
}

void
freeList::free_space( long int* location ) {
long int* prev = head;
head = location - 2;
head[1] = (long int)prev;
}

void
freeList::coalesce_forward() {
bool can_coalesce = true; // can_coalesce variable set to true
long int* traveling_point = head; //new pointer pointing to head

while (can_coalesce == true){
  if(((long int*)traveling_point[1] != NULL) && (traveling_point[1] == traveling_point[0] + 2 +(long int) traveling_point)) {
//condition to check if the free list continues and that traveling_point[1] is pointing to the next free list)

  long int* nextOne =(long int*) traveling_point[1];// a new pointer at traveling_point[1]
  traveling_point[1]  = nextOne[1];
  traveling_point[0] = traveling_point[0] + 2 + nextOne[0]; //traveling_point[0] updated with thesize of coalsced free list. 
  
}
  else{
  can_coalesce = false; //set can_coalse to false is above conditions are not met
  traveling_point =(long int*) traveling_point[1]; 
  }



}
}

// print() is given to you. It traverses the free list and prints out what is there.
void freeList::print() {
  long int * printHead = head;
  
  while( printHead != NULL ) {
    cout << "at " << printHead << "("<< dec <<printHead[0] << " : 0x" << hex << printHead[1] <<  ")\n";
    printHead = (long int *)printHead[1];
  }
}

