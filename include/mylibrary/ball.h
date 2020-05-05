//
// Created by Parth Savla on 4/26/20.
//

#ifndef FINALPROJECT_BALL_H
#define FINALPROJECT_BALL_H

#include <cinder/app/App.h>
#include <cinder/app/RendererGl.h>
#include <cinder/gl/gl.h>

using namespace cinder;
using namespace ci;
using namespace ci::app;


namespace mylibrary {
  class Ball {
   public:
    /** Constructor that sets x,y position and change in x,y (dx,dy) **/
    Ball();
    /** Sets the balls initial location**/
    void SetBall() const;
    /** Draws the ball at the updated position **/
    void DrawBall();
    /** Getter for ball's y position **/
    double GetYPos();
    /** Getter for ball's x position **/
    double GetXPos();
    /**
     * Updates change in position per frame based of mouse click
     * @param dest vector coordiantes of mouse click destination
     */
    void UpdateVelocity(vec2 dest);
    /** Updates x and y position of ball **/
    void UpdatePos();
   private:
    /** board's x_position **/
    double y_position;
    /** board's x_position **/
    double x_position;
    /** change in board's x_position **/
    float dx;
    /** change in board's y_position **/
    float dy;
  };
}
#endif  // FINALPROJECT_BALL_H
