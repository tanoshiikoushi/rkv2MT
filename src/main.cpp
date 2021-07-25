#include <stdio.h>
#include <fstream>
#include "RKV2.h"

int main(int argc, char* argv[])
{
    if (argc != 3) {
        printf("Invalid usage!\n");
        printf("Execute as: rkv2MT \"C:\\dir\\to\\file.rkv\" \"C:\\dir\\to\\output\\to\"\n");
        return 0;
    }

    std::string file_name(argv[1]);
    std::string out_path(argv[2]);

    std::fstream file_in;
    u64 file_size;

    file_in.open(file_name, std::ios_base::in | std::ios_base::binary);

    if (!file_in) {
        printf("Unable to open file");
        return 1;
    }

    file_in.seekg(0, std::ios_base::end);
    file_size = file_in.tellg();

    file_in.seekg(0, std::ios_base::beg);

    u8* in_data = new u8[file_size];

    file_in.read((char*)in_data, file_size);
    file_in.close();

    RKV2File* rkv = new RKV2File();
    if (rkv->load(in_data, file_size)) {
        if(rkv->extract((u8*)out_path.c_str())) {
            printf("success!\n");
        } else {
            printf("failure :(\n");
        }
    }

    delete in_data;
    delete rkv;

    return 0;
}
