// Copyright (c) 2020 [Your Name]. All rights reserved.

#include <cinder/app/App.h>
#include <cinder/app/RendererGl.h>

#include "hot_shot.h"

using cinder::app::App;
using cinder::app::RendererGl;


namespace myapp {

const int kSamples = 8;
const int kWidth = 800;
const int kHeight = 800;

void SetUp(App::Settings* settings) {
  settings->setWindowSize(kWidth, kHeight);
  settings->setTitle("Hot Shot");
}

}  // namespace myapp


// This is a macro that runs the application.
CINDER_APP(myapp::HotShot,
           RendererGl(RendererGl::Options().msaa(myapp::kSamples)),
           myapp::SetUp)
