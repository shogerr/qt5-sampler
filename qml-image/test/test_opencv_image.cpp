#include <SDL_image.h>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <emscripten.h>

int main()
{
    auto img = IMG_Load("test.png");
    std::cout << img << std::cout;
    //cv::Mat image = cv::imread(cv::samples::findFile("test.png"), cv::IMREAD_COLOR);
    //cv::namedWindow("Window", cv::WINDOW_AUTOSIZE);
    //cv::imshow("Window", image);
    //cv::waitKey(0);
    std::cout << "hello" << std::endl;

    return 0;
}
