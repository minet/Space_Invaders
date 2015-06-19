#ifndef INPUT_SYSTEM_HPP
#define INPUT_SYSTEM_HPP

#include "system.hpp"
#include <opencv2/opencv.hpp>

class AbstractInputSystem : public AbstractSystem {
public:
	AbstractInputSystem() = default;

	/**
	 * @brief Add an entity to this system
	 * @details Implementations use an unique entity
	 * 
	 * @param entity
	 */
	void addEntity(std::shared_ptr<Entity> const &entity) override {
		assert(entity != nullptr);
		assert(entity->have<Input>());

		mEntity = entity;
	}

	virtual ~AbstractInputSystem() = default;

protected:
	std::shared_ptr<Entity> mEntity;
};

/**
 * @brief This system is used to manage all input in our game
 */
class KeyboardInputSystem : public AbstractInputSystem {
public:
	KeyboardInputSystem() = default;

	/**
	 * @brief Execute this system
	 */
	void run() override;

	~KeyboardInputSystem() = default;
};


class WebcamInputSystem : public AbstractInputSystem {
public:
	WebcamInputSystem();

	/**
	 * @brief Execute this system
	 */
	void run() override;

	~WebcamInputSystem() = default;

private:
	cv::VideoCapture mCapture;
	cv::CascadeClassifier mFaceCascade;
	float mAverageX;
	float mAverageY;
};

#endif