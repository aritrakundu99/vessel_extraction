#include <iostream>
#include <image.hpp>

int main(int argc, char *argv[])
{
    std::string img_filename = "C:\\Users\\Nandan\\Downloads\\baboon.pgm";
    Image img;

    img.read_image_from_file(img_filename);

    std::cout << "Size of rows : " << img.get_num_rows() << std::endl;
    std::cout << "Size of cols : " << img.get_num_cols() << std::endl;

    img.save_image_to_file("C:\\Users\\Nandan\\Desktop\\bab.pgm");

    return 0;
}
