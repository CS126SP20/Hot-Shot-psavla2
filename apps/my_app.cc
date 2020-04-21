// Copyright (c) 2020 [Your Name]. All rights reserved.

#include "my_app.h"
#include <cinder/app/App.h>
#include <cinder/app/RendererGl.h>
#include <cinder/gl/gl.h>
#include <vector>
#include <cmath>

using namespace ci;
using namespace ci::app;
using std::vector;
bool pressed = false;


namespace myapp {

double ypos = 0;
double xpos = 0;
using cinder::app::KeyEvent;
vector<vec2> cd;

MyApp::MyApp() {
}

void MyApp::setup() {
  mylibrary::SetUp();
  gl::enableDepthWrite();
  gl::enableDepthRead();
}

void MyApp::update() {

}

void MyApp::draw() {
  cinder::gl::clear(Color(0.53, 0.81, 0.94));
  mylibrary::DrawBoard();

  if (pressed) {
    double x = mylibrary::MoveBall();
    if (x >= 400) {
      pressed = false;
    }
  } else {
    mylibrary::DrawBall();
  }
  /*if (!cd.empty()) {
    double x = mylibrary::Slope(cd);
    std::cout << x << std::endl;
    mylibrary::MoveBall(abs(x));
  }*/

  /*double x = 0;
  if (!cd.empty()) {
    x = mylibrary::Slope(cd);
    std::cout << "SLOPE: " << x << "\n";
  }

  gl::setMatricesWindow( getWindowSize());
  if (abs(ypos) <= 400) {
    ypos += x;
    xpos += 0.5;
  } else {
    ypos = 0;
    xpos = 0;
    cd.clear();
  }
  gl::translate(xpos, ypos);
  std::cout << "YPOS: " << ypos << "\n";
  gl::color( Color( 1, 0.67, 0.67 ) );
  gl::drawSolidCircle( getWindowCenter() + vec2(0, 250), 25 );*/
}

void MyApp::keyDown(KeyEvent event) {
  if (event.getCode() == KeyEvent::KEY_SPACE) {
    pressed = true;
  }
}

void MyApp::mouseDrag( MouseEvent event ) {
  //std::cout << event.getPos() << std::endl;
  cd.push_back(event.getPos());
}



}  // namespace myapp

