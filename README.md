# Some useful OpenVMS migration utilities

## convert_vms_vl

This will convert a OpenVMS Variable Length (VL) format file into
a stream of bytes with additional line endings if required.

command line option with convert_vms_vl are:
*   **-cl**   (default) add linux style line ending (\n)
*   **-cw**   add windows style line endings (\r\n)
*   **-cm**   add (old?) mac style line ending (\r)
*   **-n**    do not add any \n, \r etc. characters to end of records, for when a VL file contains binary rather than ASCII data

e.g. to generate windows style line endings use:

    ./convert_vms_vl -cw orig_file > new_file

A Windows (MinGW) compiled binary is provided in  **convert_vms_vl_win32.exe**

For linux and Mac you will need to compile the source code

    g++ -o convert_vms_vl convert_vms_vl.cxx

## convert_vms_vl.sh

script to simplify running **convert_vms_vl** on a number of files

    sh convert_vms_vl.sh -cw *.for

will create a subdirectory called "converted" for output files and then 
process all files matching \*.for in the current directory using
**convert_vms_vl** and the supplied options
