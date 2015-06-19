#include "../include/inputsystem.hpp"

void KeyboardInputSystem::run() {
	auto input = mEntity->get<Input>();

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		input.displacement = -0.2f;

	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		input.displacement = 0.2f;

	else 
		input.displacement = 0.f;

	mEntity->set(input);
}

WebcamInputSystem::WebcamInputSystem() :
	mCapture(0), mFaceCascade("data/haarcascade_frontalface_alt.xml"), mAverageX(-1.f), mAverageY(-1.f) {}

void WebcamInputSystem::run() {
	cv::Mat frame;
	static std::vector<cv::Rect> faces;

	mCapture >> frame;

	if(mFaceCascade.empty())
		throw std::runtime_error("Unable to open haarcascad");

	mFaceCascade.detectMultiScale(frame, faces, 1.1, 1, CV_HAAR_SCALE_IMAGE, cv::Size(1, 1));

	

	for(auto &face : faces) {
		cv::Point center(face.x + face.width * 0.5, face.y + face.height * 0.5);
		cv::ellipse(frame, center, cv::Size(face.width * 0.5, face.height * 0.5), 0, 0, 360, cv::Scalar(255, 0, 255), 4, 8, 0);
	}

	imshow("lol", frame);

	cv::waitKey(10);
}