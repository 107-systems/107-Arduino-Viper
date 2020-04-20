/**
 * @brief   Arduino library containing FPGA configuration and MCU interface code for the MKR VIDOR 4000 based Viper quadcopter.
 * @license LGPL 3.0
 */

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include "FpgaIo.h"

#include <Arduino.h>

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace Fpga
{

/**************************************************************************************
 * CTOR/DTOR
 **************************************************************************************/

FpgaIo::FpgaIo(SpiSelectFunc select, SpiDeselectFunc deselect, SpiTransferFunc transfer)
: _select{select}
, _deselect{deselect}
, _transfer{transfer}
{

}

/**************************************************************************************
 * PUBLIC MEMBER FUNCTIONS
 **************************************************************************************/

uint8_t FpgaIo::read(Register const reg)
{
  uint8_t const reg_addr = to_integer(reg);

  _select();
                          _transfer(reg_addr);
  uint8_t const reg_val = _transfer(0);
  _deselect();

  return reg_val;
}

void FpgaIo::write(Register const reg, uint8_t const reg_val)
{
  uint8_t const reg_addr = 0x80 | to_integer(reg);

  _select();
  _transfer(reg_addr);
  _transfer(reg_val);
  _deselect();
}

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* namespace Fpga */