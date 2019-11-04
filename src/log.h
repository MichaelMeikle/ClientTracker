#pragma once
#include <ctime>
#include <string>
#include "teamspeak.h"

#define __FILENAME__ (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__)
#define GLOBAL_DEFAULT LogLevel_INFO

class Log {
public:
	/* Default Constructor with logLevel initialized to Info level */
	Log();
	/* Constructor to be used in main file */
	Log(int log_level, std::string file_name);
	/* Constructor to be used in all other files */
	Log(std::string file_name);
	~Log();

	/* Send a devel msg */
	void Devel(int line, std::string msg);
	/* Send a logged info msg */
	void Info(int line, std::string msg);
	/* Send a logged debug msg */
	void Debug(int line, std::string msg);
	/* Send a logged warning msg */
	void Warning(int line, std::string msg);
	/* Send a logged error msg */
	void Error(int line, std::string msg);
	/* Sends a logged critical msg (Indicates something that would terminate plugin completely)*/
	void Critical(int line, std::string msg);

	/*** Setters ***/
	void log_level(int level) { log_level_ = level; };

	/*** Getters ***/
	int log_level() { return log_level_; };

private:
	static int log_level_; //Log level state, should be set to value matching default TS Log Levels as defined in logtypes.h
	std::string file_name_; 
};

/* TS3 Log Level Definitions
LogLevel_CRITICAL = 0, //these messages stop the program
LogLevel_ERROR,        //everything that is really bad, but not so bad we need to shut down
LogLevel_WARNING,      //everything that *might* be bad
LogLevel_DEBUG,        //output that might help find a problem
LogLevel_INFO,         //informational output, like "starting database version x.y.z"
LogLevel_DEVEL         //developer only output (will not be displayed in release mode)
*/