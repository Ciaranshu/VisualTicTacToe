#include <iostream>  
#include "opencv2/highgui/highgui.hpp"  
#include "opencv2/imgproc/imgproc.hpp"  
#include<stdlib.h>  
using namespace cv;  
using namespace std;  

 int main()  
 {  
    VideoCapture cap(0); //capture the video from web cam  
  
    if ( !cap.isOpened() )  // if not success, exit program  
    {  
         cout << "Cannot open the web cam" << endl;  
         return -1;  
    }  
 
  int iLowH1 = 155;  
  int iHighH1 = 179;  
  
  int iLowS1 = 90;   
  int iHighS1 = 255;  
  
  int iLowV1 = 10;  
  int iHighV1 = 255;  
   
 
  int iLowH2 = 80;  
  int iHighH2 = 110;  
  
  int iLowS2 = 90;   
  int iHighS2 = 255;  
  
  int iLowV2 = 0;  
  int iHighV2 = 255;  
  

    while (true)  
    {  
        system("cls");
		Mat imgOriginal;  
  
        bool bSuccess = cap.read(imgOriginal); // read a new frame from video  
  
         if (!bSuccess) //if not success, break loop  
        {  
             cout << "Cannot read a frame from video stream" << endl;  
             break;  
        }  
  
   Mat imgHSV;  
   vector<Mat> hsvSplit;  
   cvtColor(imgOriginal, imgHSV, COLOR_BGR2HSV); //Convert the captured frame from BGR to HSV  
  
  //在HSV空间做直方图均衡化
   split(imgHSV, hsvSplit);  
   equalizeHist(hsvSplit[2],hsvSplit[2]);  
   merge(hsvSplit,imgHSV);  
   Mat imgThresholded1;  
  
   inRange(imgHSV, Scalar(iLowH1, iLowS1, iLowV1), Scalar(iHighH1, iHighS1, iHighV1), imgThresholded1); //Threshold the image  
  
   Mat imgThresholded2;  
  
   inRange(imgHSV, Scalar(iLowH2, iLowS2, iLowV2), Scalar(iHighH2, iHighS2, iHighV2), imgThresholded2); //Threshold the image  
  
   //开操作 (去除一些噪点)  
   Mat element = getStructuringElement(MORPH_RECT, Size(5, 5));  
   morphologyEx(imgThresholded1, imgThresholded1, MORPH_OPEN, element);  
   morphologyEx(imgThresholded2, imgThresholded2, MORPH_OPEN, element); 
  
   //闭操作 (连接一些连通域)  
   morphologyEx(imgThresholded2, imgThresholded2, MORPH_CLOSE, element);  
   morphologyEx(imgThresholded2, imgThresholded2, MORPH_CLOSE, element); 
  
   imshow("Thresholded Image1", imgThresholded1); //show the thresholded image1
   imshow("Thresholded Image2", imgThresholded2); //show the thresholded image2
   imshow("Original", imgOriginal); //show the original image  

   int a1=0;
   int b1=0;
   int c1=0;
   int d1=0;
   int e1=0;
   int f1=0;
   int g1=0;
   int h1=0;
   int i1=0;

   int a2=0;
   int b2=0;
   int c2=0;
   int d2=0;
   int e2=0;
   int f2=0;
   int g2=0;
   int h2=0;
   int i2=0;

   
	int count=0;
	for( int i = 0; i<160; ++i )
	{	
		uchar * p = imgThresholded1.ptr<uchar>(i);
		for( int j = 0; j<200; ++j )
		{	 
			if(p[j]==255)
			{ count++;}
		}
	}
	if( count>5000 )
	a1=1;

	count=0;
	for( int i = 0; i<160; ++i )
	{	
		uchar * p = imgThresholded1.ptr<uchar>(i);
		for( int j = 200; j<400; ++j )
		{	 
			if(p[j]==255)
			{ count++;}
		}
	}
	if( count>000 )
	b1=1;

	count=0;
	for( int i = 0; i<160; ++i )
	{	
		uchar * p = imgThresholded1.ptr<uchar>(i);
		for( int j = 400; j<599; ++j )
		{	 
			if(p[j]==255)
			{ count++;}
		}
	}
	if( count>5000 )
	c1=1;

	count=0;
	for( int i = 160; i<320; ++i )
	{	
		uchar * p = imgThresholded1.ptr<uchar>(i);
		for( int j = 0; j<200; ++j )
		{	 
			if(p[j]==255)
			{ count++;}
		}
	}
	if( count>5000 )
	d1=1;

	count=0;
	for( int i = 160; i<320; ++i )
	{	
		uchar * p = imgThresholded1.ptr<uchar>(i);
		for( int j = 200; j<400; ++j )
		{	 
			if(p[j]==255)
			{ count++;}
		}
	}
	if( count>5000 )
	e1=1;

	count=0;
	for( int i = 160; i<320; ++i )
	{	
		uchar * p = imgThresholded1.ptr<uchar>(i);
		for( int j = 400; j<599; ++j )
		{	 
			if(p[j]==255)
			{ count++;}
		}
	}
	if( count>5000 )
	f1=1;
	
	count=0;
	for( int i = 320; i<479; ++i )
	{	
		uchar * p = imgThresholded1.ptr<uchar>(i);
		for( int j = 0; j<200; ++j )
		{	 
			if(p[j]==255)
			{ count++;}
		}
	}
	if( count>5000 )
	g1=1;

	count=0;
	for( int i = 320; i<479; ++i )
	{	
		uchar * p = imgThresholded1.ptr<uchar>(i);
		for( int j = 200; j<400; ++j )
		{	 
			if(p[j]==255)
			{ count++;}
		}
	}
	if( count>5000 )
	h1=1;

	count=0;
	for( int i = 320; i<479; ++i )
	{	
		uchar * p = imgThresholded1.ptr<uchar>(i);
		for( int j = 400; j<599; ++j )
		{	 
			if(p[j]==255)
			{ count++;}
		}
	}
	if( count>5000 )
	i1=1;

	count=0;
	for( int i = 0; i<160; ++i )
	{	
		uchar * p = imgThresholded2.ptr<uchar>(i);
		for( int j = 0; j<200; ++j )
		{	 
			if(p[j]==255)
			{ count++;}
		}
	}
	if( count>5000 )
	a2=-1;

	count=0;
	for( int i = 0; i<160; ++i )
	{	
		uchar * p = imgThresholded2.ptr<uchar>(i);
		for( int j = 200; j<400; ++j )
		{	 
			if(p[j]==255)
			{ count++;}
		}
	}
	if( count>5000 )
	b2=-1;

	count=0;
	for( int i = 0; i<160; ++i )
	{	
		uchar * p = imgThresholded2.ptr<uchar>(i);
		for( int j = 400; j<599; ++j )
		{	 
			if(p[j]==255)
			{ count++;}
		}
	}
	if( count>5000 )
	c2=-1;

	count=0;
	for( int i = 160; i<320; ++i )
	{	
		uchar * p = imgThresholded2.ptr<uchar>(i);
		for( int j = 0; j<200; ++j )
		{	 
			if(p[j]==255)
			{ count++;}
		}
	}
	if( count>5000 )
	d2=-1;

	count=0;
	for( int i = 160; i<320; ++i )
	{	
		uchar * p = imgThresholded2.ptr<uchar>(i);
		for( int j = 200; j<400; ++j )
		{	 
			if(p[j]==255)
			{ count++;}
		}
	}
	if( count>5000 )
	e2=-1;

	count=0;
	for( int i = 160; i<320; ++i )
	{	
		uchar * p = imgThresholded2.ptr<uchar>(i);
		for( int j = 400; j<599; ++j )
		{	 
			if(p[j]==255)
			{ count++;}
		}
	}
	if( count>5000 )
	f2=-1;
	
	count=0;
	for( int i = 320; i<479; ++i )
	{	
		uchar * p = imgThresholded2.ptr<uchar>(i);
		for( int j = 0; j<200; ++j )
		{	 
			if(p[j]==255)
			{ count++;}
		}
	}
	if( count>5000 )
	g2=-1;

	count=0;
	for( int i = 320; i<479; ++i )
	{	
		uchar * p = imgThresholded2.ptr<uchar>(i);
		for( int j = 200; j<400; ++j )
		{	 
			if(p[j]==255)
			{ count++;}
		}
	}
	if( count>5000 )
	h2=-1;

	count=0;
	for( int i = 320; i<479; ++i )
	{	
		uchar * p = imgThresholded2.ptr<uchar>(i);
		for( int j = 400; j<599; ++j )
		{	 
			if(p[j]==255)
			{ count++;}
		}
	}
	if( count>5000 )
	i2=-1;
	
   
   int matrix[3][3]=
   {{a1+a2,b1+b2,c1+c2},{d1+d2, e1+e2, f1+f2},{g1+g2, h1+h2, i1+i2 }};


  cout<<matrix[0][0]<<matrix[0][1]<<matrix[0][2]<<endl
	  <<matrix[1][0]<<matrix[1][1]<<matrix[1][2]<<endl
	  <<matrix[2][0]<<matrix[2][1]<<matrix[2][2]<<endl;

   char key = (char) waitKey(60);  
   if(key == 27)  
         break;  
    }  
  
   return 0;  
  
}  




	





