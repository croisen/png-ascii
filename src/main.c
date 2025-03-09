#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define STB_IMAGE_IMPLEMENTATION
#include "../3rd_party/stb/stb_image.h"

#include "png_ascii.h"

int main(int argc, char **argv)
{
    int width, height, channels;
    bool error = argc == 1
        || !strcasecmp(argv[1], "-h")
        || !strcasecmp(argv[1], "--help");
    if (error)
    {
        fprintf(stderr, "Usage: %s <image.png>\n", argv[0]);
        fprintf(stderr, "       %s -c <image.png>\n", argv[0]);
        fprintf(stderr, "       %s -h\n", argv[0]);
        fprintf(stderr, "       %s --help\n", argv[0]);
        return EXIT_SUCCESS;
    }

    char *file   = (argc > 2) ? argv[2] : argv[1];
    bool colored = (argc > 2);

    stbi_uc *img = stbi_load(file, &width, &height, &channels, 0);
    if (!img)
    {
        fprintf(stderr, "Error in loading the image %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    printf("Image: %s\n", argv[1]);
    printf(
        "Image width: %d\theight: %d\tChannels: %d\n",
        width, height, channels
    );

    png_ascii(width, height, channels, img, colored);
    stbi_image_free(img);
    return EXIT_SUCCESS;
}
