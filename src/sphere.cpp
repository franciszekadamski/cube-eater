#include "sphere.h"
#include "raylib.h"

Sphere::Sphere(
  Vector3 position
) : GameObject(position) {}

void Sphere::Draw() {

  DrawSphere(
    position,
    radius,
    color
  );
  DrawSphereWires(
    position,
    radius,
    15,
    15,
    DARKGRAY
  );
}

void Sphere::SetPosition(Vector3 newPosition) {
  position = newPosition;
}

void Sphere::SetRadius(float newRadius) {
  radius = newRadius;
}

void Sphere::SetColor(Color newColor) {
  color = newColor;
}

Vector3 Sphere::GetPosition() {
  return position;
}

float Sphere::GetRadius() {
  return radius;
}