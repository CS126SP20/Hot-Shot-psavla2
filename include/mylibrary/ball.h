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
    Ball();
    void SetBall();
    void DrawBall();
    double GetYPos();
    double GetXPos();
    void UpdatePos(vec2 dest);
   private:
    double y_position;
    double x_position;
    float dx;
    float dy;
  };
}
#endif  // FINALPROJECT_BALL_H
