#include <vector>
#include "matplotlibcpp.h"
namespace plt = matplotlibcpp;

int main() {
    std::vector<double> x = {1, 2, 3, 4};
    std::vector<double> y = {1, 4, 9, 16};
    printf("HELLO\r\n");
    plt::plot(x, y);
    plt::show();

  return 0;
}
