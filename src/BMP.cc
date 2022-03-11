
#include <iostream>


#include <fstream>


#include "BMP.hh"


namespace oct::image
{
	BMP::BMP(const std::filesystem::path& f)
	{		
		load(f);
	}
	BMP::~BMP()
	{
	}
	
	

	const BMP::Header& BMP::get_header()const
	{
		return header;
	}
	const BMP::HeaderInfo& BMP::get_header_info()const
	{
		return info;
	}
	void BMP::load(const std::filesystem::path& f)
	{
		std::ifstream file;
		file.open(f,std::ios::binary | std::ios::in);
		if(not file.is_open()) throw oct::core::Exception("No se ha abierto el archivo",__LINE__,__FILE__);
		
		//
		file.read((char*)&header,14);
		file.read((char*)&info,16);
		
		//
		file.close();
	}
	
	
	
	
	/*
	BMP::Header::Header()
	{
		signature[0] = 0;
		signature[1] = 0;
		size = 0;
		reserved1 = 0;
		reserved2 = 0;
		offset = 0;
	}
	BMP::HeaderInfo::HeaderInfo() : size(0), width(0), height(0)
	{
	}
	*/
}