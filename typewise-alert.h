#pragma once

typedef enum {
  PASSIVE_COOLING,
  HI_ACTIVE_COOLING,
  MED_ACTIVE_COOLING
} CoolingType;

typedef enum {
  NORMAL,
  TOO_LOW,
  TOO_HIGH
} BreachType;


typedef enum {
  TO_CONTROLLER,
  TO_EMAIL
} AlertTarget;

typedef struct {
  CoolingType coolingType;
  char brand[48];
} BatteryCharacter;

typedef enum{
  E_OK,
  E_NOT_OK
}status;

typedef struct
{
  CoolingType coolingType ;
  double lowerLimit ;
  double upperLimit ;
} temperatureBreach;



void checkAndAlert(AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC);
BreachType inferBreach(double value, double lowerLimit, double upperLimit);
BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC);
void sendToController(BreachType breachType);
void sendToEmail(BreachType breachType);
void checkAlertTarget(AlertTarget alertTarget,BreachType breachType);
