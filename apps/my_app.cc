// Copyright (c) 2020 [Your Name]. All rights reserved.

#include "my_app.h"
#include <cinder/app/App.h>
#include <cinder/app/RendererGl.h>
#include <cinder/gl/gl.h>

using namespace ci;
using namespace ci::app;


namespace myapp {

using cinder::app::KeyEvent;

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
  mylibrary::DrawBall();
}

void MyApp::keyDown(KeyEvent event) { }

void MyApp::mouseMove( MouseEvent event ) {
  ivec2 mMouseLoc = event.getPos();
  std::cout << mMouseLoc;
}

void MyApp::mouseDrag( MouseEvent event ) {
  mouseMove( event );
}



}  // namespace myapp

