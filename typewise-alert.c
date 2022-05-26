#include "typewise-alert.h"
#include <stdio.h>

temperatureBreach tempBreach[] = {{PASSIVE_COOLING, 0, 35}, {HI_ACTIVE_COOLING, 0, 45}, {MED_ACTIVE_COOLING, 0, 40}};

BreachType inferBreach(double value, double lowerLimit, double upperLimit)
{
  return value > upperLimit ? TOO_HIGH : value < lowerLimit ? TOO_LOW : NORMAL;
}

BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC)
{
  return inferBreach(temperatureInC, tempBreach[coolingType].lowerLimit, tempBreach[coolingType].upperLimit);
}

void checkAndAlert(AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC)
{
  BreachType breachType = classifyTemperatureBreach(batteryChar.coolingType, temperatureInC);
}
  

void sendToController(BreachType breachType)
{
  const unsigned short header = 0xfeed;
  printf("%x : %x\n", header, breachType);
}

void sendToEmail(BreachType breachType) {
  const char* recepient = "a.b@c.com";
}
