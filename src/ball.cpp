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

namespace mylibrary {

double Ball::y_position = 0;

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

double Ball::GetYPos() {
  return y_position;
}

}