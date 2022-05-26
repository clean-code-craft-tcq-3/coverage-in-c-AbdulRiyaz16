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
  breachType == TOO_HIGH ? printf("\ntemperature is too high\n") : breachType == TOO_LOW ? printf("\ntemperature is too low\n"): printf("\ntemperature is Normal\n");
  checkAlertTarget(alertTarget,breachType);
}

void checkAlertTarget(AlertTarget alertTarget,BreachType breachType)
{
  switch(alertTarget) {
    case TO_CONTROLLER:
      sendToController(breachType);
      break;
    case TO_EMAIL:
      sendToEmail(breachType);
      break;
  }
  
}
  

void sendToController(BreachType breachType)
{
  const unsigned short header = 0xfeed;
  printf("%x : %x\n", header, breachType);
}

void sendToEmail(BreachType breachType) {
  const char* recepient = "a.b@c.com";
  breachType == TOO_HIGH ? printf("\ntemperature is too high\n") : breachType == TOO_LOW ? printf("\ntemperature is too low\n"),printf("\ntemperature is too low\n"): printf("\ntemperature is Normal\n");
}
