// Copyright (c) 2020 [Your Name]. All rights reserved.

#include "my_app.h"

#include <cinder/app/App.h>
#include <cinder/app/RendererGl.h>
#include <cinder/gl/gl.h>

using namespace ci;
using namespace ci::app;


namespace myapp {

float xpos = 0;
int score = 0;
gl::TextureRef mTexture;
gl::TextureRef mTex;
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

template <typename C>
void PrintText(const std::string& text, const C& color, const cinder::ivec2& size,
               const cinder::vec2& loc) {
  cinder::gl::color(color);
}

void MyApp::draw() {
  cinder::gl::clear(Color(0.53, 0.81, 0.94));
  const cinder::vec2 center = getWindowCenter();
  const cinder::ivec2 size = {500, 50};
  const Color color = Color::black();
  PrintText("Score:" + score, color, size, {center.x - 200, center.y - 300});
  // reset the matrices
  gl::setMatricesWindow( getWindowSize());
  gl::translate(xpos, getWindowCenter().y - 100);
  gl::color( Color( 1, 1, 1 ) );
  Rectf drawRect( 0, 0, mTexture->getWidth() / 12,
                  mTexture->getHeight() / 12 );
  gl::draw( mTexture, drawRect );

  if (xpos <= 800) {
    xpos += 0.5;
  } else {
    xpos = 0;
  }

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

