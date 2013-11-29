#ifndef LOGGER_HPP_INCLUDED
#define LOGGER_HPP_INCLUDED

#include <ctime>
#include <fstream>
#include <string>

namespace dte
{
    class Logger
    {
        public:
            ~Logger();
            static Logger& GetInstance();

            void Open(const std::string& standard, const std::string& error);

            void LogTimeStandard();
            void LogTimeError();

            void WriteStandard(const std::string& data);
            void WriteError(const std::string& data);
            void WriteStandardLn(const std::string& data);
            void WriteErrorLn(const std::string& data);

        private:
            Logger();
            Logger(const Logger&);
            Logger& operator= (const Logger &);

            std::ofstream m_output_file;
            std::ofstream m_error_file;
    };

    time_t GetTime();
    std::string GetStringFromTime_T(time_t time_to_convert);
}

#endif // LOGGER_HPP_INCLUDED
