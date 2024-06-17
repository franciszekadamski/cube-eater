#include <algorithm>
namespace RLGL {
  #include "rlgl.h"
}

#include "app.h"
#include "cube.h"
#include "sphere.h"
#include "tools_mod.h"

App::App(const int windowHeight, const int windowWidth) : 
    camera { 0 },
    cubesEaten { 0 },
    windowWidth(windowWidth),
    windowHeight(windowHeight)
    {}

void App::InitCamera() {
  camera.position = (Vector3){ 2.0f, 2.0f, 2.0f };
  camera.target = (Vector3){ 0.0f, 0.2f, 0.0f };
  camera.up = { 0.0f, 0.1f, 0.0f };
  camera.fovy = 50.0f;
  camera.projection = CAMERA_PERSPECTIVE;
}

void App::SetupWindow(const char* windowTitle) {
  InitWindow(
    windowWidth,
    windowHeight,
    windowTitle
  );

  DisableCursor();
  SetTargetFPS(60);
}

void App::run() {
    while (!WindowShouldClose()) {
        HeaderFunction();
        BodyFunction();
        FooterFunction();
    }
    CloseWindow();
}

void App::HeaderFunction() {
  UpdateCamera(&camera, CAMERA_FREE);
  BeginDrawing();
  ClearBackground(BLACK);
  BeginMode3D(camera);
}

void App::BodyFunction() {
    float player_size = 0.15f;
    DrawSphere(camera.target, player_size, BLUE);
    DrawSphereWires(camera.target, player_size, 13, 13, DARKPURPLE);
    for (const auto& gameObject : gameObjects) {
      if (
        CheckCollisionSpheres(
          camera.target,
          player_size,
          gameObject->GetPosition(),
          gameObject->GetRadius()
        )
      ) {
          gameObject->SetPosition(GenerateRandomPoint(Low + camera.target.x, High + camera.target.x));
          ++cubesEaten;
      }
      gameObject->Draw();
    }
}

void App::FooterFunction() {
  EndMode3D();
  DrawText(TextFormat("CUBES EATEN: %i", cubesEaten), 10, 40, 20, LIME);
  DrawText(TextFormat("CURRENT POSITION: \nx: %f\ny: %f\nz: %f", camera.target.x, camera.target.y, camera.target.z), 10, 70, 20, LIME);
  DrawFPS(10, 10);
  EndDrawing();
}

void App::AddDefaultCube(Vector3 cubePosition) {
    auto cube = std::make_shared<Cube>(cubePosition);
    auto edge_size = GenerateRandomFloat(0.05f, 0.3f);
    cube->SetDimensions(Vector3(edge_size, edge_size, edge_size));
    cube->SetColor(ORANGE);
    cube->SetPosition(cubePosition);
    gameObjects.push_back(cube);
}

void App::AddDefaultCubes(const int numberOfCubes) {
  auto positions = GenerateRandomPoints(numberOfCubes, Low, High);
  for (const auto &cubePosition : positions) {
    AddDefaultCube(cubePosition);
  }
}

void App::AddDefaultSphere(Vector3 spherePosition) {
    auto sphere = std::make_shared<Sphere>(spherePosition);
    auto radius = GenerateRandomFloat(0.05f, 3.0f);
    sphere->SetRadius(radius);
    sphere->SetColor(ORANGE);
    sphere->SetPosition(spherePosition);
    gameObjects.push_back(sphere);
}

void App::AddDefaultSpheres(const int numberOfSpheres) {
  auto positions = GenerateRandomPoints(numberOfSpheres, Low, High);
  for (const auto &spherePosition : positions) {
    AddDefaultSphere(spherePosition);
  }
}

void App::SetLow(const int newLow) {
  Low = newLow;
}

void App::SetHigh(const int newHigh) {
  High = newHigh;
}
