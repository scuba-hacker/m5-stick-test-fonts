#define TEXT "aA MWyz~12" // Text that will be printed on screen in any font

#include "Free_Fonts.h"

#include <M5StickCPlus.h>

#include <TFT_eSPI.h>
#include <TFT_eWidget.h>  // Widget library

#include "NotoSansBold15.h"
#include "NotoSansBold36.h"
#include "NotoSansMonoSCB20.h"
#include "Final_Frontier_28.h"
#include "Latin_Hiragana_24.h"
#include "Unicode_Test_72.h"

uint16_t bg = TFT_BLACK;
uint16_t fg = TFT_WHITE;

// The font names are arrays references, thus must NOT be in quotes ""
#define AA_FONT_SMALL NotoSansBold15
#define AA_FONT_LARGE NotoSansBold36
#define AA_FONT_MONO  NotoSansMonoSCB20 // NotoSansMono-SemiCondensedBold 20pt

// Stock font and GFXFF reference handle
#define GFXFF 1
#define FF18 &FreeSans12pt7b

// Custom are fonts added to library "TFT_eSPI\Fonts\Custom" folder
// a #include must also be added to the "User_Custom_Fonts.h" file
// in the "TFT_eSPI\User_Setups" folder. See example entries.
#define CF_OL24 &Orbitron_Light_24
#define CF_OL32 &Orbitron_Light_32
#define CF_RT24 &Roboto_Thin_24
#define CF_S24  &Satisfy_24
#define CF_Y32  &Yellowtail_32

unsigned long drawTime = 0;

void header(const char *string, uint16_t color);
void drawDatumMarker(int x, int y);
void button(int x, int y, int num );
float mapValue(float ip, float ipmin, float ipmax, float tomin, float tomax);

void setup_analogue_meters();

void loop_all_free_fonts_demo(); 
void loop_free_font_demo();
void loop_custom_fonts();
void loop_fast_fonts();
void loop_smooth_font_demo_1();
void loop_smooth_font_demo_2();
void loop_smooth_font_demo_3();
void loop_smooth_font_demo_4();
void unicode_font_test();
void cycle_font_demos();
void loop_analogue_meters();

TFT_eSPI& tft=M5.Lcd;
TFT_eSprite spr = TFT_eSprite(&tft); // Sprite class needs to be invoked

MeterWidget   amps  = MeterWidget(&tft);
MeterWidget   volts = MeterWidget(&tft);
MeterWidget   ohms  = MeterWidget(&tft);

#define LOOP_PERIOD 35 // Display updates every 35 ms

//  -D TFT_WIDTH=135
//  -D TFT_HEIGHT=240

void setup()
{
  tft.begin();
  tft.setRotation(1);
  spr.setColorDepth(16); // 16 bit colour needed to show anti-aliased fonts
  fg = TFT_WHITE;
  bg = TFT_BLACK;

  setup_analogue_meters();
}

void loop()
{
  cycle_font_demos();
  loop_analogue_meters();
  loop_analogue_meters();
  loop_analogue_meters();
}

void setup_analogue_meters()
{
  tft.setRotation(1);
  
  // Colour zones are set as a start and end percentage of full scale (0-100)
  // If start and end of a colour zone are the same then that colour is not used
  //            --Red--  -Org-   -Yell-  -Grn-
  amps.setZones(75, 100, 50, 75, 25, 50, 0, 25); // Example here red starts at 75% and ends at 100% of full scale
  // Meter is 239 pixels wide and 126 pixels high
  amps.analogMeter(0, 0, 2.0, "mA", "0", "0.5", "1.0", "1.5", "2.0");    // Draw analogue meter at 0, 0

/*
  // Colour draw order is red, orange, yellow, green. So red can be full scale with green drawn
  // last on top to indicate a "safe" zone.
  //             -Red-   -Org-  -Yell-  -Grn-
  volts.setZones(0, 100, 25, 75, 0, 0, 40, 60);
  volts.analogMeter(0, 128, 10.0, "V", "0", "2.5", "5", "7.5", "10"); // Draw analogue meter at 0, 128

  // No coloured zones if not defined
  ohms.analogMeter(0, 256, 100, "R", "0", "", "50", "", "100"); // Draw analogue meter at 0, 128
*/
}

void loop_analogue_meters()
{
  static int d = 0;
  static uint32_t updateTime = 0;  

  if (millis() - updateTime >= LOOP_PERIOD) 
  {
    updateTime = millis();

    d += 4; if (d > 360) d = 0;

    // Create a Sine wave for testing, value is in range 0 - 100
    float value = 50.0 + 50.0 * sin((d + 0) * 0.0174532925);

    float current;
    current = mapValue(value, (float)0.0, (float)100.0, (float)0.0, (float)2.0);
    //Serial.print("I = "); Serial.print(current);
    amps.updateNeedle(current, 0);
/*
    float voltage;
    voltage = mapValue(value, (float)0.0, (float)100.0, (float)0.0, (float)10.0);
    //Serial.print(", V = "); Serial.println(voltage);
    volts.updateNeedle(voltage, 0);
    
    float resistance;
    resistance = mapValue(value, (float)0.0, (float)100.0, (float)0.0, (float)100.0);
    //Serial.print(", R = "); Serial.println(resistance);
    ohms.updateNeedle(resistance, 0);
    */
  }
}

float mapValue(float ip, float ipmin, float ipmax, float tomin, float tomax)
{
  return tomin + (((tomax - tomin) * (ip - ipmin))/ (ipmax - ipmin));
}

#define BUILD_INCLUDE_MAIN_FONT_TESTS
#include "main_font_tests.cpp"
