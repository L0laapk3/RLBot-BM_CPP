#pragma once
#include "rlbot/interface.h"
#include "rlbot/packets.h"
#include "rlbot/rlbot_generated.h"
#include "RLBotBM.h"

#include <string>

namespace rlbot {
class Bot {
private:
  int lastMessageIndex = -1;

public:
  int index;
  int team;
  std::string name;

  Bot(int index, int team, std::string name);
  virtual ~Bot() {}
  virtual RLBotBM::ControllerInput GetOutput(RLBotBM::GameState& state) = 0;

  BallPrediction GetBallPrediction();
  FieldInfo GetFieldInfo();
  MatchInfo GetMatchInfo();

  void SendQuickChat(rlbot::flat::QuickChatSelection message, bool teamOnly);
  QuickChatMessages ReceiveQuickChat();
};
} // namespace rlbot
