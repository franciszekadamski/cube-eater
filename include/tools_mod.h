#ifndef TOOLS_MOD_H
#define TOOLS_MOD_H

#include <vector>
#include "raylib.h"

void print_points3D(std::vector<Vector3> points3D);

std::vector<Vector3> filterBackground(const std::vector<Vector3> points);

float Deg2Rad(float degrees);

Vector3 Vector3Add(Vector3 v1, Vector3 v2);

float GenerateRandomFloat(float min, float max);

Vector3 GenerateRandomPoint(const int Low, const int High);

std::vector<Vector3> GenerateRandomPoints(
  const int numberOfPoints,
  const int Low,
  const int High
);


#endif // TOOLS_MOD_H
