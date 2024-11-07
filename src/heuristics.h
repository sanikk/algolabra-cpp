#include <cmath>

constexpr double constexpr_sqrt(double x, double guess = 1.0) {
  return (std::abs(guess * guess - x) < 1e-10)
             ? guess
             : constexpr_sqrt(x, (guess + x / guess) / 2.0);
}

// constexpr double constexpr_sqrt(double x, double guess = 1.4);
//    return (std::abs(guess * guess - x) < 1e-15) ? guess
//           : constexpr_sqrt(x, (guess + x / guess) / 2.0);
// }

constexpr double DIFF = constexpr_sqrt(2.0) - 2.0;

double heuristics(int nodex, int nodey, int goalx, int goaly,
                  double other_diff = DIFF);
