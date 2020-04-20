// Copyright (c) 2020 [Your Name]. All rights reserved.

#include <mylibrary/example.h>
#include <cinder/app/App.h>
#include <cinder/app/RendererGl.h>
#include <cinder/gl/gl.h>

using namespace ci;
using namespace ci::app;

namespace mylibrary {

float xpos = 0;
gl::TextureRef mTexture;

void SetUp() {
      auto img = loadImage( loadAsset( "basketball.png" ) );
      mTexture = gl::Texture::create( img );
      mTexture->bind();
}

void DrawBoard() {
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

void DrawBall() {
  gl::setMatricesWindow( getWindowSize());
  gl::color( Color( 1, 0.67, 0 ) );
  gl::drawSolidCircle( getWindowCenter() + vec2(0, 250), 25 );
}

}  // namespace mylibrary
