// FaceDetection.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include<opencv2/objdetect.hpp>
#include <iostream>

using namespace std;
using namespace cv;


int main()
{
    
    String path = "Image.jpg";
    Mat img = imread(path);

    CascadeClassifier faceDetects;
    faceDetects.load("haarcascade_frontalface_default.xml");

    vector<Rect> faces;

    faceDetects.detectMultiScale(img, faces,1.3,5); 

    for (int i = 0; i < faces.size(); i++) {
        rectangle(img, faces[i].tl(), faces[i].br(), Scalar(255,255,0), 2);
    }
    putText(img, to_string(faces.size()), Point(10,40), FONT_HERSHEY_PLAIN, 1, Scalar(0,0,0), 1);

    imshow("Window", img);

    waitKey(0);
}


