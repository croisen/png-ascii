# png -> ascii

Welp I originally wanted to directly convert aseprite files into ascii,
but that turned out to be a pain to parse on my own so I turned to pictures
instead, and as parsing that is a pain too, I went with stb.

## Dependency

-   [stb](https://github.com/nothings/stb)

## Building

The build system uses gcc to compile the two files so if you want you can change
build.c to use another set of build tools

While in the project directory compile build.c with your favourite c compiler
and run the output executable of that

There should be a png-ascii executable inside nobita-build/bin relative to
the project directory if nothing goes wrong

## Usage

```sh
# To just convert the image directly to ascii
./nobita-build/bin/png-ascii.elf <image.png>

# To just convert the image directly to colored ascii
# (well if your terminal supports it)
# Just make the image be the second argument of the executable
# -c is just nothing
./nobita-build/bin/png-ascii.elf -c <image.png>
```
