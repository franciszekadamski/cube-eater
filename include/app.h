#ifndef APP_H
#define APP_H

#include <vector>
#include <memory>

#include "game_object.h"
#include "cube.h"
#include "sphere.h"

class App {
  public:
    App(
      const int windowHeight,
      const int windowWidth
    );
    void InitCamera();
    void SetupWindow(const char* windowTitle = "Visualization");
    void run();
    void AddDefaultCube(Vector3 cubePosition);
    void AddDefaultCubes(const int numberOfCubes);
    void AddDefaultSphere(Vector3 spherePosition);
    void AddDefaultSpheres(const int numberOfSpheres);
    void SetLow(int const newLow);
    void SetHigh(int const newHigh);
  
  private:
    Camera3D camera;
    const int windowWidth;
    const int windowHeight;
    int Low;
    int High;
    int cubesEaten;
    std::vector<std::shared_ptr<GameObject>> gameObjects;
    void HeaderFunction();
    void BodyFunction();
    void FooterFunction();
};

#endif // APP_H
