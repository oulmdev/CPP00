#include <iostream>
#include <ctime>
#include <sstream>


std::string formatNumberWithLeadingZero(int number, int width) {
    std::ostringstream oss;
    oss.width(width);
    oss.fill('0');
    oss << number;
    return oss.str();
}

int main() {

	time_t currentTime;
	time(&currentTime);


	struct tm* timeinfo = localtime(&currentTime);

	int year = timeinfo->tm_year + 1900;
	int month = timeinfo->tm_mon + 1;
	int day = timeinfo->tm_mday;
	int hour = timeinfo->tm_hour;
	int minute = timeinfo->tm_min;
	int second = timeinfo->tm_sec;

	std::string formattedTime =
	formatNumberWithLeadingZero(year, 4) +
	formatNumberWithLeadingZero(month, 2) +
	formatNumberWithLeadingZero(day, 2) + "_" +
	formatNumberWithLeadingZero(hour, 2) +
	formatNumberWithLeadingZero(minute, 2) +
	formatNumberWithLeadingZero(second, 2);

	return 0;
}
	