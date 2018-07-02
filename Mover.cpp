#include "Mover.h"


Mover::Mover (float x_, float y_, float vx_, float vy_) {
  this->lx = x_;
  this->ly = y_;
  this->vx = vx_;
  this->vy = vy_;
  this->ax = 0;
  this->ay = 0;
}

void Mover::limit(float &var, float max_var) {
  if (var < -max_var) var = -max_var * .8;
  if (var > max_var) var = max_var * .8;

}

void Mover::update() {

  // acceleration changes velocity over time
  this->vx += this->ax;
  this->vy += this->ay;
  Mover::limit(this->vx, .5);
  Mover::limit(this->vy, .5);

  //velocity changes location over time
  this->lx += this->vx;
  this->ly += this->vy;
}

void Mover::addForce(float ax_, float ay_) {
  this->ax = ax_;
  this->ay = ay_;
}

void Mover::setVelocity(float vx_, float vy_) {
  this->vx = vx_;
  this->vy = vy_;
}

void Mover::edges() {
  if (this->lx  > 8) this->lx = 0;
  if (this->lx  < 0) this->lx = 7;
  if (this->ly  > 8) this->ly = 0;
  if (this->ly  < 0) this->ly = 7;
}

void Mover::display() {

}

int Mover::getx() {
  return round(this->lx);
}

int Mover::gety() {
  return round(this->ly);
}
