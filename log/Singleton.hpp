#ifndef COMMON_SINGLETON_HPP
#define COMMON_SINGLETON_HPP

#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/thread/once.hpp>

namespace common {

template<typename T>
class Singleton
{
public:
    static void init()
    {
        instance_.reset(new T);
    }

    static T& get_mutable_instance()
    {
        return *get_instance();
    }

    static const T& get_const_instance()
    {
        return *get_instance();
    }

private:
    static T* get_instance()
    {
        boost::call_once(once_, boost::bind(&init));
        return instance_.get();
    }

private:
    static boost::shared_ptr<T> instance_;
    static boost::once_flag once_;
};

template<typename T> boost::shared_ptr<T> Singleton<T>::instance_;
template<typename T> boost::once_flag Singleton<T>::once_ = BOOST_ONCE_INIT;

} // namespace common {

#endif  // COMMON_SINGLETON_HPP
