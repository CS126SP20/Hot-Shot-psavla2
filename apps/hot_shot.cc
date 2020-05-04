// Copyright (c) 2020 [Your Name]. All rights reserved.

#include "hot_shot.h"
#include <cinder/app/App.h>
#include <cinder/app/RendererGl.h>
#include <cinder/gl/gl.h>
#include "mylibrary/ball.h"
#include <cinder/audio/Voice.h>

#include <cmath>
#include <vector>

using namespace ci;
using namespace ci::app;
using cinder::app::KeyEvent;
using std::vector;

const Color background = Color(0.53, 0.81, 0.94);

namespace myapp {

cinder::audio::VoiceRef mVoice;
cinder::audio::VoiceRef dVoice;
mylibrary::Ball ball = mylibrary::Ball();
mylibrary::Board board = mylibrary::Board();

HotShot::HotShot() {
}

void HotShot::setup() {
  mylibrary::Board::SetUp();
  gl::enableDepthWrite();
  gl::enableDepthRead();
  mouse_dest = vec2(0,250);
  cinder::audio::SourceFileRef aud = cinder::audio::load(cinder::app::loadAsset("game_audio.wav"));
  mVoice = cinder::audio::Voice::create(aud);
  mVoice->start();
}

void HotShot::update() {
  board.UpdatePos(score);
  ball.UpdatePos(mouse_dest);
  //UpdateScore();
  if (lives == 0) {
    is_game_finished = true;
  }
}

void HotShot::UpdateScore() {
  double ball_y = ball.GetYPos();
  double ball_x = ball.GetXPos();
  cinder::vec2 center = getWindowCenter();
  if (abs(ball_y) >= board.GetYPos()) {
    is_shot_in_progress = false;
    if (board.GetShotOutcome(ball_x)) {
      score++;
      SwishSound();
    } else {
      lives--;
    }
  }
}

void HotShot::draw() {
  cinder::gl::clear(background);
  board.DrawBoard();
  gl::setMatricesWindow( getWindowSize());

  if (is_shot_in_progress) {
    ball.DrawBall();
    UpdateScore();
  } else {
    ball.SetBall();
  }

  DrawScore();

  if (is_game_finished) {
    cinder::gl::clear(background);
    DrawGameOver();
  }
}

void HotShot::keyDown(KeyEvent event) {
}

void HotShot::mouseDown(MouseEvent event) {
  if (event.isRight()) {
    is_shot_in_progress = true;
    mouse_dest = event.getPos();
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

void HotShot::SwishSound() {
  cinder::audio::SourceFileRef swish = cinder::audio::load(cinder::app::loadAsset("ball.wav"));
  dVoice = cinder::audio::Voice::create(swish);
  dVoice->start();
}
void HotShot::DrawScore() {
  const cinder::vec2 center = getWindowCenter();
  const cinder::ivec2 size = {500, 50};
  const Color color = Color::black();
  const Color o = Color(1,0.67,0);
  std::stringstream ss;
  ss << score;
  PrintText("Score: " + ss.str(), color, size, {center.x - 200, center.y - 300});
  std::stringstream ff;
  for (int i = 0; i < lives; i++) {
    ff << "🏀";
  }
  PrintText("Lives: " + ff.str(),o, size, {center.x - 200, center.y - 200});
}

void HotShot::DrawGameOver() {
  mVoice->stop();
  const cinder::vec2 center = getWindowCenter();
  const cinder::ivec2 size = {500, 50};
  const Color color = Color::black();
  std::stringstream ss;
  ss << score;
  PrintText("Game Over :( You scored: " + ss.str() + " points", color, size, {center.x, center.y});

}



}  // namespace myapp

