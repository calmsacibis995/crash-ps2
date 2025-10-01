#include <stdio.h>

#include "nups2.h"
#include "numem.h"

/*
 * @unimplemented
 */
void
NuPs2Init(void)
{
}

/*
 * @unimplemented
 */
void
NuPs2InitIOP(void)
{
	long ret;

	if (!initialised) {
		initialised = TRUE;
		ret = NuFileSifLoadModule("SYS\\SIO2MAN.IRX", 0, NULL);
		if (ret < 0) {
			ret = NuFileSifLoadModule("SYS\\SIO2MAN.IRX", 0, NULL);
			if (ret < 0) {
				ret = NuFileSifLoadModule("/usr/local/sce/iop/modules/SIO2MAN.IRX", 0, NULL);
				if (ret < 0) {
					ret = sceSifLoadModule("host0:/usr/local/sce/iop/modules/sio2man.irx", 0, NULL);
					if (ret < 0) {
						printf("Can\'t load module sio2man\n");
						Exit(0);
					}
				}
			}
		}
		printf("Loaded module sio2man\n");

		nusound_irx_loaded = TRUE;
		ret = NuFileSifLoadModule("SYS\\NUSOUND.IRX", 0, NULL);
		if (ret < 0) {
			ret = NuFileSifLoadModule("/usr/local/sce/iop/modules/nusound.irx", 0, NULL);
			if (ret < 0) {
				ret = sceSifLoadModule("host0:/usr/local/sce/iop/modules/nusound.irx", 0, NULL);
				if (ret < 0) {
					printf("Can\'t load module nusound - sound services will be denied\n");
					nusound_irx_loaded = FALSE;
				}
			}
		}
		printf("Loaded module nusound\n");

		ret = sceMcInit();
		printf("sceMcInit result %d\n", ret);
		scePadInit(0);
		sceSifInitIopHeap();
		sceSdRemoteInit();
	}
}

/*
 * @unimplemented
 */
void
NuPs2InitVideo(int width, int height, uint16_t zbuf_format, uint32_t fb_format,
	uint32_t video_mode)
{
}

/*
 * @unimplemented
 */
void
NuPs2VideoSetPos(int x, int y)
{
}
