


#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>
#include <opencv2/photo.hpp>
using namespace cv;
using namespace std;
Mat src_gray;
int thresh = 100;
RNG rng(12345);
void thresh_callback(int, void*);

int main()
{
    // CommandLineParser parser(argc, argv, "{@input | HappyFish.jpg | input image}");
    string path = "G:/openvc/Cascade Trainer GUI/workingIslamFile.jpg";// (parser.get<string>("image"));
    Mat src = imread(path);
    /* if (src.empty())
     {
         cout << "Could not open or find the image!\n" << endl;
         cout << "Usage: " << argv[0] << " <Input image>" << endl;
         return -1;
     }*/
    cvtColor(src, src_gray, COLOR_BGR2GRAY);
    blur(src_gray, src_gray, Size(3, 3));
    const char* source_window = "Source";
    namedWindow(source_window);
    imshow(source_window, src);
    const int max_thresh = 255;
    createTrackbar("Canny thresh:", source_window, &thresh, max_thresh, thresh_callback);
    thresh_callback(0, 0);
    waitKey();
    return 0;
}
vector<Point> yuvarlat(vector<Point> gelenCounter)
{
    vector<Point> Yenivektor;
    for (size_t i = 1; i < gelenCounter.size(); i++)
    {
        if (gelenCounter[i - 1].x - gelenCounter[i].x > 0 || gelenCounter[i - 1].y - gelenCounter[i].y > 0)
        {
            Yenivektor.push_back(gelenCounter[i]);
        }
    }


    return Yenivektor;
}

vector<vector<Point> > EliminateNoise(vector<vector<Point> >     gelenCOunter)
{
    vector<vector<Point>> yeniCounter;    
    vector<Point> yeni;
    

   // yeniCounter.push_back(gelenCOunter[0]);
    for (size_t i = 1; i < gelenCOunter.size(); i++)
    {
        vector<vector<Point>> geciciVect;
     

        int area = gelenCOunter[i].size();// contourArea(gelenCOunter[i]);// contourArea(geciciVect);
       
        if (area ==3568)
        {
       
            if (area > 0)
            {
                yeniCounter.push_back(gelenCOunter[i]);
            }
           
          /*  yeni1.push_back(gelenCOunter[gelenCOunter.size()][0]);
            yeniCounter.push_back(yeni1); */
        }
        else
        {
           /* vector<Point> yeni1;
            yeni1.push_back(gelenCOunter[i][0]);
            yeni1.push_back(gelenCOunter[i][gelenCOunter.size()-1]);

            yeniCounter.push_back(yeni1);*/
        }
    }
 //   yeniCounter.push_back(gelenCOunter[gelenCOunter.size()]);
    return yeniCounter;
}
void thresh_callback(int, void*)
{
    Mat canny_output;
    Canny(src_gray, canny_output, thresh, thresh * 2);
    vector<vector<Point> > contours;
    vector<Vec4i> hierarchy;
    findContours(canny_output, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE);
    Mat drawing = Mat::zeros(canny_output.size(), CV_8UC3);
    for (size_t i = 0; i < contours.size(); i++)
    {
        int area = contourArea(contours[i]);

        /* if (area > 33476 && area < 300000)*/

        if (area == 54516)
        {
           /* cout << area << endl;*/
            /*for (size_t i1 = 0; i1 < contours[i].size(); i1++)
            {*/
                 vector<vector<Point>> contours1 = EliminateNoise(contours);
                Scalar color = Scalar(rng.uniform(0, 256), rng.uniform(0, 256), rng.uniform(0, 256));
                drawContours(drawing, contours, (int)i, color, 2, LINE_8, hierarchy, 0);

            
            
        }
    }


    imshow("Contours", drawing);
}
Mat imgGray, imgBlur, ImgCanny, imgCanny, imgDil, imgOriginal, imgThre;
vector<Point> getCountours(Mat image)
{
    vector <vector <Point>>  contours;
    vector <Vec4i>  hierarchy;
    findContours(image, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

    vector <vector <Point>> conPoly(contours.size());
    vector <Rect> boundRect(contours.size());

    Point myPoint(0, 0);

    vector<Point> biggest;
    int maxArea = 0;


    for (int i = 0; i < contours.size(); i++)
    {
        int area = contourArea(contours[i]);
        /* cout << area << endl;*/

        String objectType;

        if (area > 1000)
        {
            float peri = arcLength(contours[i], true);
            cout << area << endl;

            approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);

            if (area > maxArea && conPoly[i].size() == 4)
            {
                drawContours(imgOriginal, conPoly, i, Scalar(255, 0, 255), 5);

                biggest = { conPoly[i][0], conPoly[i][1] , conPoly[i][2] , conPoly[i][3] };
                maxArea = area;
            }
            drawContours(imgOriginal, conPoly, i, Scalar(255, 0, 255), 20);

            rectangle(imgOriginal, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 255, 0), 5);

            return biggest;

        }

    }

}