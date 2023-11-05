

//
//
//
////#include <opencv2/core.hpp>
//#include <opencv2/imgcodecs.hpp>
//#include <opencv2/highgui.hpp>
//#include <iostream>
//#include "opencv2/objdetect.hpp"
//#include "opencv2/highgui.hpp"
//#include "opencv2/imgproc.hpp"
//#include "iostream"
//
//using namespace std;
//using namespace cv;
//
// <summary>
// import image
// </summary>
//Mat ImgGray, ImgBlur, ImgCanny, ImgDil, ImgErode;
//int main() {
//	double j;
//	cout << "beginning of the program ", '\n';
//	string path= "G:/openvc/Cascade Trainer GUI/workingIslamFile.jpg";
//	Mat src = cv::imread(path);
//	imshow("image ", src);
//	waitKey(0);
//	Mat src_Gray;
//	int tresh = 100;
//	RNG rng(12345);
//
//	cvtColor(src, src_gray, COLOR_BGR2GRAY);
//	blur(src_gray, src_gray, Size(1, 1)); //Size(3, 3));
//	const char* source_window = "Source";
//	namedWindow(source_window);
//	imshow(source_window, src);
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
//	for (size_t i = 0; i < contours.size(); i++)
//	{
//		cnt = contours[i];
//		j = fabs(contourArea(cv::Mat(cnt)));
//		if (j < 800) continue;
//		Scalar color = Scalar(100, 100, 100);
//		drawContours(drawing, contours, (int)i, color, 2, LINE_8, hierarchy, 0);
//	}
//
//	imshow("Contours", drawing);
//	waitKey();
//
//
//}
//
//void GetCountours(Mat imagDil,Mat img)
//{
//	
//	vector<vector<Point>> contours;
//	vector<Vec4i> hierarchy;
//	findContours(imagDil,contours,hierarchy,RETR_EXTERNAL,CHAIN_APPROX_SIMPLE);
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
//		cout << area << endl;
//		if (area > 11)
//		{
//
//			float peri = arcLength(contours[i], true);
//			approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);
//
//			cout << conPoly[i].size() << endl;
//
//			drawContours(img, conPoly, i, Scalar(255, 0, 255), 2);
//			/*bounRec[i] = boundingRect(conPoly[i]);
//
//			rectangle(imagDil, bounRec[i].tl(), bounRec[i].br(), Scalar(0,255, 0), 5);*/
//		}
//	}
//}
//void main()
//{
//	string path = "G:/openvc/Cascade Trainer GUI/workingIslamFile.jpg";
//		Mat img = imread(path);
//		Mat ImgResize;
//		//Point2f src[4] = { {529,142},{771,190},{} }
//
//	     cvtColor(img, ImgGray,COLOR_BGR2GRAY);
//		
//		GaussianBlur(img, ImgBlur, Size(3, 3), 3, 0);
//		Canny(img, ImgCanny, 25, 75);
//
//		Mat Kernel = getStructuringElement(MORPH_RECT,Size(3,3));
//
//		dilate(ImgCanny,ImgDil,Kernel);
//
//		GetCountours(ImgDil, img);
//		imshow("image ", img);
//		imshow("image gray", ImgGray);
//	/*	imshow("image blur", ImgBlur);
//		imshow("image canny", ImgCanny);
//		imshow("image dil", ImgDil);*/
//	//	imshow("image erode", ImgErode);
//
//		waitKey(0);
//}
//



//int main()
//{
//    cv::Mat img = cv::imread("E:/workingIslamFile.jpg");
//    
//    namedWindow("First OpenCV Application", WINDOW_AUTOSIZE);
//    cv::imshow("First OpenCV Application", img);
//    cv::moveWindow("First OpenCV Application", 0, 45);
//    cv::waitKey(0);
//    cv::destroyAllWindows();
//    return 0;
//}

//void main() {
//	VideoCapture video(0);
//	CascadeClassifier facedetect;
//	Mat img;
//	facedetect.load("G:/haarcascade_frontalface_default.xml");
//
//	while (true) {
//		video.read(img);
//
//		vector<Rect> faces;
//
//		facedetect.detectMultiScale(img, faces, 1.3, 5);
//
//		cout << faces.size() << endl;
//
//		for (int i = 0; i < faces.size(); i++) {
//			rectangle(img, faces[i].tl(), faces[i].br(), Scalar(50, 50, 255), 3);
//			rectangle(img, Point(0, 0), Point(250, 70), Scalar(50, 50, 255), FILLED);
//			putText(img, to_string(faces.size()) + " Murat Face Found", Point(10, 40), FONT_HERSHEY_DUPLEX, 1, Scalar(255, 255, 255), 1);
//		}
//
//
//		imshow("Frame", img);
//		waitKey(10);
//
//
//	}
//}
//
//int main()
//{
//    VideoCapture vidio(0);
//    Mat img;
//    CascadeClassifier MuratDedetection;
//    MuratDedetection.load("G:/haarcascade_frontalface_default.xml");
//   
//
//        while (true)
//        {
//            vector<Rect> PrestUnit;
//            MuratDedetection.detectMultiScale(img, PrestUnit, 1.3, 5);
//            for (int i = 0; i < PrestUnit.size(); i++)
//            {
//                rectangle(img, PrestUnit[i].tl(), PrestUnit[i].br(), Scalar(50, 50, 225), 3);
//               // PrestUnit(img, PrestUnit[i].tl(), PrestUnit[i].br(),Scalar(50,50,225),3);
//                putText(img, to_string(PrestUnit.size()), Point(10, 40), FONT_HERSHEY_DUPLEX, 1, Scalar(255, 255, 255), 1);
//
//            }
//            vidio.read(img);
//
//            imshow("First OpenCV Application", img);
//            waitKey(20);
//        }
//
//  /*  cv::Mat img = cv::imread("E:/workingIslamFile.jpg");
//    namedWindow("First OpenCV Application", WINDOW_AUTOSIZE);
//    cv::imshow("First OpenCV Application", img);
//    cv::moveWindow("First OpenCV Application", 0, 45);
//    cv::waitKey(0);
//    cv::destroyAllWindows();*/
//    return 0;
//}
//

//using namespace std;
//using namespace cv;
//
//// Function for Face Detection
//void detectAndDraw(Mat& img, CascadeClassifier& cascade,
//    CascadeClassifier& nestedCascade, double scale);
//string cascadeName, nestedCascadeName;
//
//int main(int argc, const char** argv)
//{
//    // VideoCapture class for playing video for which faces to be detected
//    VideoCapture capture;
//    Mat frame, image;
//
//    // PreDefined trained XML classifiers with facial features
//    CascadeClassifier cascade, nestedCascade;
//    double scale = 1;
//
//    // Load classifiers from "opencv/data/haarcascades" directory
//   /* nestedCascade.load("../../haarcascade_eye_tree_eyeglasses.xml");*/
//    nestedCascade.load("G:/openvc/opencv/build/etc/haarcascades/haarcascade_eye_tree_eyeglasses.xml");
//
//    // Change path before execution
//   /* cascade.load("../../haarcascade_frontalcatface.xml");*/
//    cascade.load("G:/openvc/opencv/build/etc/haarcascades/haarcascade_frontalcatface.xml");
//
//    // Start Video..1) 0 for WebCam 2) "Path to Video" for a Local Video
//    capture.open(0);
//    if (capture.isOpened())
//    {
//        // Capture frames from video and detect faces
//        cout << "Face Detection Started...." << endl;
//        while (1)
//        {
//            capture >> frame;
//            if (frame.empty())
//                break;
//            Mat frame1 = frame.clone();
//            detectAndDraw(frame1, cascade, nestedCascade, scale);
//            char c = (char)waitKey(10);
//
//            // Press q to exit from window
//            if (c == 27 || c == 'q' || c == 'Q')
//                break;
//        }
//    }
//    else
//        cout << "Could not Open Camera";
//    return 0;
//}
//
//void detectAndDraw(Mat& img, CascadeClassifier& cascade,
//    CascadeClassifier& nestedCascade,
//    double scale)
//{
//    vector<Rect> faces, faces2;
//    Mat gray, smallImg;
//
//    cvtColor(img, gray, COLOR_BGR2GRAY); // Convert to Gray Scale
//    double fx = 1 / scale;
//
//    // Resize the Grayscale Image
//    resize(gray, smallImg, Size(), fx, fx, INTER_LINEAR);
//    equalizeHist(smallImg, smallImg);
//
//    // Detect faces of different sizes using cascade classifier
//    cascade.detectMultiScale(smallImg, faces, 1.1,
//        2, 0 | CASCADE_SCALE_IMAGE, Size(30, 30));
//
//    // Draw circles around the faces
//    for (size_t i = 0; i < faces.size(); i++)
//    {
//        Rect r = faces[i];
//        Mat smallImgROI;
//        vector<Rect> nestedObjects;
//        Point center;
//        Scalar color = Scalar(255, 0, 0); // Color for Drawing tool
//        int radius;
//
//        double aspect_ratio = (double)r.width / r.height;
//        if (0.75 < aspect_ratio && aspect_ratio < 1.3)
//        {
//            center.x = cvRound((r.x + r.width * 0.5) * scale);
//            center.y = cvRound((r.y + r.height * 0.5) * scale);
//            radius = cvRound((r.width + r.height) * 0.25 * scale);
//            circle(img, center, radius, color, 3, 8, 0);
//        }
//        /*else
//            rectangle(img, cvPoint(cvRound(r.x * scale), cvRound(r.y * scale)),
//                cvPoint(cvRound((r.x + r.width - 1) * scale),
//                    cvRound((r.y + r.height - 1) * scale)), color, 3, 8, 0);*/
//        if (nestedCascade.empty())
//            continue;
//        smallImgROI = smallImg(r);
//
//        // Detection of eyes in the input image
//        nestedCascade.detectMultiScale(smallImgROI, nestedObjects, 1.1, 2,
//            0 | CASCADE_SCALE_IMAGE, Size(30, 30));
//
//        // Draw circles around eyes
//        for (size_t j = 0; j < nestedObjects.size(); j++)
//        {
//            Rect nr = nestedObjects[j];
//            center.x = cvRound((r.x + nr.x + nr.width * 0.5) * scale);
//            center.y = cvRound((r.y + nr.y + nr.height * 0.5) * scale);
//            radius = cvRound((nr.width + nr.height) * 0.25 * scale);
//            circle(img, center, radius, color, 3, 8, 0);
//        }
//    }
//
//    // Show Processed Image with detected faces
//    imshow("Face Detection", img);
//}