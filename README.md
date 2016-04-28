Some useful VMS migration utilities
===================================

convert_vms_vl
--------------

This will convert a VMS Variable Length (VL) format file into
a stream of bytes with additional line endings if required.

    g++ -o convert_vms_vl convert_vms_vl.cxx
    ./convert_vms_vl orig_file > new_file

command line option with convert_vms_vl are:
   -cl   (default) add linux style line ending (\n)
   -cw   add windows style line endings (\r\n)
   -cm   add (old?) mac style line ending (\r)
   -n    do not add any \n, \r etc characters to end of record, for when a VL
         file contains binary rather than ASCII data

e.g. for windows line ending use

    ./convert_vms_vl -cw orig_file > new_file

