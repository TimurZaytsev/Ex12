// Copyright 2021 TimurZaytsev
#include <iostream>

#include "TimedDoor.h"

int main() {
  TimedDoor tDoor(5);
  tDoor.lock();
  tDoor.unlock();
  return 0;
}
