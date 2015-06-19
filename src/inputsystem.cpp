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
	mCapture(0), mFaceCascade("data/haarcascade_frontalface_alt.xml"), mOldAverageDisplacement(-1.f) {}

void WebcamInputSystem::run() {
	cv::Mat frame;
	static std::vector<cv::Rect> faces;
	auto input = mEntity->get<Input>();

	mCapture >> frame;

	if(mFaceCascade.empty())
		throw std::runtime_error("Unable to open haarcascad");

	mFaceCascade.detectMultiScale(frame, faces, 1.5, 2, CV_HAAR_SCALE_IMAGE, cv::Size(1, 1));

	auto currentAverageDisplacement(0.f);

	for(auto &face : faces) {
		currentAverageDisplacement += face.x + face.width * 0.5;
		cv::Point center(face.x + face.width * 0.5, face.y + face.height * 0.5);
		cv::ellipse(frame, center, cv::Size(face.width * 0.5, face.height * 0.5), 0, 0, 360, cv::Scalar(255, 0, 255), 4, 8, 0);
	}

	if(!faces.empty()) {
		currentAverageDisplacement /= faces.size();

		// We are unable to compute displacement
		if(mOldAverageDisplacement > 0.0) {
			input.displacement = mOldAverageDisplacement - currentAverageDisplacement;

			mEntity->set(input);
		}

		mOldAverageDisplacement = currentAverageDisplacement;
	}

	imshow("lol", frame);

	cv::waitKey(10);
}