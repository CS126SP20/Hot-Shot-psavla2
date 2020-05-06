// Copyright (c) 2020 Parth Savla. All rights reserved.

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

/** background color for game **/
const Color background = Color(0.53, 0.81, 0.94);
/** orange color **/
const Color orange = Color(1,0.67,0);
/** size of the font*/
const cinder::ivec2 font_size = {500, 50};
/** score location on screen **/
const int score_loc = 200;
/** title location on screen **/
const int title_loc = 300;

namespace myapp {

/** voice ref object **/
cinder::audio::VoiceRef background_audio;
/** voice ref object **/
cinder::audio::VoiceRef basket_made_sound;
/** ball object **/
mylibrary::Ball ball;
/** board object **/
mylibrary::Board board;


HotShot::HotShot() {

}

void HotShot::setup() {
  ball = mylibrary::Ball();
  board = mylibrary::Board();
  mylibrary::Board::SetUp();
  gl::enableDepthWrite();
  gl::enableDepthRead();
  mouse_dest = ball.GetStartPos();
  cinder::audio::SourceFileRef aud = cinder::audio::
      load(cinder::app::loadAsset("game_audio.wav"));
  background_audio = cinder::audio::Voice::create(aud);
  background_audio->start();
}

void HotShot::update() {
  board.UpdatePos(score);
  if (is_shot_in_progress) {
    ball.SetVelocity(mouse_dest);
    ball.UpdatePos();
  }
  if (lives == 0) {
    is_game_finished = true;
  }
}

void HotShot::draw() {
  cinder::gl::clear(background);
  DrawTitle();
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

void HotShot::mouseDown(MouseEvent event) {
  if (event.isRight()) {
    is_shot_in_progress = true;
    mouse_dest = event.getPos();
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

template <typename C>
void HotShot::PrintText(const std::string& text, const C& color, const
cinder::ivec2& size, const cinder::vec2& loc) {
  cinder::gl::color(color);
  auto box = TextBox()
      .alignment(TextBox::CENTER)
      .font(cinder::Font("Arial", 30))
      .size(size)
      .color(color)
      .backgroundColor(ColorA(0, 0, 0, 0))
      .text(text);

  const auto box_size = box.getSize();
  const cinder::vec2 new_loc = {loc.x - box_size.x / 2,
                                loc.y - box_size.y / 2};
  const auto surface = box.render();
  const auto texture = cinder::gl::Texture::create(surface);
  cinder::gl::draw(texture, new_loc);
}

void HotShot::SwishSound() {
  cinder::audio::SourceFileRef swish = cinder::audio::
      load(cinder::app::loadAsset("ball.wav"));
  basket_made_sound = cinder::audio::Voice::create(swish);
  basket_made_sound->start();
}
void HotShot::DrawScore() {
  const cinder::vec2 center = getWindowCenter();
  std::stringstream score_stream;
  score_stream << score;
  std::stringstream life_stream;
  for (int i = 0; i < lives; i++) {
    life_stream << "🏀";
  }
  PrintText("Score: " + score_stream.str() + "            Lives: " +
  life_stream.str(), orange, font_size,
  {center.x - score_loc, center.y - score_loc});
}

void HotShot::DrawTitle() {
  const cinder::vec2 center = getWindowCenter();
  PrintText("HOT SHOT 🏀🔥", orange, font_size,
      {center.x, center.y - title_loc});
}

void HotShot::DrawGameOver() {
  const cinder::vec2 center = getWindowCenter();
  background_audio->stop();
  const Color color = Color::black();
  std::stringstream score_stream;
  score_stream << score;
  PrintText("Game Over :( You scored: " + score_stream.str() + " points",
      color, font_size, {center.x, center.y});

}

}  // namespace myapp

