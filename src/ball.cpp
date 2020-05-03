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
const vec2 start_position = vec2(0,250);

namespace mylibrary {

//double Ball::y_position = 0;
//double Ball::x_position = 400;

Ball::Ball() {
  y_position = 0;
  x_position = 400;
}

void Ball::DrawBall() {
  gl::setMatricesWindow(getWindowSize());
  gl::color(basketball_color);
  gl::drawSolidCircle(getWindowCenter() + start_position, 25);
}

double Ball::MoveBall(vec2 dest) {
  float des_x = dest[0];
  float des_y = dest[1];
  float org_x = (getWindowCenter() + start_position)[0];
  float org_y = (getWindowCenter() + start_position)[1];
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
  gl::drawSolidCircle(getWindowCenter() + start_position, 25);
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