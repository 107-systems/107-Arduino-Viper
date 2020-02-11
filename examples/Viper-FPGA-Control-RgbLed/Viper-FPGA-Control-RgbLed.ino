/* This example demonstrates how to control the RGB LED located on the
 * VidorCameraAdapter via MCU-FPGA interface.
 */

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <ArduinoViperFpga.h>

/**************************************************************************************
 * GLOBAL VARIABLES
 **************************************************************************************/

ArduinoViperFpga fpga;

/**************************************************************************************
 * SETUP/LOOP
 **************************************************************************************/

void setup()
{
  Serial.begin(115200);
  while(!Serial) { }

  if(ArduinoViperFpga::Status::OK != fpga.begin()) {
    Serial.println("ArduinoViperFpga::begin() failed");
  }
}

void loop()
{

}