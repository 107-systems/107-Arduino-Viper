---------------------------------------------------------------
-- Viper Quadcopter MKR VIDOR 4000 FPGA Code
-- (C) Alexander Entinger, MSc / LXRobotics GmbH
-- GNU LGPL V3.0
---------------------------------------------------------------

architecture Rtl of ViperQuadcopterTop is

  constant cRgbLedColour : aRgbLedColour := Cyan;

  -- PLL output signals
  signal pll_clock_c0_192MHz : std_ulogic;
  signal pll_locked          : std_ulogic;

  -- SPI sync signals
  signal iMosiSync : std_ulogic;
  signal iSckSync : std_ulogic;
  signal inCsSync : std_ulogic;
  
begin

  rgb_led_encoder : entity work.RgbLedEncoder(Rtl)
  port map
  (
    iColour => cRgbLedColour,
    oRed    => oLED_R,
    oGreen  => oLED_G,
    oBlue   => oLED_B
  );

  syspll_inst : entity work.syspll(SYN)
  port map
  (
    areset => inResetAsync,
    inclk0 => iClk,
    c0     => pll_clock_c0_192MHz,
    locked => pll_locked
  );

  spisync_inst : entity work.SpiSynchronizer(Rtl)
  port map
  (
      iClk       => iClk,
      inReset    => pll_locked,
      iMosiAsync => iMOSI,
      iSckAsync  => iSCK,
      inCsAsync  => inCS,
      oMosiSync  => iMosiSync,
      oSckSync   => iSckSync,
      onCsSync   => inCsSync
  );

end Rtl;
