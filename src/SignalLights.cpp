//
// Created by backo on 12/04/25.
//

#include "SignalLights.h"

SignalLight signalLight("hasMemo", 16, SignalLight::WHITE, [](const Calculator* calculator) { return true; });

SignalLight SignalLights::leds[SignalLights::signalLightsNumber] = {
        {"hasMemo", 6, SignalLight::WHITE, [](const Calculator* calculator) -> bool {
            return !calculator->memo.empty();
        }},
        // Conversió implícita de punter a bool
        {"calc", 5, SignalLight::BLUE,  [](const Calculator* calculator) -> bool {
            return calculator->activeOperation;
        }},
        {"result", 4, SignalLight::GREEN, Display::State::RESULT},
        {"keypress", 3, SignalLight::YELLOW, [](const Keypad* keypad) -> bool {
            static unsigned long lastKeypressTimestamp = 0;

            if (keypad->lastPress != ButtonInfo::NONE) {
                lastKeypressTimestamp = millis();
            }

            unsigned long timeSinceKeypress = millis() - lastKeypressTimestamp;

            return lastKeypressTimestamp != 0 && timeSinceKeypress < 200;
        }},
        {"error", 2, SignalLight::RED, Display::State::ERROR},
};

void SignalLights::updateAll(const Calculator* calculator, const Display* display, const Keypad* keypad) {
    for (auto& led : SignalLights::leds) {
        led.update(calculator, display, keypad);
    }
}