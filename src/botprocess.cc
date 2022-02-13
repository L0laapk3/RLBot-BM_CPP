#include "rlbot/botprocess.h"

#include "rlbot/packets.h"
#include "rlbot/platform.h"
#include "rlbot/bmInterface.h"
#include "RLBotBM.h"

#include <iostream>


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

	RLBotBM::GameState state;
	bmInterface->getCurrentState(state);

	while (state.numCars <= bot->index) // wait for our bot to spawn
		bmInterface->waitNextTick(state);
		
	while (running) {
		bmInterface->setBotInput(bot->GetOutput(state), bot->index);

		bmInterface->waitNextTick(state);
	}
}

} // namespace rlbot
