# crash-ps2
This is a project to decompile Crash Bandicoot: The Wrath of Cortex (PS2, v1.00, NTSC-U). It aims
to be as accurate as possbile, initially by providing functional implementations, and later matching the
recompiled instructions to the original machine code, to the best of our ability. The goal is to provide
a workable codebase that can be modified, improved, and ported to other platforms.

## Status
Currently, it cannot be compiled as only a few functions have been fully decompiled, and many are simply
stubs that don't function.

## Goals
The goal is to produce an executable with the open-source, homebrew PS2SDK.
The decompiled codebase can be used later to port the game to other platforms, if we want to.

## Building
The codebase is very incomplete, and not buildable at this time. The following
information below is for future reference.

### Prerequisites
You will need:
 * A US (NTSC-U) v1.00 copy of the game.
 * PS2SDK, available [here](https://github.com/ps2dev/ps2sdk).

TODO

## Notes

To figure out which version of the game you have, look at the disc packaging. If your copy
says "Greatest Hits", you don't have v1.00. Instead, you have v1.01.

If you have a PAL copy (identifiable by the language selection option on the title screen) or
Sakuretsu! Majin Power (JP), they are not supported right now, as the focus is on the v1.00 NTSC-U version. This file will
be updated once PAL or Japanese decompilation efforts begin.

If you have Return of the Demon King (KR), most likely, decompilation efforts will
not be made, as the game lacks debug symbols, making this process more difficult.

The GCN version will start probably after the PS2 version is complete.

`#ifdef` statements are placed in some files, as this project also aims to decompile
the E3 demo build (SLEU_000.01). If the `CRASH_PS2_E3` directive is defined by the `make e3_2001` command,
a binary similar to the E3 demo build will be produced.

## Information
 * Release year: 2001
 * Platforms: PS2, GCN, Xbox
 * Developer: Traveller's Tales
 * Publisher: Universal Interactive Studios (US/EU), Konami (US/EU/JP), HanbitSoft (KR)
 * Game engine: Currently unknown, probably a proprietary engine.
