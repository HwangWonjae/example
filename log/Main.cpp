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
		LOGV << "A 한글 message!";
	    LOGD << "A 한글 message!";
		LOGI << "A 한글 message!";
		LOGW << "A 한글 message!";
		LOGE << "A 한글 message!";
		LOGF << "A 한글 message!";
	}

    return 0;
}
