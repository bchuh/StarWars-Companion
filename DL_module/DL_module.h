#ifndef DL_MODULE
#define DL_MODULE
#include <opencv2/opencv.hpp>
#include "detector.h"

//using namespace std;


class Classifier
{
public:
	int classify(cv::Mat frame);
    static Classifier* getInstance(std::string onnx_path);
	bool isReady();
	static void Destroy();

private:
	const int w = 224;//input shape of the module
	const int h = 224;//input shape of the module
	bool _isReady;
	cv::dnn::Net net;
	static Classifier* instance;
	void preProcess(const cv::Mat& image, cv::Mat& image_blob);
	~Classifier();
    Classifier(std::string onnx_path);
    bool fileExist(std::string name);
};

class DLmodule
{
public:
    static DLmodule* getInstance(std::string model_path);
	int classify(const cv::Mat& frame);
    std::vector<Detection>& detect(cv::Mat frame);
	static void Destory();
	bool isReady();
private:
	static DLmodule* instance;
	Classifier* classifier;
	Detector* detector;
    DLmodule(std::string model_path);
	~DLmodule();
};

#endif // !DL

