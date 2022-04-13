#include "detector.h"

//using namespace std;
using namespace cv;
Detector* Detector::instance = nullptr;


std::vector<Detection>& Detector::detect(cv::Mat frame)
{
    cv::Mat blob;

    auto input_image = format_yolov5(frame);

    cv::dnn::blobFromImage(input_image, blob, 1. / 255., cv::Size(INPUT_WIDTH, INPUT_HEIGHT), cv::Scalar(), true, false);
    net.setInput(blob);
    std::vector<cv::Mat> outputs;
    net.forward(outputs, net.getUnconnectedOutLayersNames());

    float x_factor = input_image.cols / INPUT_WIDTH;
    float y_factor = input_image.rows / INPUT_HEIGHT;

    float* data = (float*)outputs[0].data;

    const int dimensions = 85;
    const int rows = 25200;

    std::vector<int> class_ids;
    std::vector<float> confidences;
    std::vector<cv::Rect> boxes;

    output.clear();
    for (int i = 0; i < rows; ++i) {

        float confidence = data[4];
        if (confidence >= CONFIDENCE_THRESHOLD) {

            float* classes_scores = data + 5;
            cv::Mat scores(1, 80, CV_32FC1, classes_scores);
            cv::Point class_id;
            double max_class_score;
            minMaxLoc(scores, 0, &max_class_score, 0, &class_id);
            if (max_class_score > SCORE_THRESHOLD) {

                confidences.push_back(confidence);

                class_ids.push_back(class_id.x);

                float x = data[0];
                float y = data[1];
                float w = data[2];
                float h = data[3];
                int left = int((x - 0.5 * w) * x_factor);
                int top = int((y - 0.5 * h) * y_factor);
                int width = int(w * x_factor);
                int height = int(h * y_factor);
                boxes.push_back(cv::Rect(left, top, width, height));
            }

        }

        data += 85;

    }

    std::vector<int> nms_result;
    cv::dnn::NMSBoxes(boxes, confidences, SCORE_THRESHOLD, NMS_THRESHOLD, nms_result);
    for (int i = 0; i < nms_result.size(); i++) {
        int idx = nms_result[i];
        Detection result;
        result.class_id = class_ids[idx];
        //if (result.class_id != 0)
        //    continue;
        result.confidence = confidences[idx];
        result.box = boxes[idx];
        output.push_back(result);
    }
    return output;
}

Detector* Detector::getInstance(std::string onnx_path)
{
	if (Detector::instance == nullptr)
	{
		Detector::instance = new Detector(onnx_path);
	}
	return Detector::instance;
}

bool Detector::isReady()
{
	return this->_isReady;
}

void Detector::Destroy()
{
	delete Detector::instance;
	Detector::instance = nullptr;
}

Detector::Detector(std::string onnx_path):output()
{
	String bin_model = onnx_path;
	if (!fileExist(bin_model)) {
		int temp;
		this->_isReady = false;
        std::cout << "Detector Error: Can't open(or find) file:" << bin_model << std::endl;
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

cv::Mat Detector::format_yolov5(const cv::Mat& source)
{
	int col = source.cols;
	int row = source.rows;
	int _max = MAX(col, row);
	cv::Mat result = cv::Mat::zeros(_max, _max, CV_8UC3);
	source.copyTo(result(cv::Rect(0, 0, col, row)));
	return result;
}

Detector::~Detector()
{
	this->_isReady = false;
}

bool Detector::fileExist(std::string name)
{
	if (FILE* file = fopen(name.c_str(), "r")) {
		fclose(file);
		return true;
	}
	else {
		return false;
	}
}
