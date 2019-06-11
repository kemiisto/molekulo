#include "utility.h"

#include <iomanip>
#include <sstream>

std::string kemiisto::to_string(double x, int width, int precision)
{
    std::stringstream ss;
    ss << std::fixed << std::setw(width) << std::setprecision(precision) << x;
    return ss.str();
}
