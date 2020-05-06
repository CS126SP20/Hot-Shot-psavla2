// Copyright (c) 2020 Parth Savla. All rights reserved.
#ifndef FINALPROJECT_MYLIBRARY_EXAMPLE_H_
#define FINALPROJECT_MYLIBRARY_EXAMPLE_H_

#include <cinder/app/App.h>
#include <cinder/app/RendererGl.h>
#include <cinder/gl/gl.h>

using namespace ci;
using namespace ci::app;

namespace mylibrary {
  class Board {
   public:
    /**
     * Constructor that sets initial basketball board x_position
     */
    Board();
    /**
     * Sets up basketball board texture and boundary
     */
    static void SetUp();
    /**
     * Draws board based on position
     */
    void DrawBoard() const;
    /**
     * Updates position based on score
     * @param score score serves as a speed multiplier moving the board
     * faster if the score is higher
     */
    void UpdatePos(int score);
    /**
     * getter for the boards y_position
     * @return the boards vertical y position
     */
    double GetYPos();
    /**
     * Checks if the shot is made or not
     * @param ball_x balls x position
     * @return true if the ball hits the basket, false otherwise
     */
    bool GetShotOutcome(double ball_x);
    /** vertical y offset for board **/
    int vert_y_offset = 100;
   private:
    /** x position error when checking if shot is made **/
    double x_board_boundary;
    /** board's x_position **/
    double x_position;
    /** board's y_position **/
    double y_position;
  };

}  // namespace mylibrary


#endif // FINALPROJECT_MYLIBRARY_EXAMPLE_H_
