// Copyright (c) 2020 [Your Name]. All rights reserved.
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
    Board();
    static void SetUp();
    static double DrawBoard(int score);
    static double GetXPos();
    bool GetShotOutcome(double x);
   private:
    static double x_position;
  };

}  // namespace mylibrary


#endif // FINALPROJECT_MYLIBRARY_EXAMPLE_H_
