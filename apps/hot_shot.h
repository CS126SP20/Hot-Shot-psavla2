// Copyright (c) 2020 CS126SP20. All rights reserved.

#ifndef FINALPROJECT_APPS_MYAPP_H_
#define FINALPROJECT_APPS_MYAPP_H_

#include <cinder/app/App.h>

#include "mylibrary/board.h"

namespace myapp {

class HotShot : public cinder::app::App {
 public:
  HotShot();
  void setup() override;
  void update() override;
  void draw() override;
  void keyDown(cinder::app::KeyEvent) override;
  // void mouseMove(cinder::app::MouseEvent event);
  void UpdateScore();
  void mouseDrag(cinder::app::MouseEvent event);
  template <typename C>
  void PrintText(const std::string& text, const C& color, const cinder::ivec2& size,
                         const cinder::vec2& loc);
  void DrawScore();
  void DrawGameOver();
  void mouseDown(MouseEvent event);
  void SwishSound();
private:
    size_t score  = 0;
    size_t lives  = 3;
    bool game_state = false;
    bool space_pressed = false;
    bool mouse_pressed = false;
    std::vector<vec2> mouse_dest;
};

}  // namespace myapp

#endif  // FINALPROJECT_APPS_MYAPP_H_
