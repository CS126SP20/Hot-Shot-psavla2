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
    void DrawBall();
    double MoveBall(vec2 dest);
    double GetYPos();
    double GetXPos();
   private:
    double y_position;
    double x_position;
  };
}
#endif  // FINALPROJECT_BALL_H
