#pragma once

#include "shared/SharedObjects.h"

namespace rlbot {
struct Controller {
  float throttle;
  float steer;
  float pitch;
  float yaw;
  float roll;
  bool jump;
  bool boost;
  bool handbrake;
  bool useItem;

  operator RLBotBM::Shared::ControllerInput() const {
	return {
		.throttle = throttle,
		.steer = steer,
		.pitch = pitch,
		.yaw = yaw,
		.roll = roll,
		.handbrake = handbrake,
		.jump = jump,
		.boost = boost,
		// .useItem = useItem,
	};
  }
};
} // namespace rlbot
