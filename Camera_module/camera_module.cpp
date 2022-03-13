
#include "camera_module.h"

Camera* Camera::instance = NULL;

CircularVector::CircularVector(vector<int>*vector)
{
	this->array = vector;
	this->index = vector->size() - 1;
}
/// <summary>
/// Get the next item of the circular array. The initial index point to the last one, 
/// because the last camera is usually the rear camera,
///  and I want it to be the default camera.
/// </summary>
/// <returns>
/// The ID of the camera, this value can be directly used by cv,
///  e.g.,cv::capture( circularArray1.getNext() ).
/// </returns>
int CircularVector::nextItem()
{
	if (this->getSize() <= 0)
		return -1;
	this->index %= this->array->size();
	auto array = this->array;
	return array->at(this->index++);
}

int CircularVector::getSize()
{
	return this->array->size();
}

CircularVector::~CircularVector()
{
	this->index = 0;
	delete this->array;
}


/// <summary>
/// get the camera instance (singleton)
/// </summary>
/// <param name="magnify"> The level of magnification(%),
///  the bigger the number means the camera will zoom in more.
/// Range:[0,70]
/// </param>
/// <returns></returns>
Camera* Camera::getInstance(int magnify)
{
	if (Camera::instance == nullptr)
	{
		Camera::instance = new Camera(magnify);
		instance->magnify = magnify;
	}
	return Camera::instance;
}

CircularVector* Camera::getCamList()
{
	return this->CamList;
}

cv::Mat& Camera::nextFrame()
{
	this->cap >> this->frame;
	int newW = floor(this->frame.cols * ((100 - this->magnify) * 0.01));
	int newH = floor(this->frame.rows * ((100 - this->magnify) * 0.01));
	int offsetW = (this->frame.cols - newW) / 2;
	int offsetH = (this->frame.rows - newH) / 2;
	cv::Rect roi(offsetW, offsetH, newW, newH);
	this->frame = this->frame(roi);
	return this->frame;
}

void Camera::nextCamera()
{
	int nextCam = this->getCamList()->nextItem();
	if (nextCam >= 0 && nextCam != this->currentCamID)
		this->cap.open(nextCam);
}

int Camera::getCamNum()
{
	return this->getCamList()->getSize();
}

void Camera::Destory()
{
	delete Camera::instance;
	Camera::instance = nullptr;
}

Camera::Camera(int magnify=20)
{
	vector<int>* vec = new vector<int>;
	cv::VideoCapture camera;
	int device_counts = 0;
	while (true) {
		if (!camera.open(device_counts)) {
			break;
		}
		else {
			vec->push_back(device_counts++);
		}
	}
	camera.release();
	this->CamList = new CircularVector(vec);
	//cam check finished

	this->currentCamID = this->getCamList()->nextItem();
	if (this->getCamNum() > 0) {
		cap.open(this->currentCamID);
	}
	this->magnify = magnify;
	
}

Camera::~Camera()
{
	delete this->CamList;
	this->CamList = nullptr;
	this->cap.release();
}
