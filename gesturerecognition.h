/*------------------------------------------------------------------------------------------*\
   This file contains material supporting chapter 3 of the cookbook:  
   Computer Vision Programming using the OpenCV Library. 
   by Robert Laganiere, Packt Publishing, 2011.

   This program is free software; permission is hereby granted to use, copy, modify, 
   and distribute this source code, or portions thereof, for any purpose, without fee, 
   subject to the restriction that the copyright notice may not be removed 
   or altered from any source or altered source distribution. 
   The software is released on an as-is basis and without any warranties of any kind. 
   In particular, the software is not guaranteed to be fault-tolerant or free from failure. 
   The author disclaims all warranties with regard to this software, any use, 
   and any consequent failure, is purely the responsibility of the user.
 
   Copyright (C) 2010-2011 Robert Laganiere, www.laganiere.name
\*------------------------------------------------------------------------------------------*/

#ifndef GESTURERECOGNITION_H
#define GESTURERECOGNITION_H

#include <QMainWindow>
#include <QFileDialog>
#include <QColorDialog>
#include <QTimer>

//sys
#include <iostream>
#include <string>

//OpenCV
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

//color detector, controller, histogram
#include "colorDetectController.h"
#include "colordetector.h"
#include "colorhistogram.h"

namespace Ui {
    class GestureRecognition;
}

class GestureRecognition : public QMainWindow{
    Q_OBJECT
public:
    GestureRecognition(QWidget *parent = 0);
    ~GestureRecognition();

protected:
    void changeEvent(QEvent *e);
    void displayMat(const cv::Mat& img);

    // camera vars
    cv::VideoCapture cap;
    static const int CAMERA = 1;

    //timer
    QTimer* timer;
    bool process;
    bool histEnable;
    cv::Mat histogram;
    ColorHistogram cHist;


    //Main Image
    //cv::Mat image;

private:
    Ui::GestureRecognition *ui;

    int color[3];
    int threshold;

private slots:
    void processColorDetection();
    void showHistogram();
    void pickColor();
    void setImage();
    void toggleCamera();
    void updateTimer();
    void setThreshold(int value);
    void setColor();
    void setColor1(int value);
    void setColor2(int value);
    void setColor3(int value);
};

#endif // GESTURERECOGNITION_H
