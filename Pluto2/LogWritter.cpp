#include "LogWritter.h"
#include "DxLib.h"
#include <boost/format.hpp>


LogWritter::LogWritter() : mOutputName( "log.txt" ){
}

void LogWritter::open(){
	mStream.open( mOutputName , std::ios::out | std::ios::app );
}

void LogWritter::close(){
	mStream.close();
}

void LogWritter::writeInfo(){
	boost::filesystem::ofstream f( mOutputName );
	f << "********************************" << endl;
	f << "*   Pluto        Log           *" << endl;
	f << "********************************" << endl;
	f << "Started" << getTimeStr() << endl;
}

void LogWritter::writeWithTime(const std::string& str){
	mStream << str << getTimeStr() << endl;
}

void LogWritter::write(const std::string& str){
	mStream << str;
}

void LogWritter::writeln(const std::string& str){
	mStream << str << endl;
}

std::string LogWritter::getTimeStr(){
	DATEDATA t;
	GetDateTime( &t );
	boost::format d( " @%1%-%2$02d-%3$02d %4$02d:%5$02d:%6$02d" );
	d % t.Year % t.Mon %  t.Day % t.Hour % t.Min % t.Sec;
	return d.str();
}