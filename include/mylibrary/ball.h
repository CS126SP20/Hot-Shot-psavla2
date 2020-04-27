//
// Created by Parth Savla on 4/26/20.
//

#ifndef FINALPROJECT_BALL_H
#define FINALPROJECT_BALL_H

#include <cinder/app/App.h>
#include <cinder/app/RendererGl.h>
#include <cinder/gl/gl.h>

using namespace cinder;

namespace mylibrary {
  class Ball {
   public:
    static void DrawBall();
    static double MoveBall();
   private:
    static double y_position;

  };
}
#endif  // FINALPROJECT_BALL_H
