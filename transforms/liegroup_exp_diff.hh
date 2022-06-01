#pragma once

namespace resim {
namespace transforms {

// This library contains some helper functions to compute the derivatives
// of the exp and log mapping functions for Liegroups (SO3 and SE3).
// The naming conventions used follow the document "Derivative of the
// Exponential Map", available here: https://ethaneade.com/exp_diff.pdf

// Computing the derivatives of exp for both SO3 and SE3 involves computing
// an expression of the form a*I + b*omega + c*omega*omegaT, where a, b c are
// coefficients. See eq. 53 and eq. 70 in https://ethaneade.com/exp_diff.pdf.
// This struct is a useful container for holding these coefficients.
struct ExpDiffCoeffs {
  double a;
  double b;
  double c;
};

// Returns the exponential map coefficients for computing the derivative
// of exp for SO3. See eq. 53 in https://ethaneade.com/exp_diff.pdf.
// [param] square_angle - The square of the angle of rotation. Also the squared
//                        norm of the algebra element.
ExpDiffCoeffs derivative_of_exp_so3(const double square_angle);

}  // namespace transforms
}  // namespace resim
