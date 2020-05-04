// Copyright (c) 2020 CS126SP20. All rights reserved.

#ifndef FINALPROJECT_APPS_MYAPP_H_
#define FINALPROJECT_APPS_MYAPP_H_

#include <cinder/app/App.h>

#include "mylibrary/board.h"

namespace myapp {

class HotShot : public cinder::app::App {
 public:
  /**
   * Empty constructor
   */
  HotShot();
  /**
   * Sets up basketball board, ball, and game audio
   */
  void setup() override;
  /**
   * Updates basketball board and ball positions
   * Checks if game is over
   */
  void update() override;
  /**
   * Draws the basketball board and ball, along with score/lives
   */
  void draw() override;
  /**
   * Checks if the mouse is clicked
   * @param event mouse is clicked down or not
   */
  void mouseDown(MouseEvent event);

 private:
  /** score of the player **/
  size_t score = 0;
  /** number of lives player has**/
  size_t lives = 3;
  /** variable for if game is finished or not**/
  bool is_game_finished = false;
  /** variable for if shot is in progress or not**/
  bool is_shot_in_progress = false;
  /** detination of mouse click for direction **/
  vec2 mouse_dest;
  /**
   * Updates score (checks if basketball collides with basket)
   */
  void UpdateScore();
  /**
   * Helper to print text
   * @param text the text written
   * @param color the color
   * @param size size of the text
   * @param loc location on screen
   */
  template <typename C>
  void PrintText(const std::string& text, const C& color,
                 const cinder::ivec2& size, const cinder::vec2& loc);
  /**
   * Draws the score
   */
  void DrawScore();
  /**
   * Draws the title
   */
  void DrawTitle();
  /**
   * Draws the ending game screen
   */
  void DrawGameOver();
  /**
   * Adds swish sound effect for made basket
   */
  void SwishSound();
};

}  // namespace myapp

#endif  // FINALPROJECT_APPS_MYAPP_H_
