## Usage example用法示范
```
	Camera* cam=Camera::getInstance();
	while (true)
	{
		auto frame = cam->nextFrame();
		cv::imshow("读取视频", frame);
		if (cv::waitKey(1) != -1)
		{
			Camera::Destory();
			std::cout << "finished by user\n";
			break;
		}
	}
```
