#include <windows.h>
#include <iostream>
#include <cstdlib>
#include <string>

#include <boost/thread.hpp>

#include "Logger.hpp"

void run()
{
    common::Logger::get_const_instance();

    for (int i = 0; i < 20; i++) {
        LOGV << boost::this_thread::get_id() <<": A 한글 message!";
        LOGD << boost::this_thread::get_id() <<": A 한글 message!";
        LOGI << boost::this_thread::get_id() <<": A 한글 message!";
        LOGW << boost::this_thread::get_id() <<": A 한글 message!";
        LOGE << boost::this_thread::get_id() <<": A 한글 message!";
        LOGF << boost::this_thread::get_id() <<": A 한글 message!";
    }
}

int main(int argc, char *argv[])
{
    ::_putenv_s("LOG_PATH", "D:\\");
    ::_putenv_s("LOG_LEVEL", "DEBUG");
    ::_putenv_s("LOG_MAXFILESIZE", "10000");
    ::_putenv_s("LOG_MAXFILES", "10");

    boost::thread_group threads;
    for (int i = 0; i < 100; ++i) {
        threads.create_thread(boost::bind(&run));
    }
    threads.join_all();

    return 0;
}
