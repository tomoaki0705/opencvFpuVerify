#include <opencv2/opencv.hpp>
#include <iostream>
#include <iomanip>
cv::String keys = 
    "{d div divide  |true |perform divide}"
    "{s sqrt        |false|perform square root}"
    "{m fma multiply|false|perform fma}"
    "{h help ?      |false|show message}";

union intFloat32
{
    int i;
    unsigned u;
    float f;
};

std::ostream& operator<<(std::ostream& os, const intFloat32& a)
{
    os << std::scientific << a.f << "\t0x" << std::setw(8) << std::setfill('0') << std::hex << a.u << std::dec;
    return os;
}

void dumpMat(const cv::Mat& mat)
{
    std::cout << mat.rows << "  " << mat.cols << std::endl;
    std::cout << ((float*)mat.data)[0] << std::endl;
    for(int i = 0;i < mat.rows;i++)
    {
        intFloat32 stub;
        stub.f = ((float*)mat.data)[i];
        std::cout << i << '\t' << stub << std::endl;
    }
}

int main(int argc, char**argv)
{
    cv::CommandLineParser parser(argc, argv, keys);
    if(parser.get<bool>("help") == true)
    {
        parser.printMessage();
        return 0;
    }

    if(parser.get<bool>("divide") == true)
    {
        float _data[] = {1.0f, 2.0f, 3.0f, 4.0f, };
        cv::Mat a = cv::Mat(4, 1, CV_32FC1, _data);
        cv::Mat one = cv::Mat::ones(4, 1, CV_32FC1);
        cv::Mat b;
        cv::divide(one, a, b);
        dumpMat(b);
    }
    return 0;
}

