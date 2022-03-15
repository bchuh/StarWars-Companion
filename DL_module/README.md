## Usage Example
```
 	auto cam=Camera::getInstance();
	auto model = DLmodule::getInstance();
	int result;
	while (true)
	{
		auto frame = cam->nextFrame();
		cv::imshow("读取视频", frame);
		result = model->classify(frame);
		std::cout << result << endl;
		if (cv::waitKey(1) != -1)
		{
			Camera::Destory();
			DLmodule::Destory();
			std::cout << "finished by user\n";
			break;
		}
	}
  ```
