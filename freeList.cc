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
  head[0] = old size - reserve_size - 2;

  return loc;
}

void
freeList::free_space( long int* location ) {
long int* prev = head;
head = location - 2;
head[1] = prev;
}

void
freeList::coalesce_forward() {
bool can_coalesce = true;
long int* traveling_point = head;

while (can_coalesce = true){
  if(travel_point[1] != NULL) && (travel_point[1] == traveling_point[0] + 2 + traveling_point) {

  long int* nextOne = traveling_point[1];
  traveling_point[1]  = nextOne[1];
  travelling_point[0] = traveling_point[0] + 2 + nextOne[0];
  
}
  else{
  can_coalesce = false;
  traveling_point = traveling_point[1];
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
