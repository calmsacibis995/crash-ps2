#include "game.h"
#include "nups2.h"
#include "numem.h"
#include "nuerror.h"

/*
 * @unimplemented
 */
void
main(void)
{
	no_default_font = 0;

#if !defined(CRASH_PS2_E3)
	superbuffer_base = NuMemAllocFn(0x1200000, __FILE__, __LINE__);
	superbuffer_end = superbuffer_base + 0x480000;
	superbuffer_reset_base = superbuffer_base;
	if (superbuffer_base == NULL)
		NUERROR_MSG("unable to allocate super buffer");

	// Run all game initialization routines.
	DefaultGame();
#else
	OnceOnlyInit();
#endif
	ResetGame();
	NuPs2Init();
#if !defined(CRASH_PS2_E3)
	NuFileInitEx(1, TRUE);
#else
	NuFileInit(1);
#endif

	Hub = &_heap_size;
	Level = &_heap_size;

	NuPs2InitIOP();		// Load IOP modules.
#if !defined(CRASH_PS2_E3)
	InitCutScenes();
#else
	init_adpcm();
	FlushIOPCommand(0);
	TransferAllSpotFX();
#endif

	// Configure video output.
	SHEIGHT = 448;
	SWIDTH = 640;
	NuPs2InitVideo(640, 224, 0, 49, 2);		// TODO: Document what those params mean.
	NuPs2VideoSetPos(0, 0);
	MAXVPSIZEX = SWIDTH;
	MAXVPSIZEY = SHEIGHT;
	MINVPSIZEY = SHEIGHT / 2;
	MINVPSIZEX = (SWIDTH * 396) / 640;

	// Initialize graphics subsystems.
	NuPs2InitVU();		// Vector units
	NuTrigInit();		// Trignometry
	NuVpInit();			// TODO: Figure out what "Vp" means.
	NuTexInit();		// Textures
	NuGobjInit();		// Game objects.
	NuMtlInit();		// TODO: Figure out what "Mtl" means.
	NuRndrInitEx(0x200000);		// Renderer.
	NuFntClose();		// Font close.
	NuLightInit();		// Lighting.
}
