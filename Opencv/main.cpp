//#include <iostream>
//#include "opencv2/highgui/highgui.hpp"
//#include "opencv2/imgproc/imgproc.hpp"
//
//using namespace cv;
//using namespace std;
//Mat src_gray;
//int main()
//{
//    VideoCapture cap(0); //capture the video from web cam
//
//
//
//    string path = "G:/openvc/Cascade Trainer GUI/workingIslamFile.jpg";// (parser.get<string>("image"));
//    Mat src = imread(path);
//
//    cvtColor(src, src_gray, COLOR_BGR2GRAY);
//    blur(src_gray, src_gray, Size(3, 3));
//    const char* source_window = "Source";
//    namedWindow(source_window);
//
//    int iLowH = 0;
//    int iHighH = 179;
//
//    int iLowS = 0;
//    int iHighS = 255;
//
//    int iLowV = 0;
//    int iHighV = 255;
//
//    //Create trackbars in "Control" window
//    //cvCreateTrackbar("LowH", "Control", &iLowH, 179); //Hue (0 - 179)
//    //cvCreateTrackbar("HighH", "Control", &iHighH, 179);
//
//    //cvCreateTrackbar("LowS", "Control", &iLowS, 255); //Saturation (0 - 255)
//    //cvCreateTrackbar("HighS", "Control", &iHighS, 255);
//
//    //cvCreateTrackbar("LowV", "Control", &iLowV, 255); //Value (0 - 255)
//    //cvCreateTrackbar("HighV", "Control", &iHighV, 255);
//
//   /* while (true)
//    {*/
//        Mat imgOriginal;
//
//        bool bSuccess = cap.read(imgOriginal); // read a new frame from video
//
//        //if (!bSuccess) //if not success, break loop
//        //{
//        //    cout << "Cannot read a frame from video stream" << endl;
//        //    break;
//        //}
//
//        Mat imgHSV;
//
//        cvtColor(imgOriginal, imgHSV, COLOR_BGR2HSV); //Convert the captured frame from BGR to HSV
//
//        Mat imgThresholded;
//
//        inRange(imgHSV, Scalar(iLowH, iLowS, iLowV), Scalar(iHighH, iHighS, iHighV), imgThresholded); //Threshold the image
//
//        //morphological opening (remove small objects from the foreground)
//        erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
//        dilate(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
//
//        //morphological closing (fill small holes in the foreground)
//        dilate(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
//        erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
//
//        imshow("Thresholded Image", imgThresholded); //show the thresholded image
//        imshow("Original", imgOriginal); //show the original image
//
//    //    if (waitKey(30) == 27) //wait for 'esc' key press for 30ms. If 'esc' key is pressed, break loop
//    //    {
//    //        cout << "esc key is pressed by user" << endl;
//    //        break;
//    //    }
//    //}
//        waitKey();
//    return 0;
//
//}


//#include "opencv2/objdetect.hpp"
//#include "opencv2/highgui.hpp"
//#include "opencv2/imgproc.hpp"
//#include "opencv2/videoio.hpp"
//#include <iostream>
//using namespace std;
//using namespace cv;
//static void help(const char** argv)
//{
//    cout << "\nThis program demonstrates the use of cv::CascadeClassifier class to detect objects (Face + eyes). You can use Haar or LBP features.\n"
//        "This classifier can recognize many kinds of rigid objects, once the appropriate classifier is trained.\n"
//        "It's most known use is for faces.\n"
//        "Usage:\n"
//        << argv[0]
//        << "   [--cascade=<cascade_path> this is the primary trained classifier such as frontal face]\n"
//        "   [--nested-cascade[=nested_cascade_path this an optional secondary classifier such as eyes]]\n"
//        "   [--scale=<image scale greater or equal to 1, try 1.3 for example>]\n"
//        "   [--try-flip]\n"
//        "   [filename|camera_index]\n\n"
//        "example:\n"
//        << argv[0]
//        << " --cascade=\"data/haarcascades/haarcascade_frontalface_alt.xml\" --nested-cascade=\"data/haarcascades/haarcascade_eye_tree_eyeglasses.xml\" --scale=1.3\n\n"
//        "During execution:\n\tHit any key to quit.\n"
//        "\tUsing OpenCV version " << CV_VERSION << "\n" << endl;
//}
//void detectAndDraw(Mat& img, CascadeClassifier& cascade,
//    CascadeClassifier& nestedCascade,
//    double scale, bool tryflip);
//string cascadeName;
//string nestedCascadeName;
//int main()
//{
//   // VideoCapture capture;
//    Mat frame, image;
//    string inputName;
//    bool tryflip;
//    CascadeClassifier cascade, nestedCascade;
//    double scale;
//   
//    cascadeName = "G:/openvc/Cascade Trainer GUI/classifier/cascade.xml";// parser.get<string>("cascade");
//    nestedCascadeName = "G:/openvc/Cascade Trainer GUI/classifier/cascade.xml";// parser.get<string>("nested-cascade");
//    /*scale = parser.get<double>("scale");
//    if (scale < 1)*/
//        scale = 1;
//        tryflip = "try-flip";// parser.has("try-flip");
//        inputName = "G:/openvc/Cascade Trainer GUI/workingIslamFile1.jpg";// parser.get<string>("@filename");
//        nestedCascade.load(samples::findFileOrKeep(nestedCascadeName));
//        image = imread(samples::findFileOrKeep(inputName), IMREAD_COLOR);
//        detectAndDraw(image, cascade, nestedCascade, scale, tryflip);
//        waitKey(0);
//    return 0;
//}
//void detectAndDraw(Mat& img, CascadeClassifier& cascade,CascadeClassifier& nestedCascade,double scale, bool tryflip)
//{
//    double t = 0;
//    vector<Rect> faces, faces2;
//    const static Scalar colors[] =
//    {
//        Scalar(255,0,0),
//        Scalar(255,128,0),
//        Scalar(255,255,0),
//        Scalar(0,255,0),
//        Scalar(0,128,255),
//        Scalar(0,255,255),
//        Scalar(0,0,255),
//        Scalar(255,0,255)
//    };
//    Mat gray, smallImg;
//    cvtColor(img, gray, COLOR_BGR2GRAY);
//    double fx = 1 / scale;
//    resize(gray, smallImg, Size(), fx, fx, INTER_LINEAR_EXACT);
//    equalizeHist(smallImg, smallImg);
//    t = (double)getTickCount();
//    cascade.detectMultiScale(smallImg, faces,
//        1.1, 2, 0
//        //|CASCADE_FIND_BIGGEST_OBJECT
//        //|CASCADE_DO_ROUGH_SEARCH
//        | CASCADE_SCALE_IMAGE,
//        Size(30, 30));
//    if (tryflip)
//    {
//      //  flip(smallImg, smallImg, 1);
//        cascade.detectMultiScale(smallImg, faces2,
//            1.1, 2, 0
//            //|CASCADE_FIND_BIGGEST_OBJECT
//            //|CASCADE_DO_ROUGH_SEARCH
//            | CASCADE_SCALE_IMAGE,
//            Size(30, 30));
//        for (vector<Rect>::const_iterator r = faces2.begin(); r != faces2.end(); ++r)
//        {
//            faces.push_back(Rect(smallImg.cols - r->x - r->width, r->y, r->width, r->height));
//        }
//    }
//    t = (double)getTickCount() - t;
//    printf("detection time = %g ms\n", t * 1000 / getTickFrequency());
//    for (size_t i = 0; i < faces.size(); i++)
//    {
//        Rect r = faces[i];
//        Mat smallImgROI;
//        vector<Rect> nestedObjects;
//        Point center;
//        Scalar color = colors[i % 8];
//        int radius;
//        double aspect_ratio = (double)r.width / r.height;
//        if (0.75 < aspect_ratio && aspect_ratio < 1.3)
//        {
//            center.x = cvRound((r.x + r.width * 0.5) * scale);
//            center.y = cvRound((r.y + r.height * 0.5) * scale);
//            radius = cvRound((r.width + r.height) * 0.25 * scale);
//            circle(img, center, radius, color, 3, 8, 0);
//        }
//        else
//            rectangle(img, Point(cvRound(r.x * scale), cvRound(r.y * scale)),
//                Point(cvRound((r.x + r.width - 1) * scale), cvRound((r.y + r.height - 1) * scale)),
//                color, 3, 8, 0);
//        if (nestedCascade.empty())
//            continue;
//        smallImgROI = smallImg(r);
//        nestedCascade.detectMultiScale(smallImgROI, nestedObjects,
//            1.1, 2, 0
//            //|CASCADE_FIND_BIGGEST_OBJECT
//            //|CASCADE_DO_ROUGH_SEARCH
//            //|CASCADE_DO_CANNY_PRUNING
//            | CASCADE_SCALE_IMAGE,
//            Size(30, 30));
//        for (size_t j = 0; j < nestedObjects.size(); j++)
//        {
//            Rect nr = nestedObjects[j];
//            center.x = cvRound((r.x + nr.x + nr.width * 0.5) * scale);
//            center.y = cvRound((r.y + nr.y + nr.height * 0.5) * scale);
//            radius = cvRound((nr.width + nr.height) * 0.25 * scale);
//            circle(img, center, radius, color, 3, 8, 0);
//        }
//    }
//    imshow("result", img);
//}
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