//#include "opencv2/imgproc.hpp"
//#include "opencv2/highgui.hpp"
//#include <iostream>
//using namespace cv;
//using namespace std;
//Mat src, erosion_dst, dilation_dst;
//int erosion_elem = 0;
//int erosion_size = 0;
//int dilation_elem = 0;
//int dilation_size = 0;
//int const max_elem = 2;
//int const max_kernel_size = 21;
//void Erosion(int, void*);
//void Dilation(int, void*);
//int main()
//{
//   // CommandLineParser parser(argc, argv, "{@input | LinuxLogo.jpg | input image}");
//    string path = "G:/openvc/Cascade Trainer GUI/workingIslamFile.jpg";// (parser.get<string>("image"));
//
//   /* src = imread(samples::findFile(parser.get<String>("@input")), IMREAD_COLOR);*/
//    src = imread(path, IMREAD_COLOR);
//    /*if (src.empty())
//    {
//        cout << "Could not open or find the image!\n" << endl;
//        cout << "Usage: " << argv[0] << " <Input image>" << endl;
//        return -1;
//    }*/
//    namedWindow("Erosion Demo", WINDOW_AUTOSIZE);
//    namedWindow("Dilation Demo", WINDOW_AUTOSIZE);
//    moveWindow("Dilation Demo", src.cols, 0);
//    createTrackbar("Element:\n 0: Rect \n 1: Cross \n 2: Ellipse", "Erosion Demo",
//        &erosion_elem, max_elem,
//        Erosion);
//    createTrackbar("Kernel size:\n 2n +1", "Erosion Demo",
//        &erosion_size, max_kernel_size,
//        Erosion);
//    createTrackbar("Element:\n 0: Rect \n 1: Cross \n 2: Ellipse", "Dilation Demo",
//        &dilation_elem, max_elem,
//        Dilation);
//    createTrackbar("Kernel size:\n 2n +1", "Dilation Demo",
//        &dilation_size, max_kernel_size,
//        Dilation);
//    Erosion(0, 0);
//    Dilation(0, 0);
//    waitKey(0);
//    return 0;
//}
//Mat imgOriginal;
//vector<Point> getCountours(Mat image)
//{
//    vector <vector <Point>>  contours;
//    vector <Vec4i>  hierarchy;
//    findContours(image, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
//
//    vector <vector <Point>> conPoly(contours.size());
//    vector <Rect> boundRect(contours.size());
//
//    Point myPoint(0, 0);
//
//    vector<Point> biggest;
//    int maxArea = 0;
//
//
//    for (int i = 0; i < contours.size(); i++)
//    {
//        int area = contourArea(contours[i]);
//        /* cout << area << endl;*/
//
//        String objectType;
//
//        if (area > 1000)
//        {
//            float peri = arcLength(contours[i], true);
//            cout << area << endl;
//
//            approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);
//
//            if (area > maxArea && conPoly[i].size() == 4)
//            {
//                drawContours(imgOriginal, conPoly, i, Scalar(255, 0, 255), 5);
//
//                biggest = { conPoly[i][0], conPoly[i][1] , conPoly[i][2] , conPoly[i][3] };
//                maxArea = area;
//            }
//            drawContours(imgOriginal, conPoly, i, Scalar(255, 0, 255), 20);
//
//            rectangle(imgOriginal, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 255, 0), 5);
//
//            return biggest;
//
//        }
//
//    }
//
//}
//vector<Point>  initialPoints;
//void Erosion(int, void*)
//{
//    int erosion_type = 0;
//    if (erosion_elem == 0) { erosion_type = MORPH_RECT; }
//    else if (erosion_elem == 1) { erosion_type = MORPH_CROSS; }
//    else if (erosion_elem == 2) { erosion_type = MORPH_ELLIPSE; }
//    Mat element = getStructuringElement(erosion_type,
//        Size(2 * erosion_size + 1, 2 * erosion_size + 1),
//        Point(erosion_size, erosion_size));
//    erode(src, erosion_dst, element);
//  //  initialPoints = getCountours(erosion_dst);
//
//    imshow("Erosion Demo", erosion_dst);
//}
//void Dilation(int, void*)
//{
//    int dilation_type = 0;
//    if (dilation_elem == 0) { dilation_type = MORPH_RECT; }
//    else if (dilation_elem == 1) { dilation_type = MORPH_CROSS; }
//    else if (dilation_elem == 2) { dilation_type = MORPH_ELLIPSE; }
//    Mat element = getStructuringElement(dilation_type,
//        Size(2 * dilation_size + 1, 2 * dilation_size + 1),
//        Point(dilation_size, dilation_size));
//    dilate(src, dilation_dst, element);
//    imshow("Dilation Demo", dilation_dst);
//}