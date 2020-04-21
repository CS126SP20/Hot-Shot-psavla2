// Copyright (c) 2020 CS126SP20. All rights reserved.

#ifndef FINALPROJECT_APPS_MYAPP_H_
#define FINALPROJECT_APPS_MYAPP_H_

#include <cinder/app/App.h>
#include "mylibrary/example.h"


namespace myapp {

class MyApp : public cinder::app::App {
 public:
  MyApp();
  void setup() override;
  void update() override;
  void draw() override;
  void keyDown(cinder::app::KeyEvent) override;
 // void mouseMove(cinder::app::MouseEvent event);
  void mouseDrag(cinder::app::MouseEvent event);
  //void mouseDown(MouseEvent event);
};

}  // namespace myapp

#endif  // FINALPROJECT_APPS_MYAPP_H_
