#include <log4cxx/logger.h>
#include <log4cxx/propertyconfigurator.h>

using namespace log4cxx;
using namespace log4cxx::helpers;

// Define static logger variable
LoggerPtr loggerMyMain(Logger::getLogger( ""));
LoggerPtr loggerFunctionA(Logger::getLogger( ""));

void functionA()
{
    LOG4CXX_INFO(loggerFunctionA, "Executing functionA.");
}

int main()
{
    int value = 5;

    // Load properties style configuration file using PropertyConfigurator
    PropertyConfigurator::configure("Log4cxxConfig.cfg");
for(int j=1;j<15;j++){
    LOG4CXX_TRACE(loggerMyMain, "this is a debug message for detailed code discovery. Value=" << value);
    LOG4CXX_DEBUG(loggerMyMain, "this is a debug message.");
    LOG4CXX_INFO (loggerMyMain, "this is a info message, ignore. Value=" << value);
    LOG4CXX_WARN (loggerMyMain, "this is a warn message, not too bad.");
    LOG4CXX_ERROR(loggerMyMain, "this is a error message, something serious is happening.");
    LOG4CXX_FATAL(loggerMyMain, "this is a fatal message!!!");

    functionA();
}
    return 0;
}


// g++ file.cpp -I/usr/include -L/usr/local/lib/ -lapr-1 -laprutil-1 -o tmp
// g++ file.cpp -I/usr/include /usr/local/lib/liblog4cxx.a -lapr-1 -laprutil-1 -o tmp **************
