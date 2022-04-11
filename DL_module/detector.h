#ifndef DETECTOR
#define DETECTOR
#include <opencv2/opencv.hpp>

using namespace std;

struct Detection
{
	int class_id;
	float confidence;
	cv::Rect box;
};

class Detector
{
public:
	std::vector<Detection>& detect(cv::Mat frame);
	static Detector* getInstance(string onnx_path);
	bool isReady();
	static void Destroy();
	std::vector<Detection> output;

private:
	const float INPUT_WIDTH = 640.0;//input shape of the module
	const float INPUT_HEIGHT = 640.0;//input shape of the module
	const float SCORE_THRESHOLD = 0.2;
	const float NMS_THRESHOLD = 0.4;
	const float CONFIDENCE_THRESHOLD = 0.2;
	bool _isReady;
	cv::dnn::Net net;
	static Detector* instance;
	cv::Mat format_yolov5(const cv::Mat& source);
	~Detector();
	Detector(string onnx_path);
	bool fileExist(string name);
};
#endif

