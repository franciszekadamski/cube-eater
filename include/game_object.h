#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <variant>
#include <iostream>
#include "raylib.h"

class GameObject {
  public:
    GameObject(
      Vector3 position
    );
    virtual ~GameObject() = default;

    virtual void Draw() = 0;
    virtual void SetPosition(Vector3 newPosition) = 0;

    virtual Vector3 GetPosition() = 0;
    virtual float GetRadius() = 0;

  protected:
    Vector3 position;
    float radius;
};

#endif // GAME_OBJECT_H