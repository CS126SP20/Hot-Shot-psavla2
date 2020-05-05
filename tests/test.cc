// Copyright (c) 2020 CS126SP20. All rights reserved.

#define CATCH_CONFIG_MAIN

#include <cinder/Rand.h>
#include <mylibrary/board.h>
#include <mylibrary/ball.h>
#include <cinder/app/App.h>
#include <cinder/gl/gl.h>
#include </Users/parthsavla/Downloads/Cinder/my-projects/final project/apps/hot_shot.h>


#include <catch2/catch.hpp>

TEST_CASE("Random sanity test", "[random]") {
  const float random = cinder::randFloat();
  REQUIRE(0. <= random);
  REQUIRE(random <= 1.);
}