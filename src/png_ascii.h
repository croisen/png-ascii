#ifndef PNG_ASCII_H
#define PNG_ASCII_H

#include <stdbool.h>
#include <stdint.h>

#ifdef STB_IMAGE_IMPLEMENTATION
#undef STB_IMAGE_IMPLEMENTATION
#endif /* STB_IMAGE_IMPLEMENTATION */
#include "../3rd_party/stb/stb_image.h"
#pragma pack(1)

struct channel_4
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
};

struct channel_3
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
};

struct channel_2
{
    uint8_t g;
    uint8_t a;
};

struct channel_1
{
    uint8_t g;
};

void png_ascii(int width, int height, int channels, stbi_uc *img, bool colored);
void print_ch3(struct channel_3, bool colored);
struct channel_3 channel_4_to_3(struct channel_4);
struct channel_3 channel_2_to_3(struct channel_2);
struct channel_3 channel_1_to_3(struct channel_1);

#endif /* PNG_ASCII_H */
