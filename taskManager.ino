#include <TaskManagerIO.h>

int leds[] = {3, 5, 6, 9, 10, 11};
int states[] = {LOW, LOW, LOW, LOW, LOW, LOW};

void change(int &state, int led)
{
  state = !state;
  digitalWrite(led, state);
}

void setup() {
  for (int led : leds) {
    pinMode(led, OUTPUT);
  }

  taskManager.scheduleFixedRate(50, [] {
    change(states[0], leds[0]);
  }, TIME_MICROS);
      
  taskManager.scheduleFixedRate(500, [] {
    change(states[1], leds[1]);
  }, TIME_MICROS);
      
  taskManager.scheduleFixedRate(1000, [] {
    change(states[2], leds[2]);
  }, TIME_MICROS);
      
  taskManager.scheduleFixedRate(15000, [] {
    change(states[3], leds[3]);
  }, TIME_MICROS);
      
  taskManager.scheduleFixedRate(50000, [] {
    change(states[4], leds[4]);
  }, TIME_MICROS);
      
  taskManager.scheduleFixedRate(200000, [] {
    change(states[5], leds[5]);
  }, TIME_MICROS);
}

void loop() {
  taskManager.runLoop();
}
