#include "LedCubeController.h"

LedCubeController cube;

void setup() {}

void loop() {
  cube.clear();
  cube.all();
  delay(1000);

  cube.clear();
  delay(500);
  cube.each();

  cube.clear();
  delay(500);
  for (int k = 0; k < 4; k++) {
    cube.curtain();
  }

  cube.clear();
  delay(500);
  for (int k = 0; k < 4; k++) {
    cube.upDown();
  }

  cube.clear();
  delay(500);
  for (int k = 0; k < 500; k++) {
    cube.frame();
  }

  cube.clear();
  delay(500);

  for (int k = 0; k < 15; k++) {
    cube.clear();
    cube.rand();
    delay(200);
  }
}
