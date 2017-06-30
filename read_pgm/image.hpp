#include <vector>
#include <string>
#include <cinttypes>

class Pixel
{
    public:
        Pixel() {}
        ~Pixel() {}

        uint8_t val;
};

class Image
{
    public:
        Image();
        ~Image();

        bool read_image_from_file(const std::string &filename);
        bool save_image_to_file(const std::string &filename);
        Pixel get_pixel_value(uint32_t row, uint32_t col);
        bool set_pixel_value(uint32_t row, uint32_t col, Pixel val);
        size_t get_num_rows();
        size_t get_num_cols();

    private:
        std::vector<Pixel>  raw_img;
        size_t              num_rows;
        size_t              num_cols;
        size_t              max_pixel_value;
};
