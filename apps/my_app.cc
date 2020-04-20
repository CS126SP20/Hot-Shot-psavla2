// Copyright (c) 2020 [Your Name]. All rights reserved.

#include "my_app.h"

#include <cinder/app/App.h>
#include <cinder/app/RendererGl.h>
#include <cinder/gl/gl.h>

using namespace ci;
using namespace ci::app;


namespace myapp {

float xpos = 0;
gl::TextureRef mTexture;
using cinder::app::KeyEvent;

MyApp::MyApp() {
}

void MyApp::setup() {
  auto img = loadImage( loadAsset( "basketball.png" ) );
  mTexture = gl::Texture::create( img );
  mTexture->bind();
  gl::enableDepthWrite();
  gl::enableDepthRead();
}

void MyApp::update() {

}

void MyApp::draw() {
  gl::clear();
  // reset the matrices
  gl::setMatricesWindow( getWindowSize());
  gl::translate(xpos, getWindowCenter().y);
  gl::color( Color( 1, 1, 1 ) );
  Rectf drawRect( 0, 0, mTexture->getWidth() / 15,
                  mTexture->getHeight() / 15 );
  gl::draw( mTexture, drawRect );
  /*gl::translate(xpos, getWindowCenter().y);
  gl::color( Color( 1, 0, 0 ) );
  gl::drawSolidCircle( vec2( 0 ), 70 );*/
  if (xpos <= 800) {
    xpos += 0.5;
  } else {
    xpos = 0;
  }

}

void MyApp::keyDown(KeyEvent event) { }

}  // namespace myapp
