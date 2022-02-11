#include "rlbot/botprocess.h"

#include "rlbot/packets.h"
#include "rlbot/platform.h"
#include "rlbot/bmInterface.h"
#include "shared/SharedObjects.h"

namespace rlbot {
void BotProcess::Start() {
	running = true;
	thread = std::thread(&BotProcess::BotThread, this);
}

void BotProcess::Stop() {
	running = false;
	thread.join();
}

void BotProcess::BotThread() const {
	// wait for legacy RLBot interface to be initialized
	while (!Interface::IsInitialized())
		platform::SleepMilliseconds(1);

	GameState state;
	RLBot::bmInterface->getCurrentState(state);
	while (running) {
		rlbot::bmInterface->setBotInput(bot->GetInput(state), bot->index);

		RLBot::bmInterface->waitNextTick(state);
	}
}

} // namespace rlbot
