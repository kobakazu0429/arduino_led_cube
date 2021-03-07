#include "LedCubeController.h"
#include "Arduino.h"

LedCubeController::LedCubeController() {
  pinMode(SRCLK, OUTPUT);
  pinMode(RCLK, OUTPUT);
  pinMode(SER, OUTPUT);

  randomSeed(analogRead(0));
}

// from 1 to 9 bit: cube anode pins
// from 10 to 12 bit: cube cathode pins (10 is bottom)
// from 13 to 16 bit: none (should filled by 0)
void LedCubeController::sendSerialData(uint16_t pattern) {
  shiftOut(SER, SRCLK, LSBFIRST, pattern);
  shiftOut(SER, SRCLK, LSBFIRST, pattern >> 8);
  digitalWrite(RCLK, LOW);
  digitalWrite(RCLK, HIGH);
}

void LedCubeController::clear() { sendSerialData(0b0000000000000000); }

void LedCubeController::all() {
  const uint16_t all = 0b1111111110000000;
  sendSerialData(all);
}

void LedCubeController::each() {
  for (int layer = 0; layer < 3; layer++) {
    for (int i = 0; i < 9; i++) {
      clear();
      sendSerialData(patterns[layer][i]);
      delay(150);
    }
  }
}

void LedCubeController::frame() {
  const uint16_t frame[] = {0b1111011111100000, 0b1010001011010000,
                            0b1111011110110000};

  for (int layer = 0; layer < 3; layer++) {
    clear();
    sendSerialData(frame[layer]);
    delay(1);
  }
}

void LedCubeController::rand() {
  int layer = random(3);
  int i = random(10);
  sendSerialData(patterns[layer][i]);
}

void LedCubeController::curtain() {
  const uint16_t curtain[] = {
      0b1000000000000000, 0b0100000000000000, 0b0010000000000000,
      0b0000010000000000, 0b0000000010000000, 0b0000000100000000,
      0b0000001000000000, 0b0001000000000000,
  };

  for (int i = 0; i < 8; i++) {
    clear();
    sendSerialData(curtain[i]);
    delay(100);
  }
}

void LedCubeController::upDown() {

  const uint16_t layers[] = {
      0b1111111111100000,
      0b1111111111010000,
      0b1111111110110000,
      0b1111111111010000,
  };

  for (int i = 0; i < 4; i++) {
    clear();
    sendSerialData(layers[i]);
    delay(120);
  }
}
