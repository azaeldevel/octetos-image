
#include <iostream>
#include <fstream>
#include <cmath>

#include "BMP.hh"


namespace oct::image
{
	BMP::BMP(const std::filesystem::path& f) : color_table(NULL)
	{		
		load(f);
	}
	BMP::~BMP()
	{
		delete[] color_table;
	}
	
	

	const BMP::Header& BMP::get_header()const
	{
		return header;
	}
	const BMP::HeaderInfo& BMP::get_header_info()const
	{
		return info;
	}
	unsigned int BMP::get_row_size()const
	{
		return row_size;
	}
	unsigned int BMP::get_nums_colors()const
	{
		return num_colors;
	}
	void BMP::load(const std::filesystem::path& f)
	{
		std::ifstream file;
		file.open(f,std::ios::binary | std::ios::in);
		if(not file.is_open()) throw oct::core::Exception("No se ha abierto el archivo",__LINE__,__FILE__);
		
		//
		file.read((char*)&header,14);
		file.read((char*)&info,40);
		if(info.bits_pixel < 8) file.read((char*)&num_colors,4);
		else num_colors = info.image_size;
		color_table = new BMP::RGB[num_colors];
		file.read((char*)color_table,num_colors * sizeof(BMP::RGB));
		
		//
		file.close();
		row_size = (info.width * info.bits_pixel)/sizeof(BMP::RGB);
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