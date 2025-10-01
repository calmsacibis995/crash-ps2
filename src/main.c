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
	superbuffer_base = NuMemAllocFn(0x1200000, __FILE__, __LINE__);
	superbuffer_end = superbuffer_base + 0x480000;
	superbuffer_reset_base = superbuffer_base;
	if (superbuffer_base == NULL)
		NUERROR_MSG("unable to allocate super buffer");

	// Run all game initialization routines.
	DefaultGame();
	ResetGame();
	NuPs2Init();
	NuFileInitEx(1, TRUE);

	Hub = &_heap_size;
	Level = &_heap_size;

	// Load IOP modules.
	NuPs2InitIOP();
}
