#ifndef DL_MODULE
#define DL_MODULE
#include <opencv2/opencv.hpp>

using namespace std;


class Classifier
{
public:
	int classify(cv::Mat frame);
	static Classifier* getInstance();
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
	Classifier();
	bool fileExist(string name);
};

class DLmodule
{
public:
	static DLmodule* getInstance();
	int classify(const cv::Mat& frame);
	static void Destory();
	bool isReady();
private:
	static DLmodule* instance;
	Classifier* classifier;
	DLmodule();
	~DLmodule();
};

#endif // !DL

