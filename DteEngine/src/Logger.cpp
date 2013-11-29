#include <Dte/Logger.hpp>

#include <chrono>
#include <iostream>

namespace dte
{
    Logger::Logger() = default;
    Logger::~Logger() = default;
    Logger& Logger::GetInstance()
    {
        static Logger instance;

        return instance;
    }

    void Logger::Open(const std::string& standard, const std::string& error)
    {
        m_output_file.open(standard);
        m_error_file.open(error);
    }

    void Logger::LogTimeStandard()
    {
        std::cout << "[" << GetStringFromTime_T(GetTime()) << "] ";
        if(m_output_file.is_open())
            m_output_file << "[" << GetStringFromTime_T(GetTime()) << "] ";
    }
    void Logger::LogTimeError()
    {
        std::cerr << "[" << GetStringFromTime_T(GetTime()) << "] ";
        if(m_error_file.is_open())
            m_error_file << "[" << GetStringFromTime_T(GetTime()) << "] ";
    }

    void Logger::WriteStandard(const std::string& data)
    {
        std::cout << data;
        if(m_output_file.is_open());
            m_output_file << data;
    }
    void Logger::WriteError(const std::string& data)
    {
        std::cerr << data;
        if(m_error_file.is_open())
            m_error_file << data;
    }
    void Logger::WriteStandardLn(const std::string& data)
    {
        std::cout << data << std::endl;
        if(m_output_file.is_open());
            m_output_file << data << std::endl;
    }
    void Logger::WriteErrorLn(const std::string& data)
    {
        std::cerr << data << std::endl;
        if(m_error_file.is_open())
            m_error_file << data << std::endl;
    }


    time_t GetTime()
    {
        std::chrono::system_clock clock;

        return clock.to_time_t(clock.now());
    }
    std::string GetStringFromTime_T(time_t time_to_convert)
    {
        std::string temp;
        temp = ctime(&time_to_convert);
        temp = temp.substr(0, temp.length()-1);

        return temp;
    }
}
