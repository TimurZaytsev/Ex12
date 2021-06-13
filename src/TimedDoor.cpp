// Copyright 2021 TimurZaytsev
#include "TimedDoor.h"

#include <time.h>

#include <string>

TimedDoor::TimedDoor(int time) {
  iTimeout = time;
  opened = false;
  adapter = new DoorTimerAdapter(*this);
}

bool TimedDoor::isDoorOpened() { return opened; }

void TimedDoor::lock() { opened = false; }

void TimedDoor::unlock() {
  this->opened = true;
  adapter->Timeout();
}

void TimedDoor::DoorTimeOut() { throw std::string("close the door!"); }

void TimedDoor::throwState() {
  if (!opened) throw std::string("the door is closed!");
}

DoorTimerAdapter::DoorTimerAdapter(TimedDoor& door) : door(door) {}

int TimedDoor::getTime() const { return iTimeout; }

void DoorTimerAdapter::Timeout() {
  Timer t;
  t.tregister(door.getTime(), this);
  door.DoorTimeOut();
}

void Timer::sleep(int sec) {
  time_t tic = clock();
  while (clock() < tic + sec * CLOCKS_PER_SEC) {
  }
}

void Timer::tregister(int time, TimerClient* timer) { sleep(time); }
