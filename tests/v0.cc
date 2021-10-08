
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
	oct::image::BMP bmp1("tests/image-1.bmp");
	
	if(bmp1.get_file().is_open()) CU_ASSERT(true)
	else CU_ASSERT(false);
	
	if(bmp1.get_header().signature[0] == 'B') CU_ASSERT(true)
	else CU_ASSERT(false);
	if(bmp1.get_header().signature[1] == 'M') CU_ASSERT(true)
	else CU_ASSERT(false);	
	if(bmp1.get_header().size > 0) CU_ASSERT(true)
	else CU_ASSERT(false);
	if(bmp1.get_header().reserved1 == 0) CU_ASSERT(true)
	else CU_ASSERT(false);
	/*if(bmp1.get_header().reserved2 == 0) CU_ASSERT(true)
	else CU_ASSERT(false);*/
	/*if(bmp1.get_header().offset > 0) CU_ASSERT(true)
	else CU_ASSERT(false);*/
	
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
	/*if(sizeof(bmp1.get_header()) == 14) CU_ASSERT(true)
	else CU_ASSERT(false);*/
	
	//std::cout << "sizeof(bmp1.get_header()) : " << sizeof(bmp1.get_header()) << "\n";
	//std::cout << "bmp1.get_header().size : " << bmp1.get_header().size << "\n";
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
