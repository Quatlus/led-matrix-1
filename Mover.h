#include <Arduino.h>

class Mover {
  public:
    float lx; // location x
    float ly; // location y
    float vx; // velocity x
    float vy; // velocity y
    float ax; // acceleration x
    float ay; // acceleration y

  public:
    Mover (float x_, float y_, float vx_, float vy_);
    void update();
    void limit(float &var, float max_var);
    void setVelocity(float vx_, float vy_);
    void addForce(float ax_, float ay_);
    void edges();
    void display();
    int getx();
    int gety();
};
