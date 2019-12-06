#if  _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif //  _MSC_VER

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <numeric>
#include <cmath>
#include <sstream>
#include <thread>
#include <chrono>
#include <ctime>
#include <mutex>

using namespace std;

int GetRandom(int max)
{
	srand(time_t(NULL));
	return rand() % max;
}

void ExecuteThread(int id)
{
	//get current time
	auto nowTime = std::chrono::system_clock::now();

	//convert to a time we can output
	std::time_t sleepTime = std::chrono::system_clock::to_time_t(nowTime);

	//convert to current time zone
	tm myLocalTime = *localtime(&sleepTime);

	//print full time information
	std::cout << "Thread-" << id << " Sleep Time: " << std::ctime(&sleepTime) << "\n";

	//get separate pieces
	std::cout << "Month :" << myLocalTime.tm_mon << "\n";
	std::cout << "Day :" << myLocalTime.tm_mday << "\n";
	std::cout << "Year :" << myLocalTime.tm_year + 1900 << "\n";
	std::cout << "Hour :" << myLocalTime.tm_hour << "\n";
	std::cout << "Minutes :" << myLocalTime.tm_min << "\n";
	std::cout << "Seconds :" << myLocalTime.tm_sec << "\n";

	//put the thread to sleep for up to 3 seconds
	std::this_thread::sleep_for(std::chrono::seconds(GetRandom(3)));
	nowTime = std::chrono::system_clock::now();
	sleepTime = std::chrono::system_clock::to_time_t(nowTime);
	std::cout << "Thread-" << id << " Awake Time :" << std::ctime(&sleepTime) << "\n";
}


int main()
{
	//std::thread th1(ExecuteThread, 1);
	//th1.join();
	//std::thread th2(ExecuteThread, 2);
	//th2.join();

	ExecuteThread(1);
	ExecuteThread(2);

	return 0;
}