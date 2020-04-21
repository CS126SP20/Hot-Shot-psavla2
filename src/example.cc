// Copyright (c) 2020 [Your Name]. All rights reserved.

#include <mylibrary/example.h>
#include <cinder/app/App.h>
#include <cinder/app/RendererGl.h>
#include <cinder/gl/gl.h>

using namespace ci;
using namespace ci::app;

namespace mylibrary {

float xpos = 0;
float ypos = 0;
gl::TextureRef mTexture;
float y = 400;

void SetUp() {
      auto img = loadImage( loadAsset( "basketball.png" ) );
      mTexture = gl::Texture::create( img );
      mTexture->bind();
}

double DrawBoard() {
  gl::setMatricesWindow( getWindowSize());
  gl::translate(xpos, getWindowCenter().y - 100);
  gl::color( Color( 1, 1, 1 ) );
  //std::cout << mTexture->getWidth() << mTexture->getHeight();
  Rectf drawRect( 0, 0, mTexture->getWidth() / 12,
                  mTexture->getHeight() / 12 );
  gl::draw( mTexture, drawRect );

  if (xpos <= 800) {
    xpos += 0.5;
  } else {
    xpos = 0;
  }

  return xpos;
}

void DrawBall() {
  gl::setMatricesWindow( getWindowSize());
  gl::color( Color( 1, 0.67, 0 ) );
  gl::drawSolidCircle( getWindowCenter() + vec2(0, 250), 25 );
}

double MoveBall() {
  gl::setMatricesWindow( getWindowSize());
  gl::translate(getWindowCenter().x - 400, -ypos);
  gl::color( Color( 1, 0.67, 0.67 ) );
  gl::drawSolidCircle( getWindowCenter() + vec2(0, 250), 25 );
  if (ypos <= getWindowCenter().y - 100) {
    ypos += 5;
  } else {
    ypos = 0;
  }
  return ypos;
}

double Slope(std::vector<vec2> cd) {
  float sumx=0,sumy=0,sumxy=0,sumx2=0;
  double a,b;
  int n = cd.size();
  for(int i=0;i<=n;i++)
  {
    sumx = sumx + cd[i][0];
    sumx2 = sumx2 +cd[i][0] * cd[i][0];
    sumy = sumy + cd[i][1];
    sumxy = sumxy + cd[i][1]*cd[i][0];

  }
  a =((sumx2*sumy -sumx*sumxy)*1.0/(n*sumx2-sumx*sumx)*1.0);
  b =((n*sumxy-sumx*sumy)*1.0/(n*sumx2-sumx*sumx)*1.0);
  return b;

}
}  // namespace mylibrary
