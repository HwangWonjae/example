#include <windows.h>
#include <iostream>
#include <cstdlib>
#include <string>

#include "Logger.hpp"

int main(int argc, char *argv[])
{
	::_putenv_s("SYNCVIEW_LOG_PATH", "D:\\");
	::_putenv_s("SYNCVIEW_LOG_LEVEL", "DEBUG");
	::_putenv_s("SYNCVIEW_LOG_MAXFILESIZE", "1000");
	::_putenv_s("SYNCVIEW_LOG_MAXFILES", "2");

	common::Logger::get_const_instance();
	for (int i = 0; i < 20; i++) {
		LOGV << "A debug message!";
	    LOGD << "A debug message!";
		LOGI << "A debug message!";
		LOGW << "A debug message!";
		LOGE << "A debug message!";
		LOGF << "A debug message!";
	}

    return 0;
}
