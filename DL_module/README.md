## Usage Example
```
 	auto cam = Camera::getInstance();
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
  
  ## Training log
  + Training config:
  	+ Optimizer: RMSprop
  	+ Learning rate scheme: step decay
  	+ Augmentation: random crop/resize, random flip, random color augmentation, random style changing.
  + result: 90% top-1 acc on val set, 87% top-1 acc on test set.
  &emsp;
<img src="https://github.com/bchuh/ImageLib/blob/master/2022.4.12/lr.jpg" width = "500" height = "500" alt="Picture missing" align=center />
<img src="https://github.com/bchuh/ImageLib/blob/master/2022.4.12/loss_acc.jpg" width = "1000" height = "500" alt="Picture missing" align=center />
