#include "cube.h"
#include "raylib.h"

Cube::Cube(
  Vector3 position
) : GameObject(position) {}

void Cube::Draw() {
  DrawCube(
    position,
    dimensions.x,
    dimensions.y,
    dimensions.z,
    color
  );
  DrawCubeWires(
    position,
    dimensions.x,
    dimensions.y,
    dimensions.z,
    RAYWHITE
  );
}

void Cube::SetPosition(Vector3 newPosition) {
  position = newPosition;
}

void Cube::SetDimensions(Vector3 newDimensions) {
  dimensions = newDimensions;
  radius = dimensions.x / 2;
}

void Cube::SetColor(Color newColor) {
  color = newColor;
}

Vector3 Cube::GetPosition() {
  return position;
}

float Cube::GetRadius() {
  return radius;
}