//-----------------------------------��ͷ�ļ��������֡�---------------------------------------  
//      ����������������������ͷ�ļ�  
//----------------------------------------------------------------------------------------------   
#include <opencv2/opencv.hpp>  
#include <opencv2/imgproc/imgproc.hpp>  
#include<iostream>
#include<algorithm>

//-----------------------------------�������ռ��������֡�---------------------------------------  
//      ����������������ʹ�õ������ռ�  
//-----------------------------------------------------------------------------------------------   
using namespace cv;
using namespace std;
//-----------------------------------��main( )������--------------------------------------------  
//      ����������̨Ӧ�ó������ں��������ǵĳ�������￪ʼ  
//-----------------------------------------------------------------------------------------------  
int main()
{
	VideoCapture cap(0); //capture the video from web cam  

	if (!cap.isOpened())  // if not success, exit program  
	{
		cout << "Cannot open the web cam" << endl;
		return -1;
	}

	vector<Vec3f> circles;
	int mark[24];

	 int a = 0;
	

	while ( a<400 || circles.size() != 24)     //��һ��ѭ����ɨ�����̣���⵽24�����ҳ�������ʱ������ѭ�����������һ�����������ѭ��������⣩
	{
		Mat srcImage;

		bool bSuccess = cap.read(srcImage); // read a new frame from video  

		if (!bSuccess) //if not success, break loop  
		{
			cout << "Cannot read a frame from video stream" << endl;
			break;
		}

		Mat midImage, dstImage;//��ʱ������Ŀ��ͼ�Ķ���  


		int iLowH1 = 155;
		int iHighH1 = 179;

		int iLowS1 = 90;
		int iHighS1 = 255;

		int iLowV1 = 10;
		int iHighV1 = 255;


		int iLowH2 = 75;
		int iHighH2 = 105;

		int iLowS2 = 90;
		int iHighS2 = 255;

		int iLowV2 = 0;
		int iHighV2 = 255;

		Mat imgHSV;
		vector<Mat> hsvSplit;
		cvtColor(srcImage, imgHSV, COLOR_BGR2HSV); //Convert the captured frame from BGR to HSV  

												   //��HSV�ռ���ֱ��ͼ���⻯
		split(imgHSV, hsvSplit);
		equalizeHist(hsvSplit[2], hsvSplit[2]);
		merge(hsvSplit, imgHSV);
		Mat imgThresholded1;

		inRange(imgHSV, Scalar(iLowH1, iLowS1, iLowV1), Scalar(iHighH1, iHighS1, iHighV1), imgThresholded1); //Threshold the image  

		Mat imgThresholded2;

		inRange(imgHSV, Scalar(iLowH2, iLowS2, iLowV2), Scalar(iHighH2, iHighS2, iHighV2), imgThresholded2); //Threshold the image  

																											 //������ (ȥ��һЩ���)  
		Mat element = getStructuringElement(MORPH_RECT, Size(5, 5));
		morphologyEx(imgThresholded1, imgThresholded1, MORPH_OPEN, element);
		morphologyEx(imgThresholded2, imgThresholded2, MORPH_OPEN, element);

		//�ղ��� (����һЩ��ͨ��)  
		morphologyEx(imgThresholded2, imgThresholded2, MORPH_CLOSE, element);
		morphologyEx(imgThresholded2, imgThresholded2, MORPH_CLOSE, element);


		imshow("Original", srcImage); //show the original image 



		int count = 0;


		for (int i = 0; i< imgThresholded1.rows; ++i)
		{
			uchar * p = imgThresholded1.ptr<uchar>(i);
			for (int j = 0; j< imgThresholded1.cols; ++j)
			{
				if (p[j] == 255)
				{
					count++;
				}
			}
		}


		for (int i = 0; i< imgThresholded2.rows; ++i)
		{
			uchar * p = imgThresholded2.ptr<uchar>(i);
			for (int j = 0; j< imgThresholded2.cols; ++j)
			{
				if (p[j] == 255)
				{
					count++;
				}
			}
		}
	   a = count;

		//תΪ�Ҷ�ͼ������ͼ��ƽ��  
		cvtColor(srcImage, midImage, CV_BGR2GRAY);//ת����Ե�����ͼΪ�Ҷ�ͼ  
		GaussianBlur(midImage, midImage, Size(9, 9), 2, 2);

		//���л���Բ�任  

		HoughCircles(midImage, circles, CV_HOUGH_GRADIENT, 1.5, 10, 200, 15, 8, 13);

		//������ͼ�л��Ƴ�Բ  
		for (size_t i = 0; i < circles.size(); i++)
		{
			Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
			int radius = cvRound(circles[i][2]);
			//����Բ��  
			circle(srcImage, center, 3, Scalar(0, 255, 0), -1, 8, 0);
			//����Բ����  
			circle(srcImage, center, radius, Scalar(155, 50, 255), 3, 8, 0);
		}


		//��ʾЧ��ͼ    
		imshow("��Ч��ͼ��", srcImage);

		cout << circles.size() << endl;

		if (circles.size() == 24)                                               //��ɨ�赽��24�����Ӧ��circles�еı��
																				//��������1-24��˳���������mark��
		{


			int line1[3];
			count = 0;
			for (int i = 0; i < midImage.rows&&count < 3; i++)
			{
				for (int j = 0; j <= 23; j++)
					if (i == cvRound(circles[j][1]))
					{
						line1[count] = j;
						count++;
					}
			}
			count = 0;
			for (int i = 0; i < midImage.cols; i++)
				for (int j = 0; j < 3; j++)
					if (i == cvRound(circles[line1[j]][0]))
					{
						mark[count] = line1[j];
						count++;
					}


			int line2[3];
			count = 0;
			for (int i = 0; i < midImage.rows&&count < 6; i++)
			{
				for (int j = 0; j <= 23; j++)
					if (i == cvRound(circles[j][1]))
					{
						count++;
						if (count >= 4)
						{
							line2[count - 4] = j;
						}
					}
			}
			count = 0;
			for (int i = 0; i < midImage.cols; i++)
				for (int j = 0; j < 3; j++)
					if (i == cvRound(circles[line2[j]][0]))
					{
						mark[count + 3] = line2[j];
						count++;
					}

			int line3[3];
			count = 0;
			for (int i = 0; i < midImage.rows&&count < 9; i++)
			{
				for (int j = 0; j <= 23; j++)
					if (i == cvRound(circles[j][1]))
					{
						count++;
						if (count >= 7)
						{
							line3[count - 7] = j;
						}
					}
			}
			count = 0;
			for (int i = 0; i < midImage.cols; i++)
				for (int j = 0; j < 3; j++)
					if (i == cvRound(circles[line3[j]][0]))
					{
						mark[count + 6] = line3[j];
						count++;
					}


			int line4[6];
			count = 0;
			for (int i = 0; i < midImage.rows&&count < 15; i++)
			{
				for (int j = 0; j <= 23; j++)
					if (i == cvRound(circles[j][1]))
					{
						count++;
						if (count >= 10)
						{
							line4[count - 10] = j;
						}
					}
			}
			count = 0;
			for (int i = 0; i < midImage.cols; i++)
				for (int j = 0; j < 6; j++)
					if (i == cvRound(circles[line4[j]][0]))
					{
						mark[count + 9] = line4[j];
						count++;
					}


			int line5[3];
			count = 0;
			for (int i = 0; i < midImage.rows&&count < 18; i++)
			{
				for (int j = 0; j <= 23; j++)
					if (i == cvRound(circles[j][1]))
					{
						count++;
						if (count >= 16)
						{
							line5[count - 16] = j;
						}
					}
			}
			count = 0;
			for (int i = 0; i < midImage.cols; i++)
				for (int j = 0; j < 3; j++)
					if (i == cvRound(circles[line5[j]][0]))
					{
						mark[count + 15] = line5[j];
						count++;
					}

			int line6[3];
			count = 0;
			for (int i = 0; i < midImage.rows&&count < 21; i++)
			{
				for (int j = 0; j <= 23; j++)
					if (i == cvRound(circles[j][1]))
					{
						count++;
						if (count >= 19)
						{
							line6[count - 19] = j;
						}
					}
			}
			count = 0;
			for (int i = 0; i < midImage.cols; i++)
				for (int j = 0; j < 3; j++)
					if (i == cvRound(circles[line6[j]][0]))
					{
						mark[count + 18] = line6[j];
						count++;
					}

			int line7[3];
			count = 0;
			for (int i = 0; i < midImage.rows&&count < 24; i++)
			{
				for (int j = 0; j < 24; j++)
					if (i == cvRound(circles[j][1]))
					{
						count++;
						if (count >= 22)
						{
							line7[count - 22] = j;
						}
					}
			}
			count = 0;
			for (int i = 0; i < midImage.cols; i++)
				for (int j = 0; j < 3; j++)
					if (i == cvRound(circles[line7[j]][0]))
					{
						mark[count + 21] = line7[j];
						count++;
					}
		}

		char key = (char)waitKey(60);
	}


	if (!cap.isOpened())  // if not success, exit program  
	{
		cout << "Cannot open the web cam" << endl;
		return -1;
	}

	while (true)                                 //�ڶ���ѭ������ȡ����λ��
	{
		Mat srcImage;

		bool bSuccess = cap.read(srcImage); // read a new frame from video  

		if (!bSuccess) //if not success, break loop  
		{
			cout << "Cannot read a frame from video stream" << endl;
			break;
		}
		Mat midImage, dstImage;//��ʱ������Ŀ��ͼ�Ķ���  


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

		Mat imgHSV;
		vector<Mat> hsvSplit;
		cvtColor(srcImage, imgHSV, COLOR_BGR2HSV); //Convert the captured frame from BGR to HSV  

												   //��HSV�ռ���ֱ��ͼ���⻯
		split(imgHSV, hsvSplit);
		equalizeHist(hsvSplit[2], hsvSplit[2]);
		merge(hsvSplit, imgHSV);
		Mat imgThresholded1;

		inRange(imgHSV, Scalar(iLowH1, iLowS1, iLowV1), Scalar(iHighH1, iHighS1, iHighV1), imgThresholded1); //Threshold the image  

		Mat imgThresholded2;

		inRange(imgHSV, Scalar(iLowH2, iLowS2, iLowV2), Scalar(iHighH2, iHighS2, iHighV2), imgThresholded2); //Threshold the image  

																											 //������ (ȥ��һЩ���)  
		Mat element = getStructuringElement(MORPH_RECT, Size(5, 5));
		morphologyEx(imgThresholded1, imgThresholded1, MORPH_OPEN, element);
		morphologyEx(imgThresholded2, imgThresholded2, MORPH_OPEN, element);

		//�ղ��� (����һЩ��ͨ��)  
		morphologyEx(imgThresholded2, imgThresholded2, MORPH_CLOSE, element);
		morphologyEx(imgThresholded2, imgThresholded2, MORPH_CLOSE, element);

		imshow("Thresholded Image1", imgThresholded1); //show the thresholded image1
		imshow("Thresholded Image2", imgThresholded2); //show the thresholded image2
		imshow("Original", srcImage); //show the original image  

									  //check
		for (int i = 0; i < 24; i++)
			cout << mark[i] << ",";
		cout << endl;
		cout << cvRound(circles[mark[7]][0]) << endl;
		//

		int array1[24];
		int array2[24];
		int array[24];

		for (int i = 0; i < 24; i++)
		{
			if (imgThresholded1.at<uchar>(cvRound(circles[mark[i]][1]), cvRound(circles[mark[i]][0])) == 255)
			{
				array1[i] = 1;
			}
			else
			{
				array1[i] = 0;
			}
			if (i == 23)
				break;
		}

		for (int i = 0; i < 24; i++)
		{
			if (imgThresholded2.at<uchar>(cvRound(circles[mark[i]][1]), cvRound(circles[mark[i]][0])) == 255)
			{
				array2[i] = -1;
			}
			else
			{
				array2[i] = 0;
			}
			if (i == 23)
				break;
		}

		for (int i = 0; i < 24; i++)
		{
			array[i] = array1[i] + array2[i];
			cout << array[i] << ",";
			if (i == 23)
				break;
		}
		cout << endl;

		char key = (char)waitKey(60);
		if (key == 27)
			break;
	}

	return 0;

}