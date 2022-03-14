#include "DL_module.h"

using namespace std;
using namespace cv;
Classifier* Classifier::instance = nullptr;
DLmodule* DLmodule::instance = nullptr;

int Classifier::classify(cv::Mat inputFrame)
{
	Mat frame, blob;
	inputFrame.copyTo(frame);
	resize(frame, frame, Size(256, 256), INTER_AREA);
	frame.convertTo(frame, CV_32FC3);
	preProcess(frame, frame);
	dnn::blobFromImage(frame, blob, 1.0, Size(224,224), Scalar(0, 0, 0), false, true);
	net.setInput(blob);
	Mat prob = net.forward();
	Point classIdPoint;
	double confidence;
	minMaxLoc(prob.reshape(1, 1), 0, &confidence, 0, &classIdPoint);
	int classId = classIdPoint.x;
	return classId;
}

Classifier* Classifier::getInstance()
{
	if (Classifier::instance == nullptr)
	{
		Classifier::instance = new Classifier;
	}
	return Classifier::instance;
}

bool Classifier::isReady()
{
	return this->_isReady;
}

void Classifier::Destroy()
{
	delete Classifier::instance;
	Classifier::instance = nullptr;
}

Classifier::Classifier()
{
	String bin_model = "DL_module\\mobilenet.onnx";
	if (!fileExist(bin_model)) {
		int temp;
		this->_isReady = false;
		cout << "DL_module Error: Can't open(or find) file:" << bin_model << endl;
		//Can't read .onnx, please contact Zhu Zengliang if you encounter this.
		cin >> temp;
		return;
	}
	else {
		this->net = cv::dnn::readNet(bin_model);  // 加载训练好的识别模型
		this->net.setPreferableBackend(cv::dnn::DNN_BACKEND_OPENCV);
		this->_isReady = true;
	}
}

Classifier::~Classifier()
{
	this->_isReady = false;
}

bool Classifier::fileExist(string name)
{
	if (FILE* file = fopen(name.c_str(), "r")) {
		fclose(file);
		return true;
	}
	else {
		return false;
	}
}

void Classifier::preProcess(const cv::Mat& image, cv::Mat& image_blob)
{
	Mat input;
	image.copyTo(input);


	//normalize the image
	std::vector<Mat> channels, channel_p;
	split(input, channels);
	Mat R, G, B;
	B = channels.at(0);
	G = channels.at(1);
	R = channels.at(2);

	B = (B / 255. - 0.406) / 0.225;
	G = (G / 255. - 0.456) / 0.224;
	R = (R / 255. - 0.485) / 0.229;

	channel_p.push_back(R);
	channel_p.push_back(G);
	channel_p.push_back(B);

	Mat outt;
	merge(channel_p, outt);
	outt.copyTo(image_blob);
}

DLmodule* DLmodule::getInstance()
{
	if (DLmodule::instance == nullptr)
	{
		DLmodule::instance = new DLmodule();
	}
	return DLmodule::instance;
}

int DLmodule::classify(const cv::Mat& frame)
{
	return this->classifier->classify(frame);
}

void DLmodule::Destory()
{
	delete DLmodule::instance;
	DLmodule::instance = nullptr;
}

bool DLmodule::isReady()
{
	return classifier->isReady();
}

DLmodule::DLmodule()
{
	this->classifier = Classifier::getInstance();
}

DLmodule::~DLmodule()
{
	Classifier::Destroy();
	this->classifier = nullptr;
}
