
#ifndef OCTETOS_CORE_BMP_HH
#define OCTETOS_CORE_BMP_HH


#include <filesystem>
#include <octetos/core/Exception.hh>

namespace oct::image
{

class BMP
{
public:
	struct Header
	{
		char signature[2];
		unsigned int size;
		unsigned short reserved1;
		unsigned short reserved2;
		unsigned int offset;

		//Header();
	};
	struct HeaderInfo
	{
		unsigned int size;
		unsigned int width;
		unsigned int height;
		unsigned short planes;
		unsigned short bits_pixel;
		
		//HeaderInfo();
	};
public:
	BMP(const std::filesystem::path& file);
	~BMP();
	const Header& get_header()const;
	const HeaderInfo& get_header_info()const;

	void load(const std::filesystem::path& file);

private:
	Header header;
	HeaderInfo info;
};

}

#endif