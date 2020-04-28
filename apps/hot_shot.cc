// Copyright (c) 2020 [Your Name]. All rights reserved.

#include "hot_shot.h"
#include <cinder/app/App.h>
#include <cinder/app/RendererGl.h>
#include <cinder/gl/gl.h>
#include "mylibrary/ball.h"

#include <cmath>
#include <vector>

using namespace ci;
using namespace ci::app;
using cinder::app::KeyEvent;
using std::vector;

const Color background = Color(0.53, 0.81, 0.94);
const int y_boundary = 100;
const int x_boundary = 80;


namespace myapp {


vector<vec2> cd;

HotShot::HotShot() {
}

void HotShot::setup() {
  mylibrary::Board::SetUp();
  gl::enableDepthWrite();
  gl::enableDepthRead();
}

void HotShot::update() {
  DrawScore();
  if (lives == 0) {
    std::cout << "Game over";
    game_state = true;
  }
}

void HotShot::UpdateScore() {
  double x_pos = mylibrary::Board::GetXPos();
  double y_pos = mylibrary::Ball::GetYPos();
  cinder::vec2 center = getWindowCenter();
  if (y_pos >= center.y - y_boundary) {
    space_pressed = false;
    mouse_pressed = false;
    cd.clear();
    if (x_pos >= center.x - x_boundary && x_pos <= center.x + x_boundary) {
      score++;
    } else {
      lives--;
    }
  }
}

void HotShot::draw() {
  cinder::gl::clear(background);
  mylibrary::Board::DrawBoard(score);
  gl::setMatricesWindow( getWindowSize());
  if (space_pressed) {
    mylibrary::Ball::MoveBall();
    UpdateScore();
  } else {
    mylibrary::Ball::DrawBall();
  }


  if (mouse_pressed) {
    mylibrary::Ball::MouseMoveBall(cd);
    UpdateScore();
  } else {
    mylibrary::Ball::DrawBall();
  }

  DrawScore();

  if (game_state) {
    cinder::gl::clear(background);
    DrawGameOver();
  }

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

void HotShot::keyDown(KeyEvent event) {
  if (event.getCode() == KeyEvent::KEY_SPACE) {
    space_pressed = true;
  }
}

void HotShot::mouseDrag( MouseEvent event ) {
  //std::cout << event.getPos() << std::endl;
  cd.push_back(event.getPos());
}

void HotShot::mouseDown(MouseEvent event) {
  if (event.isRight()) {
    std::cout << "clicked";
    mouse_pressed = true;
    cd.push_back(event.getPos());
  }
}

template <typename C>
void HotShot::PrintText(const std::string& text, const C& color, const cinder::ivec2& size,
                        const cinder::vec2& loc) {
  cinder::gl::color(color);

  auto box = TextBox()
      .alignment(TextBox::CENTER)
      .font(cinder::Font("Arial", 30))
      .size(size)
      .color(color)
      .backgroundColor(ColorA(0, 0, 0, 0))
      .text(text);

  const auto box_size = box.getSize();
  const cinder::vec2 locp = {loc.x - box_size.x / 2, loc.y - box_size.y / 2};
  const auto surface = box.render();
  const auto texture = cinder::gl::Texture::create(surface);
  cinder::gl::draw(texture, locp);
}

void HotShot::DrawScore() {
  const cinder::vec2 center = getWindowCenter();
  const cinder::ivec2 size = {500, 50};
  const Color color = Color::black();
  std::stringstream ss;
  ss << score;
  PrintText("Score: " + ss.str(), color, size, {center.x - 200, center.y - 300});
}

void HotShot::DrawGameOver() {
  const cinder::vec2 center = getWindowCenter();
  const cinder::ivec2 size = {500, 50};
  const Color color = Color::black();
  std::stringstream ss;
  ss << score;
  PrintText("Game Over :( You scored: " + ss.str() + " points", color, size, {center.x, center.y});
}



}  // namespace myapp

