Some useful VMS migration utilities

convert_vms_vl

This will convert a VMS Variable Length (VL) format file into
a stream of bytes. It assumes you want a linefeed at the end
of each record (i.e. an ASCII VL file)

    g++ -o convert_vms_vl convert_vms_vl.cxx
    ./convert_vms_vl orig_file > new_file

