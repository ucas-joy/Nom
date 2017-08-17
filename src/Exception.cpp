#include "Exception.h"
#include <stdlib.h>
#include <execinfo.h>

Exception::Exception(const char *s)
    :message_(s)
{
    fillStackTrace();
}

Exception::Exception(const std::string &s)
    :message_(s)
{
    fillStackTrace();
}

Exception::~Exception() throw()
{
}

const char *Exception::what() const throw()
{
    return message_.c_str();
}
 
void Exception::fillStackTrace()
{
    const int len = 200;
    void* buffer[len];
    //获取栈的调用痕迹 
    int nptrs = ::backtrace(buffer, len);
	 //backtrace函数用于获取当前线程的调用堆栈，获取的消息将会保存放在buffer中
  //len用来指定buffer中可以保存多少个void*元素
  //函数返回的nptrs是实际获取的指针个数，最多不超过len个
    //翻译成可读的字符串
    char** strings = ::backtrace_symbols(buffer, nptrs);
	//backtrace_symbols 将从backtrace函数获取的信息转换为一个字符串数组。
  //参数buffer应该是从backtrace函数获取的指针数组，nptrs是数组中的元素个数
 //返回值strings是一个指向字符串数组的指针，它的大小同buffer
    if (strings)
    {
        for (int i = 0; i < nptrs; ++i)
        {
            // TODO demangle funcion name with abi::__cxa_demangle
            stack_.append(strings[i]);
            stack_.push_back('\n');
        }
        free(strings);
    } 
}

const char *Exception::stackTrace() const throw()
{
    return stack_.c_str();// 返回与stack_相同的字符串信息
}












