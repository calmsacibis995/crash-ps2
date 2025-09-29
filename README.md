# crash-ps2
This is a project to decompile Crash Bandicoot: The Wrath of Cortex (PS2, v1.00, NTSC-U). It aims
to be as accurate as possbile, initially by providing functional implementations, and later matching the
recompiled instructions to the original machine code, to the best of our ability. The goal is to provide
a workable codebase that can be modified, improved, and ported to other platforms.

## Status
Currently, it cannot be compiled as only a few functions have been fully decompiled, and many are simply
stubs that don't function.

## Building
The goal is to produce an executable with the open-source, homebrew PS2SDK, available [here](https://github.com/ps2dev/ps2sdk).
