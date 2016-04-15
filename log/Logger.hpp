#ifndef COMMON_LOGGER_HPP
#define COMMON_LOGGER_HPP

#include <windows.h>
#include <string>

#include <plog/Log.h>
#include <plog/Appenders/ColorConsoleAppender.h>
#include <plog/Formatters/FuncMessageFormatter.h>

#include "Singleton.hpp"

namespace plog
{
template<class Formatter> // Typically a formatter is passed as a template parameter.
class OutputDebugStringAppender : public IAppender // All appenders MUST inherit IAppender interface.
{
public:
    virtual void write(const Record& record) // This is a method from IAppender that MUST be implemented.
    {
        util::nstring str = Formatter::format(record); // Use the formatter to get a string from a record.
		OutputDebugString(str.c_str());
    }
};
}

namespace common {
class Logger : public Singleton<Logger> {
public:
    Logger()
    {
         // Create the 1st appender.
        static plog::ColorConsoleAppender<plog::FuncMessageFormatter> consoleAppender;
        plog::init(plog::debug, &consoleAppender);
        //plog::get()->setMaxSeverity(getLevel());

        // Create the 2nd appender.
        static plog::RollingFileAppender<plog::FuncMessageFormatter>
				//fileAppender("D:\\PlogTest.log", 2000, 2);
				fileAppender(getLogPath().c_str(), getMaxFileSize(), getMaxFiles());
        plog::get()->addAppender(&fileAppender);

		// Create the 3nd appender.
		static plog::OutputDebugStringAppender<plog::FuncMessageFormatter> OutputDebugStringAppender; // Create our custom appender. 
		plog::get()->addAppender(&OutputDebugStringAppender);
    }

private:
	std::string getProcessName()
	{
		char pathName[MAX_PATH];
		GetModuleFileNameA(NULL, pathName, MAX_PATH);

		char fileName[MAX_PATH];
		_splitpath_s(pathName, NULL, 0, NULL, 0, fileName, MAX_PATH, NULL, 0);

		return std::string(fileName);
	}

    std::string getLogPath()
    {
        std::stringstream ss;
		std::string path = getEnv("SYNCVIEW_LOG_PATH");
		if (!path.empty()) {
            ss << path << "/";
        }
        ss << getProcessName() << ".log";

        LOGD << "SYNCVIEW_LOG_PATH:" << ss.str();
        return ss.str();
    }

    plog::Severity getLevel()
    {
		const std::string level = getEnv("SYNCVIEW_LOG_LEVEL");
		LOGD_IF(!level.empty()) << "ENV.SYNCVIEW_LOG_LEVEL:" << level
                << ":" << plog::severityFromString(level.c_str());
        LOGW_IF(level.empty()) << "ENV.SYNCVIEW_LOG_LEVEL:" << "NULL";
		return level.empty() ? plog::debug : plog::severityFromString(level.c_str());
    }

    size_t getMaxFileSize()
    {
		const std::string size = getEnv("SYNCVIEW_LOG_MAXFILESIZE");
		LOGD_IF(!size.empty()) << "ENV.SYNCVIEW_LOG_MAXFILESIZE:" << size;
		LOGW_IF(size.empty()) << "ENV.SYNCVIEW_LOG_MAXFILESIZE:" << "NULL";
        return size.empty() ? 0 : std::atoi(size.c_str());
    }

    int getMaxFiles()
    {
		const std::string files = getEnv("SYNCVIEW_LOG_MAXFILES");
		LOGD_IF(!files.empty()) << "ENV.SYNCVIEW_LOG_MAXFILES:" << files;
		LOGW_IF(files.empty()) << "ENV.SYNCVIEW_LOG_MAXFILES:" << "NULL";
		return files.empty() ? 0 : std::atoi(files.c_str());
    }

	std::string getEnv(const std::string &name)
	{
		char value[MAX_PATH] = "";
		size_t envsize = 0;
		getenv_s(&envsize, value, MAX_PATH, name.c_str());
		return value;
	}
};
}	// namespace common {

#endif  COMMON_LOGGER_HPP
