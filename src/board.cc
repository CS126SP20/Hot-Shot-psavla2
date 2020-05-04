// Copyright (c) 2020 [Your Name]. All rights reserved.
#include <mylibrary/board.h>
#include <cinder/app/App.h>
#include <cinder/app/RendererGl.h>
#include <cinder/gl/gl.h>

using namespace ci;
using namespace ci::app;

const double speed  = 0.5;
const double x_boundary = 80;

namespace mylibrary {

gl::TextureRef mTexture;

Board::Board() {
  x_position = 0;
}
void Board::SetUp()   {
      auto img = loadImage( loadAsset( "basketball.png" ));
      mTexture = gl::Texture::create( img );
      mTexture->bind();
}

void Board::DrawBoard() {
  gl::setMatricesWindow( getWindowSize());
  gl::translate(x_position, getWindowCenter().y - 100);
  gl::color( Color( 1, 1, 1 ) );
  Rectf drawRect( 0, 0, mTexture->getWidth() / 12,
                  mTexture->getHeight() / 12 );
  gl::draw(mTexture, drawRect);

}

void Board::UpdatePos(int score) {
  if (x_position <= getWindowWidth()) {
    x_position += 0.5 * (speed * score + 1);
  } else {
    x_position = 0;
  }
}
double Board::GetXPos() {
  return x_position;
}

bool Board::GetShotOutcome(double x) {
  cinder::vec2 center = getWindowCenter();
  double board_x = x_position;
  double ball_x = x;
  if (board_x >= getWindowWidth() - ball_x - x_boundary &&
      board_x <= getWindowWidth() - ball_x + x_boundary) {
    return true;
  } else {
    return false;
  }
}

double Board::GetYPos() {
  return getWindowCenter().y - 100;
}

}  // namespace mylibrary
