#include "app.h"
#include "tools_mod.h"

int main() {
  App app { 800, 1200 };
  
  app.SetupWindow();
  app.InitCamera();
  app.SetLow(-100);
  app.SetHigh(100);
  app.AddDefaultCubes(1000);
  app.run();

  return 0;
}
