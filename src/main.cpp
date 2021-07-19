#include "RKV2.h"
#include <stdio.h>

int main(int argc, char* argv[])
{
	u32 checksum = test_func();
	printf("0x%.8X\n", checksum);
	return 0;
}
