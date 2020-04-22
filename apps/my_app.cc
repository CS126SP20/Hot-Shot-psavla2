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

int score  = 0;
using cinder::app::KeyEvent;
vector<vec2> cd;

MyApp::MyApp() {
}

void MyApp::setup() {
  mylibrary::SetUp();
  gl::enableDepthWrite();
  gl::enableDepthRead();
}

template <typename C>
void PrintText(const std::string& text, const C& color, const cinder::ivec2& size,
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

void MyApp::update() {

}

void MyApp::draw() {
  cinder::gl::clear(Color(0.53, 0.81, 0.94));
  double x_pos = mylibrary::DrawBoard();
  //std::cout << "CENTER" << x_pos;
  gl::setMatricesWindow( getWindowSize());
  if (pressed) {
    double y_pos = mylibrary::MoveBall();
    if (y_pos >= getWindowCenter().y - 100) {
      pressed = false;
    }


    if (y_pos == getWindowCenter().y - 100 && x_pos >= getWindowCenter().x - 7  0 && x_pos <= getWindowCenter().x + 70) {
      score++;
    }
  } else {
    mylibrary::DrawBall();
  }

  const cinder::vec2 center = getWindowCenter();
  const cinder::ivec2 size = {500, 50};
  const Color color = Color::black();
  std::stringstream ss;
  ss << score;
  std::cout << ss.str();
  PrintText("Score: ", color, size, {center.x - 200, center.y - 300});
  PrintText(ss.str(), color, size, {center.x - 130, center.y - 260});
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

