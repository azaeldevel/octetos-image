
#ifndef OCTETOS_CORE_BMP_HH
#define OCTETOS_CORE_BMP_HH


#include <filesystem>
#include <octetos/core/Exception.hh>

namespace oct::image
{

struct RGB
{
	unsigned char red;
	unsigned char gree;
	unsigned char blue;
};

class BMP
{
public:
	struct alignas(0) Header
	{
		char signature[2];
		unsigned int size;
		unsigned short reserved1;
		unsigned short reserved2;
		unsigned int offset;

		//Header();
	};
	enum Compression
	{
		BI_RGB,
		BI_RLE8,
		BI_RLE4
	};
	struct HeaderInfo
	{
		unsigned int size;
		unsigned int width;
		unsigned int height;
		unsigned short planes;
		unsigned short bits_pixel;
		Compression compression;
		unsigned int image_size;
		unsigned int x_pixel_m;
		unsigned int y_pixel_m;
		unsigned int colors_used;
		unsigned int important_colors;
		
		//HeaderInfo();
	};
	struct alignas(0) RGB 
	{
		unsigned char alpha;
		unsigned char red;
		unsigned char gree;
		unsigned char blue;
	};

public:
	BMP(const std::filesystem::path& file);
	~BMP();
	const Header& get_header()const;
	const HeaderInfo& get_header_info()const;
	unsigned int get_row_size()const;
	unsigned int get_nums_colors()const;

	void load(const std::filesystem::path& file);

private:
	Header header;
	HeaderInfo info;
	unsigned int num_colors;
	BMP::RGB* color_table;
	unsigned int row_size;
};

}

#endif