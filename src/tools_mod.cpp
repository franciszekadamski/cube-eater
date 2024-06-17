#include <vector>
#include <random>
#include <iostream>

#include "raylib.h"
#include "tools_mod.h"


void print_points3D(std::vector<Vector3> points3D) {
  std::cout << "Points:" << std::endl;
  for (const auto &point : points3D) {
    std::cout << "[" << point.x << ", " << point.y << ", " << point.z << "]" << std::endl;
  }
}


std::vector<Vector3> filterBackground(const std::vector<Vector3> points) {
  std::vector<Vector3> filtered_points; 
  for (auto &point : points) {
    if (point.z < 0.4f) {
      filtered_points.push_back(point);
    }
  }

  return filtered_points;
}

float Deg2Rad(float degrees) {
  return degrees * (M_PI / 180.0f);
}

Vector3 Vector3Add(Vector3 v1, Vector3 v2) {
  Vector3 result;
  result.x = v1.x + v2.x;
  result.y = v1.y + v2.y;
  result.z = v1.z + v2.z;
  return result;
}

float GenerateRandomFloat(float min, float max) {
  std::random_device rd;
  std::mt19937 engine(rd());
  std::uniform_real_distribution<float> distribution(min, max);
  return distribution(engine);
}

Vector3 GenerateRandomPoint(const int Low, const int High) {
  auto x = GenerateRandomFloat(Low, High);
  auto y = GenerateRandomFloat(Low, High);
  auto z = GenerateRandomFloat(Low, High);
  auto point = Vector3(x, y, z);
  return point;
}

std::vector<Vector3> GenerateRandomPoints(
  const int numberOfPoints,
  const int Low,
  const int High
) {
  std::vector<Vector3> points;
  Vector3 point;
  for (int i = 0; i < numberOfPoints; ++i) {
    point = GenerateRandomPoint(Low, High);
    points.push_back(point);
  }

  return points;
}

