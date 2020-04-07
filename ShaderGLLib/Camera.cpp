#include "Camera.h"
#include <cmath>
#include <glm/gtc/matrix_transform.hpp>

namespace sgl {

	Camera::Camera(
		const glm::vec3& position /*= { 0.f, 0.f, 0.f }*/, 
		const glm::vec3& front /*= { 0.f, 0.f, -1.f }*/, 
		const glm::vec3& up /*= { 0.f, 1.f, 0.f }*/) :
		position_(position),
		front_(front),
		up_(up)
	{
		UpdateCameraVectors();
	}

	const glm::mat4 Camera::GetLookAt() const
	{
		return glm::lookAt(position_, front_, up_);
	}

	void Camera::UpdateCameraVectors()
	{
		glm::vec3 front;
		front.x = std::cos(glm::radians(pitch_)) * std::cos(glm::radians(yaw_));
		front.y = std::sin(glm::radians(pitch_));
		front.z = std::cos(glm::radians(pitch_)) * std::sin(glm::radians(yaw_));
		front_ = glm::normalize(front);

		right_ = glm::normalize(glm::cross(up_, front_));
		up_ = glm::cross(front_, right_);
	}

}	// End namespace sgl.
