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
    static void DrawBall();
    static double MoveBall();
    static double MouseMoveBall(std::vector<vec2> cd);
    static double GetYPos();
    static double GetXPos();
   private:
    static double y_position;
    static double x_position;

  };
}
#endif  // FINALPROJECT_BALL_H
