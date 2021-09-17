
#include <iostream>

#include "BMP.hh"


namespace oct::image
{
	BMP::BMP(const std::string& f)
	{		
		load(f);
	}
	BMP::~BMP()
	{
	}
	
	
	const std::ifstream& BMP::get_file()const
	{
		return file;
	}
	const BMP::Header& BMP::get_header()const
	{
		return header;
	}
	void BMP::load(const std::string& f)
	{
		file.open(f,std::ios::binary | std::ios::in);
		if(not file.is_open()) throw oct::core::Exception("No se ha abierto el archivo",__LINE__,__FILE__);
		
		//header
		file >> header.signature[0];
		file >> header.signature[1];
		file >> header.size;
		file >> header.reserved1;	
		file >> header.reserved2;	
		file >> header.offset;	
		
		//
		
	}
	
	
	
	
	BMP::Header::Header()
	{
		signature[0] = 0;
		signature[1] = 0;
		size = 0;
		reserved1 = 0;
		reserved2 = 0;
		offset = 0;
	}
}