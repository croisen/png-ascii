#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "png_ascii.h"

void png_ascii(int width, int height, int channels, stbi_uc *img, bool colored)
{
    struct channel_1 *ch1 = (void *)img;
    struct channel_2 *ch2 = (void *)img;
    struct channel_3 *ch3 = (void *)img;
    struct channel_4 *ch4 = (void *)img;

    int wincr = (width  > 80) ? width  / 80 : 1;
    int hincr = (height > 45) ? height / 45 : 1;
    for (int i = 0; i < height; i+= hincr)
    {
        for (int j = 0; j < width; j += wincr)
        {
            struct channel_3 _ch3;
            switch (channels)
            {
            case 1:
                _ch3 = channel_1_to_3(ch1[i * width + j]);
                break;
            case 2:
                _ch3 = channel_2_to_3(ch2[i * width + j]);
                break;
            case 3:
                _ch3 = ch3[i * width + j];
                break;
            case 4:
                _ch3 = channel_4_to_3(ch4[i * width + j]);
                break;
            default:
                continue;
            }

            print_ch3(_ch3, colored);
        }

        if (colored)
            printf("\033[0m\n");
        else
            putc('\n', stdout);
    }
}

void print_ch3(struct channel_3 ch, bool colored)
{
    char repr[] = " .\'`^\",:;Il!i><~+_-?][}{1)(|\\/tfjrxnuvczXYUJCLQ0OZmwqpdbk"
                  "hao*#MW&8%B@$";
    int len = strlen(repr);
    int ave = (ch.r + ch.g + ch.b) / 3;
    int idx = (ave * (len - 1)) / 255;

    if (colored)
        printf("\033[38;2;%d;%d;%dm%c", ch.r, ch.g, ch.b, repr[idx]);
    else
        putc(repr[idx], stdout);
}

struct channel_3 channel_4_to_3(struct channel_4 i)
{
    struct channel_3 ch = {
        .r = i.r,
        .g = i.g,
        .b = i.b,
    };

    return ch;
}

struct channel_3 channel_2_to_3(struct channel_2 i)
{
    struct channel_3 ch = {
        .r = i.g,
        .g = i.g,
        .b = i.g,
    };

    return ch;
}

struct channel_3 channel_1_to_3(struct channel_1 i)
{
    struct channel_3 ch = {
        .r = i.g,
        .g = i.g,
        .b = i.g,
    };

    return ch;
}
