# include "Account.hpp"

int Account:: _nbAccounts = 0;
int Account:: _totalAmount = 0;
int Account:: _totalNbDeposits = 0;
int Account:: _totalNbWithdrawals = 0;


Account :: Account( void ) {

}


Account :: Account(int initial_deposit) {
	this->_accountIndex = this->_nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;

	this->_nbAccounts++;
	this->_totalAmount += initial_deposit;

}

std::string formatNumberWithLeadingZero(int number, int width) {
	std::ostringstream oss;
	oss.width(width);
	oss.fill('0');
	oss << number;
	return oss.str();
}

void Account :: _displayTimestamp( void ) {


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

	std:: cout << "[" << formattedTime << "] ";
}

Account :: ~Account( void ) {

}
