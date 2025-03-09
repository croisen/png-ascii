#include <stdlib.h>

#define NOBITA_IMPL
#include "nobita.h"

// NOBITA_BT_GCC  - gcc,   g++,     ld,      as,      ar
// NOBITA_BT_LLVM - clang, clang++, llvm-ld, llvm-as, llvm-ar
// NOBITA_BT_MSVC - cl,    cl,      cl,      masm,    lib
enum nobita_build_tool build_tool = NOBITA_BT_GCC;

void build(Nobita_Build *b)
{
    Nobita_Try_Rebuild(b, __FILE__);

    Nobita_Exe *png_ascii = Nobita_Build_Add_Exe(b, "png-ascii");
    Nobita_Target_Set_Build_Tool(png_ascii, build_tool);
    if (build_tool != NOBITA_BT_MSVC)
        Nobita_Target_Add_Cflags(png_ascii,
            "-O3", "-g", "-static",
            "-Wall", "-Wextra", "-Wpedantic",
            NULL
        );
    else
        Nobita_Target_Add_Cflags(png_ascii, "/O2", "/Wall", NULL);

    Nobita_Target_Add_LDflags(png_ascii, "-lm", NULL);
    Nobita_Target_Add_Sources(png_ascii, "src/*.c", NULL);
}
