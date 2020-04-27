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
using std::vector;
bool pressed = false;
const Color background = Color(0.53, 0.81, 0.94);


namespace myapp {

int score  = 0;
using cinder::app::KeyEvent;
vector<vec2> cd;

HotShot::HotShot() {
}

void HotShot::setup() {
  mylibrary::Board::SetUp();
  gl::enableDepthWrite();
  gl::enableDepthRead();
}

void HotShot::update() {

}

void HotShot::draw() {
  cinder::gl::clear(background);
  double x_pos = mylibrary::Board::DrawBoard();
  gl::setMatricesWindow( getWindowSize());
  if (pressed) {
    double y_pos = mylibrary::Ball::MoveBall();
    if (y_pos >= getWindowCenter().y - 100) {
      pressed = false;
    }


    if (y_pos == getWindowCenter().y - 100 && x_pos >= getWindowCenter().x - 70 && x_pos <= getWindowCenter().x + 70) {
      score++;
    }
  } else {
    mylibrary::Ball::DrawBall();
  }

  PrintScore();
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

void HotShot::keyDown(KeyEvent event) {
  if (event.getCode() == KeyEvent::KEY_SPACE) {
    pressed = true;
  }
}

void HotShot::mouseDrag( MouseEvent event ) {
  //std::cout << event.getPos() << std::endl;
  cd.push_back(event.getPos());
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

void HotShot::PrintScore() {
  const cinder::vec2 center = getWindowCenter();
  const cinder::ivec2 size = {500, 50};
  const Color color = Color::black();
  std::stringstream ss;
  ss << score;
  PrintText("Score: " + ss.str(), color, size, {center.x - 200, center.y - 300});
}




}  // namespace myapp

