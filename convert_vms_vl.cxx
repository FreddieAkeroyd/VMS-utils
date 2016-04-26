///
/// Convert VMS VL format file into UNIX format
/// @author Freddie Akeroyd, STFC ISIS Facility
///

#include <cstdio>
#include <iostream>
#include <fstream>

// convert 16 bit length field of VMS variable length(VL) to \n
int main(int argc, char* argv[])
{
    std::fstream f;
    const char* filein = argv[1];
    if (argc < 2 || filein == NULL)
    {
        std::cerr << "No filename given" << std::endl;
        return -1;
    }
    f.open(argv[1], std::ios::in | std::ios::binary);
    if (!f.good())
    {
        std::cerr << "File open error for \""  << filein << "\"" << std::endl;
        return -1;
    }
    f.seekg (0, f.end);
    int length = f.tellg();
    if (length % 2 != 0)
    {
        std::cerr << "File length not multiple of 2 bytes for file \"" << filein << "\"" << std::endl;
        return -1;
    }
    f.seekg (0, f.beg);
    char * buffer = new char [length+2];
    f.read (buffer,length);
    buffer[length] = '\0';
    buffer[length+1] = '\0';
    unsigned short* sbuffer = (unsigned short*)buffer;
    int slength = length / 2;
    int l, i;
    for(i = 0; i < slength; )
    {
        l = sbuffer[i]; // record length in bytes
        sbuffer[i] = '\0' + 256 * '\n';
        i += 1; // length field
        i += (l + 1) / 2; // record data, but padded to even byte number
        if (l % 2 != 0)
        {
            buffer[2*i-1] = '\0'; // overwrite padding byte, probably already a NULL
        }
    }
    if (i != slength)
    {
        std::cerr << "record length mismatch - maybe not OpenVMS VL file format? for file \"" << filein << "\"" << std::endl;
        return -1;
    }
    for(i = 2; i < length; ++i)
    {
        switch(buffer[i])
        {
            case '\0':
		break;

	    default:
		std::cout << buffer[i];
		break;
	}
    }
    std::cout << "\n";
    return 0;
}
