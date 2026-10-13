#include <exception>
#include <iostream>
#include <stdexcept>
namespace trushin {
  int inMass(int *x);
  int sumPif(const int *x);
  int newMass(int *x);
} // namespace trushin

int main()
{
  int x[3];
  int sum = 0;
  int n = 1;
  try {
    const int k = trushin::inMass(x);
    if (k < 3) {
      std::cout << 0 << '\n';
      return 0;
    }
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
    return 1;
  }
  while (n != 0) {
    sum = sum + trushin::sumPif(x);
    try {
      n = trushin::newMass(x);
    } catch (const std::exception &e) {
      std::cerr << e.what() << '\n';
      return 1;
    }
  }
  std::cout << sum << '\n';
}

int trushin::inMass(int *x)
{
  for (int i = 0; i < 3; ++i) {
    std::cin >> x[i];
    if (std::cin.fail()) {
      throw std::logic_error("Error: input is not a sequence");
    }
    if (x[i] == 0) {
      return i;
    }
  }
  return 3;
}

int trushin::sumPif(const int *x)
{
  if (x[0] <= 0 || x[1] <= 0 || x[2] <= 0) {
    return 0;
  }
  const long long a = x[0];
  const long long b = x[1];
  const long long c = x[2];
  if (c * c == a * a + b * b) {
    return 1;
  }
  return 0;
}

int trushin::newMass(int *x)
{
  int y = 0;
  std::cin >> y;
  if (std::cin.fail()) {
    throw std::logic_error("Error: input is not a sequence");
  }
  if (y == 0) {
    return 0;
  } else {
    x[0] = x[1];
    x[1] = x[2];
    x[2] = y;
  }
  return y;
}
