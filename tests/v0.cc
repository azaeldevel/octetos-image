
#include <CUnit/Basic.h>
#include "config.h"

#include <iostream>
#include <BMP.hh>

int init(void)
{
	return 0;
}

int clean(void)
{
	return 0;
}

void testDevelop()
{
	oct::image::BMP bmp1("../../tests/image-1.bmp");
	
	//if(bmp1.get_file().is_open()) CU_ASSERT(true)
	//else CU_ASSERT(false);
	
	if(bmp1.get_header().signature[0] == 'B') CU_ASSERT(true)
	else CU_ASSERT(false);
	if(bmp1.get_header().signature[1] == 'M') CU_ASSERT(true)
	else CU_ASSERT(false);	
	if(bmp1.get_header().size > 0) CU_ASSERT(true)
	else CU_ASSERT(false);
	if(bmp1.get_header().reserved1 == 0) CU_ASSERT(true)
	else CU_ASSERT(false);
	if(bmp1.get_header().reserved2 == 138) CU_ASSERT(true)
	else CU_ASSERT(false);
	//std::cout << "bmp1.get_header().reserved2 : " << bmp1.get_header().reserved2 << "\n";
	if(bmp1.get_header().offset == 0) CU_ASSERT(true)
	else CU_ASSERT(false);
	//std::cout << "bmp1.get_header().offset : " << bmp1.get_header().offset << "\n";
	
	CU_ASSERT((void*)&bmp1.get_header().signature == (void*)&bmp1.get_header());
	if(sizeof(bmp1.get_header().signature) == 2) CU_ASSERT(true)
	else CU_ASSERT(false);
	if(sizeof(bmp1.get_header().size) == 4) CU_ASSERT(true)
	else CU_ASSERT(false);
	if(sizeof(bmp1.get_header().reserved1) == 2) CU_ASSERT(true)
	else CU_ASSERT(false);
	if(sizeof(bmp1.get_header().reserved2) == 2) CU_ASSERT(true)
	else CU_ASSERT(false);
	if(sizeof(bmp1.get_header().offset) == 4) CU_ASSERT(true)
	else CU_ASSERT(false);
	if(sizeof(oct::image::BMP::Header) == 16) CU_ASSERT(true)//alineamineto de memoria
	else CU_ASSERT(false);
	//std::cout << "sizeof(oct::image::BMP::Header) : " << sizeof(oct::image::BMP::Header) << "\n";
	
	CU_ASSERT(bmp1.get_header_info().size == 124);
	CU_ASSERT(sizeof(bmp1.get_header_info().size) == 4);
	//std::cout << "bmp1.get_header_info().size : " << bmp1.get_header_info().size << "\n";
	CU_ASSERT(bmp1.get_header_info().width == 1024);
	CU_ASSERT(sizeof(bmp1.get_header_info().width) == 4);
	//std::cout << "bmp1.get_header_info().width : " << bmp1.get_header_info().width << "\n";
	CU_ASSERT(bmp1.get_header_info().height == 768);
	CU_ASSERT(sizeof(bmp1.get_header_info().height) == 4);
	//std::cout << "bmp1.get_header_info().height : " << bmp1.get_header_info().height << "\n";
	CU_ASSERT(bmp1.get_header_info().planes == 1);
	CU_ASSERT(sizeof(bmp1.get_header_info().planes) == 2);
	//std::cout << "bmp1.get_header_info().planes : " << bmp1.get_header_info().planes << "\n";
	CU_ASSERT(bmp1.get_header_info().bits_pixel == 32);
	CU_ASSERT(sizeof(bmp1.get_header_info().bits_pixel) == 2);
	//std::cout << "bmp1.get_header_info().bits_pixel : " << bmp1.get_header_info().bits_pixel << "\n";
}

int main(int argc, char *argv[])
{	
	/* initialize the CUnit test registry */
	if (CUE_SUCCESS != CU_initialize_registry()) return CU_get_error();

	CU_pSuite pSuite = CU_add_suite("Testing for octetos-image", init, clean);
	if (NULL == pSuite) 
	{
		CU_cleanup_registry();
		return CU_get_error();
	}
	
	if ((NULL == CU_add_test(pSuite, "developing", testDevelop)))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}
	
	/* Run all tests using the CUnit Basic interface */
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_cleanup_registry();
	return CU_get_error();	
}
