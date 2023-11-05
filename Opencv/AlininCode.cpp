//#include <opencv2/core.hpp>
//#include <opencv2/opencv.hpp>
//#include <opencv2/imgcodecs.hpp>
//#include <opencv2/highgui.hpp>
//#include <iostream>
//#include "opencv2/imgproc.hpp"
//
//using namespace cv;
//using namespace std;
//
//Mat src_gray;
//int thresh = 100;
//RNG rng(12345);
//void thresh_callback(int, void*);
//
//// comparison function object
//bool compareContourAreas(std::vector<cv::Point> contour1, std::vector<cv::Point> contour2) {
//	double i = fabs(contourArea(cv::Mat(contour1)));
//	double j = fabs(contourArea(cv::Mat(contour2)));
//	return (i < j);
//}
//
//void GetCountours(Mat imagDil, Mat img)
//{
//
//	vector<vector<Point>> contours;
//	vector<Vec4i> hierarchy;
//	                     
//	findContours(imagDil, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE);
//
//	drawContours(img, contours, -1, Scalar(255, 0, 0), 10);
//
//	for (int i = 0; i < contours.size(); i++)
//	{
//		int area = contourArea(contours[i]);
//		vector<vector<Point>> conPoly(contours.size());
//
//		vector<Rect> bounRec(contours.size());
//
//
//
//		if (area > 1010)
//		{
//			cout << area << endl;
//
//			float peri = arcLength(contours[i], true);
//			approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);
//
//			cout << conPoly[i].size() << endl;
//
//			drawContours(img, conPoly, i, Scalar(255, 0, 255), 2);
//			
//		}
//	}
//}
//
//int main() {
//	double j;
//	cout << "beginning of the program ", '\n';
//	cv::Mat src = cv::imread("G:/openvc/Cascade Trainer GUI/workingIslamFile.jpg");
//	cv::imshow("image ", src);
//	//cv::waitKey(0);
//	Mat src_Gray;
//	int tresh = 100;
//	RNG rng(12345);
//	//	void thresh_callback(int, void*);
//
//	cvtColor(src, src_gray, COLOR_BGR2GRAY);
//	blur(src_gray, src_gray, Size(1, 1)); //Size(3, 3));
//	const char* source_window = "Source";
//	namedWindow(source_window);
//	//imshow(source_window, src);
//
//	const int max_thresh = 255;
//
//	Mat canny_output;
//	Canny(src_gray, canny_output, thresh, thresh * 2);
//	vector<vector<Point> > contours;
//	vector<Vec4i> hierarchy;
//	findContours(canny_output, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE);
//	Mat drawing = Mat::zeros(canny_output.size(), CV_8UC3);
//
//	vector<cv::Point> cnt;
//	sort(contours.begin(), contours.end(), compareContourAreas);
//
//	for (size_t i = contours.size() - 1; i > contours.size() - 20; i--)// select last 7 contours
//	{
//		cnt = contours[i];
//
//		int area = contourArea(contours[i]);
//		vector<vector<Point>> conPoly(contours.size());
//
//		vector<Rect> bounRec(contours.size());
//
//		
//		if (area > 1010)
//		{
//			cout << area << endl;
//
//			float peri = arcLength(contours[i], true);
//			approxPolyDP(contours[i], conPoly[i], 0.001 * peri, true);
//
//			cout << conPoly[i].size() << endl;
//
//			Scalar color = Scalar(100, 100, 100);
//			//drawContours(drawing, contours, (int)i, color, 2, LINE_8, hierarchy, 0);
//			drawContours(drawing, conPoly, i, color, 2, LINE_8, hierarchy, 0);
//		}
//	}
//
//
//	imshow("Contours", drawing);
//	//GetCountours(canny_output, src);
//	//imshow("Contours area", canny_output);
//	waitKey(0);
//
//
//	cout << "see if it works  ";
//
//
//}
//
//void thresh_callback(int, void*)
//{
//}
