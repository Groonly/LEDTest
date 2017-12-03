#include  "../unity/extras/fixture/src/unity_fixture.h"
#include "../src/LedDriver.h"
#include <stdint.h>

TEST_GROUP(LedDriver);

static uint16_t virtualLeds;

TEST_SETUP(LedDriver){
  LedDriver_Create(&virtualLeds);
}

TEST_TEAR_DOWN(LedDriver){

}

TEST(LedDriver, LedsOffAfterCreate){
  uint16_t virtualLeds = 0xffff;
  LedDriver_Create(&virtualLeds);
  TEST_ASSERT_EQUAL_HEX16(0, virtualLeds);
}

TEST(LedDriver, TurnOnLedOne){
  LedDriver_TurnOn(1);
  TEST_ASSERT_EQUAL_HEX16(1, virtualLeds);
}

TEST(LedDriver, TurnOffLedOne){
  LedDriver_TurnOn(1);
  LedDriver_TurnOff(1);
  TEST_ASSERT_EQUAL_HEX16(0, virtualLeds);
}

TEST(LedDriver, TurnOnMultipleLeds){
  LedDriver_TurnOn(9);
  LedDriver_TurnOn(8);
  TEST_ASSERT_EQUAL_HEX16(0x180, virtualLeds);
}

TEST(LedDriver, TurnOffAnyLed){
  LedDriver_TurnAllOn();
  LedDriver_TurnOff(8);
  TEST_ASSERT_EQUAL_HEX16(0xff7f, virtualLeds);
}

TEST(LedDriver, AllOn){
  LedDriver_TurnAllOn();
  TEST_ASSERT_EQUAL_HEX(0xffff, virtualLeds);
}
TEST(LedDriver, LEDMemoryIsNotReadable){
  virtualLeds = 0xffff;
  LedDriver_TurnOn(8);
  TEST_ASSERT_EQUAL_HEX16(0x0080, virtualLeds);
}
TEST(LedDriver, UpperAndLowerBounds){
  LedDriver_TurnOn(1);
  LedDriver_TurnOn(16);
  TEST_ASSERT_EQUAL_HEX16(0x8001, virtualLeds);
}
TEST(LedDriver, OutOfBoundsChangesNothing){
  LedDriver_TurnOn(-1);
  LedDriver_TurnOn(0);
  LedDriver_TurnOn(17);
  LedDriver_TurnOn(3141);
  TEST_ASSERT_EQUAL_HEX16(0, virtualLeds);
}
