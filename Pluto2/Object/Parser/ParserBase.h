#ifndef INCLUDED_OBJECT_PARSER_PARSERBASE_H
#define INCLUDED_OBJECT_PARSER_PARSERBASE_H

#include <boost/utility.hpp>

class ParserBase : boost::noncopyable{
public:
	ParserBase(){}
	virtual ~ParserBase(){}
};

#endif //#ifndef INCLUDED_OBJECT_PARSER_PARSERBASE_H