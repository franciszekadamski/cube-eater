#ifndef CUBE_H
#define CUBE_H

#include "raylib.h"
#include "game_object.h"

class Cube : public GameObject {
  public:
    Cube(Vector3 position);

    void Draw() override;

    void SetPosition(Vector3 newPosition);
    void SetDimensions(Vector3 newDimensions);
    void SetColor(Color newColor);

    Vector3 GetPosition() override;
    float GetRadius() override;


  private:
    Vector3 position;
    Vector3 dimensions;
    float radius;
    Color color;

};

#endif // CUBE_H