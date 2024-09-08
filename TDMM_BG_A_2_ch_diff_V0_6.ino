// TDMM - the talking digital multimeter - 
// Michael Klein 2024 - made for AZ Delivery Blog
//  
// Thanks to: Rob.Tillaart for https://github.com/RobTillaart/ADS1X15

#include <ADS1X15.h>
#include <U8g2lib.h>

//setup OLED-display
U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/U8X8_PIN_NONE); u8g2_uint_t offset;
u8g2_uint_t width;
const char *text = "-- TDMM --";
int16_t val_00 =0; int16_t val_01 =0;

ADS1115 ADS(0x48);

void setup() {
  Serial.begin(19200);
  Serial.println(__FILE__);
  Serial.print("ADS1X15_LIB_VERSION: "); Serial.println(ADS1X15_LIB_VERSION);
  
  ADS.begin();

  if (!ADS.begin()) {
        Serial.println("address ADS1115 or 0x48 not found");
      }
      if (!ADS.isConnected()) {
        Serial.println("address 0x48 not found");  
      }
  Serial.println("AD1115 is properly connected.");
  
  ADS.setGain(0);

  u8g2.begin();
  u8g2.setFont(u8g2_font_ncenB14_tr);
  width = u8g2.getUTF8Width(text);
  u8g2.setFontMode(0);
  delay(3500); // show start screen
}

void loop() {
  val_01=0;
  for (int x=0; x<10; x++){
    val_00 = ADS.readADC_Differential_0_1();  
    val_01=val_01+val_00;
    delay(2); // delay 2ms
  }
  val_01=val_01/10; // mean value
  float volts_01 = ADS.toVoltage(val_01)*22.74; // multiplier 
  String voltsString = String(volts_01);
  Serial.print("U: "); Serial.print(voltsString); Serial.println(" Volt");

  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_ncenB12_tf);
  // Messwert auf Display darstellen
  u8g2.setCursor(0, 20);
  u8g2.print("U = ");u8g2.print(voltsString);u8g2.print(" Volt");

  u8g2.sendBuffer();

  delay(2000);
}
