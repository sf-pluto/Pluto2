#ifndef INCLUDED_LOGWRITTER_H
#define INCLUDED_LOGWRITTER_H

#include "Class/Singleton.h"
#include <string>
#include <boost/filesystem/fstream.hpp>

using namespace std;

class LogWritter : public Singleton< LogWritter >{
public:
	LogWritter();

	void open();
	void close();
	void writeInfo();
	void writeWithTime( const string& str );
	void write( const string& str );
	void writeln( const string& str );
private:
	string mOutputName;
	boost::filesystem::ofstream mStream;

	string getTimeStr();
};

#endif //#ifndef INCLUDED_LOGWRITTER_H