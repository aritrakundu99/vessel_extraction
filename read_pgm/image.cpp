#include <image.hpp>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>

Image::Image()
{}

Image::~Image()
{}

bool Image::read_image_from_file(const std::string &filename)
{
    std::ifstream im_file(filename.c_str(),
                          std::ios_base::in);
    std::string line;

    raw_img.clear();
    num_rows = 0;
    num_cols = 0;

    if (im_file.is_open())
    {
        if (std::getline(im_file, line))
        {
            if ((line.compare("P2") != 0) && (line.compare("P5") != 0))
            {
                std::cerr << "Version error - could not read pgm file." << std::endl;
                return false;
            }
        }

        if (std::getline(im_file, line))
        {
            std::stringstream ss;
            ss << line;
            ss >> num_cols >> num_rows;
        }

        if (std::getline(im_file, line))
        {
            std::stringstream ss;
            ss << line;
            ss >> max_pixel_value;
        }

        if (max_pixel_value > 255)
        {
            std::cerr << "Pixel value greater than 255 not supported. Could not read pgm file." << std::endl;
            return false;
        }

        char *img_buffer = new char[num_cols * num_rows];
        im_file.read(img_buffer, num_cols * num_rows);
        for (size_t row = 0; row < num_rows; ++row)
            for (size_t col = 0; col < num_cols; ++col)
            {
                Pixel pix;
                pix.val = img_buffer[row * num_cols + col];
                raw_img.push_back(pix);
            }

        delete img_buffer;
        im_file.close();
        return true;
    }
    else
    {
        std::cerr << "Unable to open pgm file." << std::endl;
        return false;
    }
}

bool Image::save_image_to_file(const std::string &filename)
{
    std::ofstream op_file(filename.c_str(),
                          std::ios_base::out | std::ios_base::binary);

    op_file << "P5\n" << num_cols << " " << num_rows << "\n" << max_pixel_value << "\n";

    for (size_t i = 0; i < raw_img.size(); ++i)
        op_file << raw_img[i].val;

    op_file.close();
}

Pixel Image::get_pixel_value(uint32_t row, uint32_t col)
{
    return raw_img[(row * num_cols) + col];
}

bool Image::set_pixel_value(uint32_t row, uint32_t col, Pixel val)
{
    if (((row * num_cols) + col) < raw_img.size())
        return false;

    raw_img[(row * num_cols) + col] = val;
    return true;
}

size_t Image::get_num_rows()
{
    return num_rows;
}

size_t Image::get_num_cols()
{
    return num_cols;
}
