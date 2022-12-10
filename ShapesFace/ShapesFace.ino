#include <Watchy.h>
#include "settings.h"

class Shapes : public Watchy {
public:
  Shapes(const watchySettings &s)
    : Watchy(s) {}
  void drawWatchFace() {

    // float voltage = getBatteryVoltage();
    // int16_t radius = 25 + (int16_t)(10 * voltage);
    int16_t radius = 65;
    int16_t centerX = 100;
    int16_t centerY = 100;

    display.fillScreen(GxEPD_WHITE);
    display.fillCircle(centerX, centerY, radius, GxEPD_BLACK);

    uint8_t hourMode = 12;
    float dotOffset = 4;
    float dotRadius = 12;
    for (uint8_t hour = 0; hour < hourMode; hour++) {
      float angle = (2 * PI / hourMode) * hour;
      float xoff1 = (radius)*sin(angle);
      float yoff1 = -(radius)*cos(angle);
      display.fillCircle(centerX + (int16_t)xoff1, centerY + (int16_t)yoff1, dotRadius + 1, GxEPD_WHITE);
      if (hour <= currentTime.Hour % hourMode) {
        float xoff2 = (radius + dotOffset) * sin(angle);
        float yoff2 = -(radius + dotOffset) * cos(angle);
        display.fillCircle(centerX + (int16_t)xoff2, centerY + (int16_t)yoff2, dotRadius, GxEPD_BLACK);
      }
    }

    // Diasbled

    // display.setTextColor(GxEPD_WHITE);
    //  display.setFont(&FreeMonoBold9pt7b);

    // display.setFont(&DSEG7_Classic_Bold_53);
    // display.setCursor(50, 120);
    // display.print(currentTime.Hour);
  }
};

Shapes watchy(settings);

void setup() {
  watchy.init();
}

void loop() {}
