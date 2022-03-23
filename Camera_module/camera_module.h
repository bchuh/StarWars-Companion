#ifndef CAMERA
#define CAMERA

#include <opencv2\opencv.hpp>
using namespace std;
class CircularVector
{
public:
	CircularVector(vector<int>*vector);
	int nextItem();
	int getSize();
	~CircularVector();

private:
	vector<int>* array;
	int index; //current index
};

class Camera
{
public:
	static Camera* getInstance(int magnify=20);//magnify means zoom in the camera 
	CircularVector* getCamList();
    cv::Mat& nextFrame(int width=-1, int height=-1);//provide crop configuration
	void nextCamera();
	int getCamNum();
	static void Destory();

private:
	Camera(int);
	~Camera();
	CircularVector* CamList;//camera list
	static Camera* instance;
	int currentCamID;
	cv::VideoCapture cap;
	int magnify;
	cv::Mat frame;


};

#endif	



