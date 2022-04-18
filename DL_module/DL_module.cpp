#include "DL_module.h"

//using namespace std;
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

Classifier* Classifier::getInstance(std::string onnx_path)
{
	if (Classifier::instance == nullptr)
	{
		Classifier::instance = new Classifier(onnx_path);
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

Classifier::Classifier(std::string onnx_path)
{
	String bin_model = onnx_path;
	if (!fileExist(bin_model)) {
		int temp;
		this->_isReady = false;
        std::cout << "DL_module Error: Can't open(or find) file:" << bin_model << std::endl;
		//Can't read .onnx, please contact Zhu Zengliang if you encounter this.
        std::cin >> temp;
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

bool Classifier::fileExist(std::string name)
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

DLmodule* DLmodule::getInstance(std::string model_path)
{
	if (DLmodule::instance == nullptr)
	{
		DLmodule::instance = new DLmodule(model_path);
	}
	return DLmodule::instance;
}

int DLmodule::classify(const cv::Mat& frame, int result_index)
{
    if(result_index == -1) // 不进行目标裁剪
        return this->classifier->classify(frame);
    else{
        auto result = detector->output.at(result_index);
        auto frame_rect = cv::Rect(0, 0, frame.size().width, frame.size().height);
        auto cropped_frame = frame(result.box & frame_rect);
        return this->classifier->classify(cropped_frame);
    }
}
QImage DLmodule::getCroppedImage(const cv::Mat&frame, int result_index)
{
    auto result = detector->output.at(result_index);
    auto frame_rect = cv::Rect(0, 0, frame.size().width, frame.size().height);
    auto cropped_frame = frame(result.box & frame_rect);
    std::cout<<cropped_frame.cols<<','<<cropped_frame.rows<<std::endl;
    float old_ratio=cropped_frame.cols*1.0/(cropped_frame.rows);
    float new_ratio=1.65;
    int total_boarder;
    if (new_ratio>=old_ratio){
        total_boarder = floor(cropped_frame.rows * new_ratio)-cropped_frame.cols;
        cv::copyMakeBorder(cropped_frame, cropped_result, 0, 0, total_boarder/2, total_boarder/2, cv::BORDER_CONSTANT);
    }else{
        total_boarder = floor(cropped_frame.cols/new_ratio)-cropped_frame.rows;
        cv::copyMakeBorder(cropped_frame, cropped_result,total_boarder/2, total_boarder/2 ,0 ,0 , cv::BORDER_CONSTANT);
    }
    std::cout<<cropped_frame.cols<<','<<cropped_frame.rows<<std::endl;
    return QImage(cropped_result.data, cropped_result.cols, cropped_result.rows, cropped_result.step, QImage::Format_RGB888);

}

std::vector<Detection>& DLmodule::detect(cv::Mat frame)
{
	return this->detector->detect(frame);
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

DLmodule::DLmodule(std::string model_path)
{
	String classifier_path = model_path + "\\mobilenet.onnx";
	String dete_path = model_path + "\\yolov5s.onnx";
	this->classifier = Classifier::getInstance(classifier_path);
	this->detector = Detector::getInstance(dete_path);
}

DLmodule::~DLmodule()
{
	Classifier::Destroy();
	this->classifier = nullptr;
	Detector::Destroy();
	this->detector = nullptr;
}
