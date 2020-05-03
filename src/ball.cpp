//
// Created by Parth Savla on 4/26/20.
//

#include <mylibrary/ball.h>
#include <cinder/app/App.h>
#include <cinder/app/RendererGl.h>
#include <cinder/gl/gl.h>

using namespace cinder;
using namespace ci;
using namespace ci::app;

const Color basketball_color = Color(1,0.67,0);
const int speed = 2;

namespace mylibrary {

double Ball::y_position = 0;
double Ball::x_position = 400;

Ball::Ball() {

}

void Ball::DrawBall() {
  gl::setMatricesWindow(getWindowSize());
  gl::color(basketball_color);
  gl::drawSolidCircle(getWindowCenter() + vec2(0, 250), 25);
}

double Ball::MoveBall() {
  gl::setMatricesWindow(getWindowSize());
  gl::translate(getWindowCenter().x - 400, -y_position);
  gl::color(basketball_color);
  gl::drawSolidCircle(getWindowCenter() + vec2(0, 250), 25);
  if (y_position <= getWindowCenter().y - 100) {
    y_position += 5;
  } else {
    y_position = 0;
  }

  return y_position;
}

double Ball::MouseMoveBall(std::vector<vec2> cd) {
  float des_x = cd.back()[0];
  float des_y = cd.back()[1];
  float org_x = (getWindowCenter() + vec2(0,250))[0];
  float org_y = (getWindowCenter() + vec2(0,250))[1];
  float dx = des_x - org_x;
  float dy = des_y - org_y;
  float length = sqrtf(dx*dx+dy*dy);
  dx/=length;
  dy/=length;
  dx *= speed;
  dy *= speed;
  gl::setMatricesWindow(getWindowSize());
  gl::pushMatrices();
  gl::translate(getWindowCenter().x - x_position, y_position);
  gl::color(basketball_color);
  gl::drawSolidCircle(getWindowCenter() + vec2(0, 250), 25);
  gl::popMatrices();
  if (abs(y_position) <= getWindowCenter().y - 100) {
    y_position += dy;
  } else {
    y_position = 0;
    x_position = getWindowWidth()/2;
  }

  if (x_position <= getWindowWidth() && x_position >= 0) {
    x_position -= dx;
  } else {
    x_position = getWindowWidth()/2;
    y_position = 0;
  }

  return y_position;
}

double Ball::GetYPos() {
  return y_position;
}

double Ball::GetXPos() {
  return x_position;
}

}