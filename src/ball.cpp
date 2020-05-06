//
// Created by Parth Savla on 4/26/20.
//

#include <cinder/app/App.h>
#include <cinder/app/RendererGl.h>
#include <cinder/gl/gl.h>
#include <mylibrary/ball.h>
#include <mylibrary/board.h>

using namespace cinder;
using namespace ci;
using namespace ci::app;

/** color for basketball **/
const Color basketball_color = Color(1, 0.67, 0);
/** speed of ball shot **/
const int speed = 2;

namespace mylibrary {

Ball::Ball() {
  start_position = vec2(0, 250);
  y_position = 0;
  x_position = 400;
  dx, dy = 0;
  ball_radius = 25;
}

void Ball::SetBall() const {
  gl::setMatricesWindow(getWindowSize());
  gl::color(basketball_color);
  gl::drawSolidCircle(getWindowCenter() + start_position, ball_radius);
}

void Ball::DrawBall() const {
  gl::setMatricesWindow(getWindowSize());
  gl::pushMatrices();
  gl::translate(getWindowCenter().x - x_position, y_position);
  gl::color(basketball_color);
  gl::drawSolidCircle(getWindowCenter() + start_position, ball_radius);
  gl::popMatrices();
}

void Ball::SetVelocity(vec2 dest) {
  gl::setMatricesWindow(getWindowSize());
  float des_x = dest[0];
  float des_y = dest[1];
  float org_x = (getWindowCenter() + start_position)[0];
  float org_y = (getWindowCenter() + start_position)[1];
  dx = normalize(vec2(des_x - org_x, des_y - org_y))[0];
  dy = normalize(vec2(des_x - org_x, des_y - org_y))[1];
  dx *= speed;
  dy *= speed;
}

void Ball::UpdatePos() {
  if (abs(y_position) <= getWindowCenter().y - Board().vert_y_offset) {
    y_position += dy;
  } else {
    y_position = 0;
    x_position = getWindowWidth() / 2;
  }

  if (x_position <= getWindowWidth() && x_position >= 0) {
    x_position -= dx;
  } else {
    x_position = getWindowWidth() / 2;
    y_position = 0;
  }
}

vec2 Ball::GetStartPos() {
    return start_position;
}
double Ball::GetYPos() { return y_position; }

double Ball::GetXPos() { return x_position; }

}  // namespace mylibrary