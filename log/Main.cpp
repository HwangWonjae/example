#include <windows.h>
#include <iostream>
#include <cstdlib>
#include <string>

#include "Logger.hpp"

int main(int argc, char *argv[])
{
	::_putenv_s("LOG_PATH", "D:\\");
	::_putenv_s("LOG_LEVEL", "DEBUG");
	::_putenv_s("LOG_MAXFILESIZE", "1000");
	::_putenv_s("LOG_MAXFILES", "2");

	common::Logger::get_const_instance();
	for (int i = 0; i < 20; i++) {
		LOGV << "A message!";
	    LOGD << "A message!";
		LOGI << "A message!";
		LOGW << "A message!";
		LOGE << "A message!";
		LOGF << "A message!";
	}

    return 0;
}
