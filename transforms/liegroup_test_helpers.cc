#include "transforms/liegroup_test_helpers.hh"

#include <Eigen/Dense>
#include <algorithm>
#include <vector>

#include "transforms/se3.hh"
#include "transforms/so3.hh"

namespace {

using SO3 = resim::transforms::SO3;
using SE3 = resim::transforms::SE3;

template <typename Vector>
Vector make_large_vector() {
  constexpr double LARGE = 1E6;
  return Vector::Random() * LARGE;
}

template <>
SO3::TangentVector make_large_vector<SO3::TangentVector>() {
  // Close to Pi
  constexpr double NEARLY_PI = M_PI - 0.01;
  constexpr double SQRT_3 = 1.732;
  constexpr double LRG_ROT = NEARLY_PI / SQRT_3;
  return SO3::TangentVector{LRG_ROT, LRG_ROT, -LRG_ROT};
}

template <>
SE3::TangentVector make_large_vector<SE3::TangentVector>() {
  return SE3::tangent_vector_from_parts(
      make_large_vector<SO3::TangentVector>(),
      make_large_vector<Eigen::Vector3d>());
}

}  // namespace

namespace resim {
namespace transforms {

template <typename Vector>
std::vector<Vector> make_test_vectors() {
  // Make random seed determistic
  constexpr unsigned int SEED = 42;
  srand(SEED);
  // How many test elements to make.
  constexpr int TEST_ELEMENT_COUNT = 7;
  std::vector<Vector> elements;
  // Add a zero element.
  elements.push_back(Vector::Zero());
  // Add a ones element.
  elements.push_back(Vector::Ones());
  // Add a negative ones element.
  elements.push_back(-Vector::Ones());
  // Add a large element.
  elements.push_back(make_large_vector<Vector>());
  // Add a tiny numbers element.
  constexpr double TINY = 1E-6;
  elements.push_back(Vector::Random() * TINY);
  // Populate the remainder with random elements.
  for (int i = elements.size(); i < TEST_ELEMENT_COUNT; ++i) {
    elements.push_back(Vector::Random());
  }
  srand(1);
  elements.resize(TEST_ELEMENT_COUNT);
  return elements;
}

template <typename Liegroup>
std::vector<typename Liegroup::TangentVector> make_test_algebra_elements() {
  return make_test_vectors<typename Liegroup::TangentVector>();
}

template <typename Liegroup>
std::vector<Liegroup> make_test_group_elements() {
  const std::vector<typename Liegroup::TangentVector> algebra_elements =
      make_test_algebra_elements<Liegroup>();
  std::vector<Liegroup> group_elements;
  group_elements.resize(algebra_elements.size());
  std::transform(
      algebra_elements.begin(),
      algebra_elements.end(),
      group_elements.begin(),
      [](const typename Liegroup::TangentVector &alg) -> Liegroup {
        return Liegroup::exp(alg);
      });
  return group_elements;
}

template std::vector<Eigen::Vector3d> make_test_vectors<Eigen::Vector3d>();
template std::vector<SO3::TangentVector> make_test_algebra_elements<SO3>();
template std::vector<SO3> make_test_group_elements<SO3>();
template std::vector<SE3::TangentVector> make_test_algebra_elements<SE3>();
template std::vector<SE3> make_test_group_elements<SE3>();

}  // namespace transforms
}  // namespace resim