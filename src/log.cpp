//Local Headers
#include "Log.h"

Log::Log() {
	log_level_ = LogLevel_INFO;
	file_name_ = "Unknown";
}
Log::Log(int log_level, std::string file_name)
{
	log_level_ = log_level;
	file_name_ = file_name;
}
Log::Log(std::string file_name)
{
	file_name_ = file_name;
}
Log::~Log() {
}

void Log::Devel(int line, std::string msg)
{
	if (log_level_ > LogLevel_DEVEL)
		return;
	msg.append(" | " + file_name_ + " Line Number: " + std::to_string(line));
	ts3()->logMessage(msg.c_str(), LogLevel_DEVEL, plugin_name(), 0);
}

void Log::Info(int line, std::string msg)
{
	if (log_level_ > LogLevel_INFO)
		return;
	msg.append(" | " + file_name_ + " Line Number: " + std::to_string(line));
	ts3()->logMessage(msg.c_str(), LogLevel_INFO, plugin_name(), 0);
}

void Log::Debug(int line, std::string msg)
{

	if (log_level_ > LogLevel_DEBUG)
		return;
	msg.append(" | " + file_name_ + " Line Number: " + std::to_string(line));
	ts3()->logMessage(msg.c_str(), LogLevel_DEBUG, plugin_name(), 0);
}

void Log::Warning(int line, std::string msg)
{
	if (log_level_ > LogLevel_WARNING)
		return;
	msg.append(" | " + file_name_ + " Line Number: " + std::to_string(line));
	ts3()->logMessage(msg.c_str(), LogLevel_WARNING, plugin_name(), 0);
}

void Log::Error(int line, std::string msg)
{
	if(log_level_ > LogLevel_WARNING)
		return;
	msg.append(" | " + file_name_ + " Line Number: " + std::to_string(line));
	ts3()->logMessage(msg.c_str(), LogLevel_WARNING, plugin_name(), 0);
}

void Log::Critical(int line, std::string msg)
{
	if (log_level_ > LogLevel_CRITICAL)
		return;
	msg.append(" | " + file_name_ + " Line Number: " + std::to_string(line));
	ts3()->logMessage(msg.c_str(), LogLevel_CRITICAL, plugin_name(), 0);
}