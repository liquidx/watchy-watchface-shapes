#include <Watchy.h>
#include "settings.h"

class Shapes : public Watchy
{
public:
  Shapes(const watchySettings &s)
      : Watchy(s) {}
  void drawWatchFace()
  {
    display.fillScreen(GxEPD_BLACK);
    display.fillCircle(120, 120, 100, GxEPD_WHITE);
  }
};

Shapes watchy(settings);

void setup()
{
  watchy.init();
}

void loop() {}
