#include "DateTime.h"
#include <ctime>
#include <iomanip>
#include <sstream>

std::string DateTime::getCurrentDateTime()
{
    std::time_t now = std::time(nullptr);
    std::tm local_time{};
    localtime_s(&local_time, &now);

    std::ostringstream oss;
    oss << std::put_time(&local_time, "%c");
    return oss.str();
}
