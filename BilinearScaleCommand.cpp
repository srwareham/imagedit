//
//  BilinearScaleCommand.cpp
//  imagedit
//
//  Created by Sean Wareham on 12/4/13.
//  Copyright (c) 2013 Sean Wareham. All rights reserved.
// NOTE: at present this is not truely bilinear interpolation.  It is a more simplified algorithm which involves taking the
// average pixel value across the 4 nearest pixels and using that value.  True interpolation would result in the new pixel
// not necessarily being equadistant from its 4 closest neighbors.
//

#include "BilinearScaleCommand.h"

inline float BilinearScaleCommand::interpolate( float val1, float val2, float coord1, float coord2, float dist){
    
    float seperation = coord2 - coord1;
    
    float slope = (val2 - val1) / seperation;
    
    return dist * slope;
}


Image* BilinearScaleCommand::execute(Image* image){
    int origWidth = image->getWidth();
    int origHeight = image->getHeight();
    int max = image->getMax();
    
    //if using percentage
    if (scaleByPercent > 0){
        myNewH = (int) (origWidth * (scaleByPercent/100.0));
        myNewW = (int) (origHeight * (scaleByPercent/100.0));
    }
    
    
    //these are to index in the original image.  Need heuristic for discrepency between actual value and new value
    int dX = 2;
    int dY = 2;
    
    myNewH = origHeight / dY;
    myNewW = origWidth /dX;
    
    
    
    
    Image* scaled = new Image(myNewW, myNewH, max);
    
    float*** originalImage = image->getImage();
    float*** newImage = scaled->getImage();
    
    double widthRatio = ((double) (origWidth)) / (double) myNewW;
    double heightRatio = ((double) (origHeight)) / (double) myNewH;
    
    printf("widthRatio: %f heightRatio %f\n", widthRatio, heightRatio);
    
    int x, y;
    double deltaX, deltaY, x_diff_2, y_diff_2;
    
    
    
    
    for (int i = 0; i < myNewH; i++){
        for (int j=0; j< myNewW; j++){
            float newRed, newGreen, newBlue;
            
            //(0,0) pixel
            float r1 = originalImage[i * dY][j *dX][0];
            float g1 = originalImage[i * dY][j * dX][1];
            float b1 = originalImage[i * dY][j* dX][2];
            
            //(1,0) pixel
            float r2 = originalImage[i* dY][j*dX +1][0];
            float g2 = originalImage[i * dY][j*dX+1][1];
            float b2 = originalImage[i * dY][j*dX+1][2];
            
            //(0,1) pixel
            float r3 = originalImage[i * dY+1][j *dX][0];
            float g3 = originalImage[i * dY +1][j * dX][1];
            float b3 = originalImage[i * dY +1][j* dX][2];
            
            //(1,1) pixel
            float r4 = originalImage[i * dY+1][j *dX+1][0];
            float g4 = originalImage[i * dY +1][j * dX+1][1];
            float b4 = originalImage[i * dY +1][j* dX+1][2];
            
            newRed = (r1 + r2 + r3 + r4)/4.0;
            newGreen = (g1 + g2 + g3 + g4)/4.0;
            newBlue = (b1 + b2 + b3 + b4)/4.0;
//            newRed = interpolate(r1, r2, 0, 0, .5);
//            newGreen = interpolate(g1, g2, 0, 0, .5);
//            newBlue = interpolate(b1, b2, 0, 0, .5);
            
            
            newImage[i][j][0] = newRed;
            newImage[i][j][1] = newGreen;
            newImage[i][j][2] = newBlue;
        }
    }
            
//            x = (int) (widthRatio * j);//idealized x
//            y = (int) (heightRatio * i);
//            deltaX = (int)(widthRatio *j) - x; //delta from ideal
//            deltaY = (int)(heightRatio * i) -y;
//            
//            y_diff_2 = 1-deltaY;
//            x_diff_2 = 1- deltaX;
//            
//            printf("x: %d y: %d\n", x, y);
//            printf("deltaX: %f deltaY %f\n", deltaX, deltaY);
            
//            double const y2_cross_x2 = y_diff_2 * x_diff_2;
//            double const y2_cross_x = y_diff_2 * deltaX;
//            double const y_cross_x2 = deltaY * x_diff_2;
//            double const y_cross_x = deltaY * deltaX;
            
//            for (int color =0; color<3; color++){
//                newImage[i][j][color] = y2_cross_x2 *originalImage[i][j][color] +
//                y2_cross_x * originalImage[i][j+1][color] +
//                y_cross_x2 * originalImage[i+1][j][color] +
//                y_cross_x * originalImage[i+1][j+1][color];
//            }
            
            
            
//            int index = y*origWidth + x;
//            
            /*
             red = (c2.red-c1.red)*dx + c1.red;
             green = (c2.green-c1.green)*dx + c1.green;
             blue = (c2,blue-c1.blue)*dx + c1.blue;
             */
//
//            //(0,0) pixel
//            float r1 = originalImage[index][j][0];
//            float g1 = originalImage[index][j][1];
//            float b1 = originalImage[index][j][2];
//            
//            //(1,0) pixel
//            float r2 = originalImage[index][j+1][0];
//            float g2 = originalImage[index][j+1][1];
//            float b2 = originalImage[index][j+1][2];
//            
//            //(0,1) pixel
//            float r3 = originalImage[i+1][j][0];
//            float g3 = originalImage[i+1][j][1];
//            float b3 = originalImage[i+1][j][2];
//            
//            //(1,1) pixel
//            float r4 = originalImage[i+1][j+1][0];
//            float g4 = originalImage[i+1][j+1][1];
//            float b4 = originalImage[i+1][j+1][2];
//
//            
//            
//            
//            newImage[i][j][0] = (r1 * (1-deltaX) * (1-deltaY)) + (r2 * deltaX *(1-deltaY)) + (r3 * (1-deltaX) * deltaY) + (r4 * deltaX * deltaY);
//            newImage[i][j][1] = (g1 * (1-deltaX) * (1-deltaY)) + (g2 * deltaX *(1-deltaY)) + (g3 * (1-deltaX) * deltaY) + (g4 * deltaX * deltaY);
//            newImage[i][j][2] = (b1 * (1-deltaX) * (1-deltaY)) + (b2 * deltaX *(1-deltaY)) + (b3 * (1-deltaX) * deltaY) + (b4 * deltaX * deltaY);
//            //r * (1-deltaX)* (1-deltaY) + g* (deltaX) * (1-deltaY) + b * (1-deltaX);
//
//        }
//        
//    }
    
    /*
     public int[] resizeBilinear(int[] pixels, int w, int h, int w2, int h2) {
     int[] temp = new int[w2*h2] ;
     int a, b, c, d, x, y, index ;
     float x_ratio = ((float)(w-1))/w2 ;
     float y_ratio = ((float)(h-1))/h2 ;
     float x_diff, y_diff, blue, red, green ;
     int offset = 0 ;
     for (int i=0;i<h2;i++) {
     for (int j=0;j<w2;j++) {
     x = (int)(x_ratio * j) ;
     y = (int)(y_ratio * i) ;
     x_diff = (x_ratio * j) - x ;
     y_diff = (y_ratio * i) - y ;
     index = (y*w+x) ;
     a = pixels[index] ;
     b = pixels[index+1] ;
     c = pixels[index+w] ;
     d = pixels[index+w+1] ;
     
     // blue element
     // Yb = Ab(1-w)(1-h) + Bb(w)(1-h) + Cb(h)(1-w) + Db(wh)
     blue = (a&0xff)*(1-x_diff)*(1-y_diff) + (b&0xff)*(x_diff)*(1-y_diff) +
     (c&0xff)*(y_diff)*(1-x_diff)   + (d&0xff)*(x_diff*y_diff);
     
     // green element
     // Yg = Ag(1-w)(1-h) + Bg(w)(1-h) + Cg(h)(1-w) + Dg(wh)
     green = ((a>>8)&0xff)*(1-x_diff)*(1-y_diff) + ((b>>8)&0xff)*(x_diff)*(1-y_diff) +
     ((c>>8)&0xff)*(y_diff)*(1-x_diff)   + ((d>>8)&0xff)*(x_diff*y_diff);
     
     // red element
     // Yr = Ar(1-w)(1-h) + Br(w)(1-h) + Cr(h)(1-w) + Dr(wh)
     red = ((a>>16)&0xff)*(1-x_diff)*(1-y_diff) + ((b>>16)&0xff)*(x_diff)*(1-y_diff) +
     ((c>>16)&0xff)*(y_diff)*(1-x_diff)   + ((d>>16)&0xff)*(x_diff*y_diff);
     
     temp[offset++] =
     0xff000000 | // hardcode alpha
     ((((int)red)<<16)&0xff0000) |
     ((((int)green)<<8)&0xff00) |
     ((int)blue) ;
     }
     }
     return temp ;
     }
     
     */
    
    
    
    return scaled;
}
//TODO: have consistent ordering of width and height throughout codebase
BilinearScaleCommand::BilinearScaleCommand(int newH, int newW) : myNewH(newH), myNewW(newW){};

BilinearScaleCommand::BilinearScaleCommand(double percent){
    if (percent >0){
        scaleByPercent = percent;
    }else {
        //TODO:ERROR
        scaleByPercent = 100.0;
    }
}

std::string BilinearScaleCommand::getStartMessage(){
    char buffer [100];
    int n;
    //if we used a percentage
    if (scaleByPercent >0){
        n = snprintf(buffer, 100, "Scaling Image by: %f%%\n", scaleByPercent);
        //if we used hard coded width and height
    }else {
        n = snprintf(buffer, 100, "Scaling Image to Width: %d Height: %d\n", myNewW, myNewH);
    }
    return std::string(buffer);
}

std::string BilinearScaleCommand::getEndMessage(){
    return "scaled\n";
}
