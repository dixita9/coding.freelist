#include "freeList.h"

freeList::freeList( long int*inRAM, int size ) {
  head = inRAM
  size = size - 2
}

long int*
freeList::reserve_space( int reserve_size ) {
  long int* loc = NULL;
  int old_size = size
  head[0] = reserve_size
  head[1] = 123456  
  
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
