#include "freeList.h"

freeList::freeList( long int*inRAM, int size ) {
  head = inRAM
  head[0] = size - 2
}

long int*
freeList::reserve_space( int reserve_size ) {
  long int* loc = NULL;
  int old_size = head[0]
  head[0] = reserve_size
  head[1] = 123456 
   loc = head + 2
  head = head + reserve_size + 2
  head[0] = old size - reserve_size - 2

  return loc;
}

void
freeList::free_space( long int* location ) {
}

void
freeList::coalesce_forward() {
}

// print() is given to you. It traverses the free list and prints out what is there.
void freeList::print() {
  long int * printHead = head;
  
  while( printHead != NULL ) {
    cout << "at " << printHead << "("<< dec <<printHead[0] << " : 0x" << hex << printHead[1] <<  ")\n";
    printHead = (long int *)printHead[1];
  }
}
