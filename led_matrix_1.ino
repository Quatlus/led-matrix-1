#include "LedControl.h" // https://github.com/wayoda/LedControl/releases
#include "Mover.h" //https://www.youtube.com/watch?v=TQ_WZU5s_VA

LedControl lc = LedControl(12, 10, 11, 2);

const int8_t size_mleds = 8;

Mover mleds[size_mleds] {
  { 0, 0, 0, 0 }, { 1, 0, 0, 0 }, { 2, 0, 0, 0 }, { 3, 0, 0, 0 }, { 4, 0, 0, 0 }, { 5, 0, 0, 0 }, { 6, 0, 0, 0 }, { 7, 0, 0, 0 }
};

float poti_vertical, poti_horizontal;

int delayTime = 10;
unsigned long old = millis();

void setup() {

  //Serial.begin(9600);

  lc.shutdown(0, false);
  lc.setIntensity(0, 1);
  lc.clearDisplay(0);
  randomSeed(analogRead(A0));

}

void loop() {

  if (old + delayTime < millis() ) {

    old = millis();
    lc.clearDisplay(0);

    for (int i = 0; i < size_mleds; i++) {

      poti_vertical = ((analogRead(A4) * .001024) - .5);   // range [-0.5, 0.5]
      poti_horizontal = ((analogRead(A5 ) * .001024) - .5); // range [-0.5, 0.5]

      mleds[i].setVelocity(poti_horizontal, poti_vertical);

      mleds[i].update();
      mleds[i].edges();

      lc.setLed(0, mleds[i].ly, mleds[i].lx, 1);

    }
  }
}
