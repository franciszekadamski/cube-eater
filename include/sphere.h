#ifndef SPHERE_H
#define SPHERE_H

#include "raylib.h"
#include "game_object.h"

class Sphere : public GameObject {
  public:
    Sphere(Vector3 position);

    void Draw() override;

    void SetPosition(Vector3 newPosition);
    void SetRadius(float newRadius);
    void SetColor(Color color);

    Vector3 GetPosition() override;
    float GetRadius() override;

  private:
    Vector3 position;
    float radius;
    Color color;

};

#endif // SPHERE_H