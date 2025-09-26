#include <iostream>
#include <vector>
#include <string>
#include <cassert>

std::vector<std::pair<int, int>> pinWrites;
std::vector<std::string> prints;

void mockDigitalWrite(int pin, int value) {
  pinWrites.push_back({pin, value});
}

void mockSerialPrint(const char* msg) {
  prints.push_back(msg);
}

void testSmokeDetectedAndSpray() {
  pinWrites.clear();
  prints.clear();

  bool spraying = false;
  unsigned long sprayStartTime = 0;
  unsigned long currentMillis = 1000;

  processSensor(350, currentMillis, 300, 5000,
                spraying, sprayStartTime,
                mockDigitalWrite, mockSerialPrint);

  assert(spraying == true);
  assert(sprayStartTime == 1000);
  assert(pinWrites[0] == std::make_pair(2, 1));  // buzzer
  assert(pinWrites[1] == std::make_pair(13, 1)); // LED
  assert(pinWrites[2] == std::make_pair(3, 1));  // relay
  assert(prints[0].find("Smoke detected") != std::string::npos);
  std::cout << "✅ testSmokeDetectedAndSpray passed\n";
}

void testSprayComplete() {
  pinWrites.clear();
  prints.clear();

  bool spraying = true;
  unsigned long sprayStartTime = 1000;
  unsigned long currentMillis = 6000;

  processSensor(250, currentMillis, 300, 5000,
                spraying, sprayStartTime,
                mockDigitalWrite, mockSerialPrint);

  assert(spraying == false);
  assert(pinWrites[0] == std::make_pair(2, 0));  // buzzer
  assert(pinWrites[1] == std::make_pair(13, 0)); // LED
  assert(pinWrites[2] == std::make_pair(3, 0));  // relay
  assert(prints[0].find("Spray complete") != std::string::npos);
  std::cout << "✅ testSprayComplete passed\n";
}

int main() {
  testSmokeDetectedAndSpray();
  testSprayComplete();
  return 0;
}
