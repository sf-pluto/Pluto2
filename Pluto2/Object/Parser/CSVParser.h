#ifndef INCLUDED_OBJECT_PARSER_PARSER_H
#define INCLUDED_OBJECT_PARSER_PARSER_H

#include <string>
#include <vector>
#include "ParserBase.h"

class CSVParser : public ParserBase{
public:
	CSVParser();
	~CSVParser();
	
	int Parse( const std::string& str );
};

#endif //#ifndef INCLUDED_OBJECT_PARSER_PARSER_H