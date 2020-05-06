// Copyright (c) 2020 Parth Savla. All rights reserved.
#include <cinder/app/App.h>
#include <cinder/app/RendererGl.h>
#include <cinder/gl/gl.h>
#include <mylibrary/board.h>

using namespace ci;
using namespace ci::app;

/** speed multiplier for board **/
const double speed = 0.5;
/** board image scaling factor **/
const int scale_factor = 12;

namespace mylibrary {

/** Texture ref object **/
gl::TextureRef board_texture;

Board::Board() {
  x_position = 0;
  x_boundary = 80;
}

void Board::SetUp() {
  auto img = loadImage(loadAsset("basketball.png"));
  board_texture = gl::Texture::create(img);
  board_texture->bind();
}

void Board::DrawBoard() const {
  gl::setMatricesWindow(getWindowSize());
  gl::translate(x_position, getWindowCenter().y - vert_y_offset);
  gl::color(Color(1, 1, 1));
  Rectf drawRect(0, 0, board_texture->getWidth() / scale_factor,
                 board_texture->getHeight() / scale_factor);
  gl::draw(board_texture, drawRect);
}

void Board::UpdatePos(int score) {
  if (x_position <= getWindowWidth()) {
    x_position += (speed) * (speed * score + 1);
  } else {
    x_position = 0;
  }
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

double Board::GetYPos() { return getWindowCenter().y - vert_y_offset; }

}  // namespace mylibrary
