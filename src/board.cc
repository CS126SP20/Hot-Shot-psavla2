// Copyright (c) 2020 [Your Name]. All rights reserved.
#include <mylibrary/board.h>
#include <cinder/app/App.h>
#include <cinder/app/RendererGl.h>
#include <cinder/gl/gl.h>

using namespace ci;
using namespace ci::app;

namespace mylibrary {

double Board::x_position = 0;
gl::TextureRef mTexture;

void Board::SetUp() {
      auto img = loadImage( loadAsset( "basketball.png" ) );
      mTexture = gl::Texture::create( img );
      mTexture->bind();
}

double Board::DrawBoard(int score) {
  gl::setMatricesWindow( getWindowSize());
  gl::translate(x_position, getWindowCenter().y - 100);
  gl::color( Color( 1, 1, 1 ) );
  Rectf drawRect( 0, 0, mTexture->getWidth() / 12,
                  mTexture->getHeight() / 12 );
  gl::draw(mTexture, drawRect);

  if (x_position <= getWindowWidth()) {
    x_position += 0.5 * (0.5 * score + 1);
  } else {
    x_position = 0;
  }

  return x_position;
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

double Board::GetXPos() {
  return x_position;
}

}  // namespace mylibrary
