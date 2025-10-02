#include "nufile.h"

#if !defined(CRASH_PS2_E3)
const char iop_img_name[] = "cdrom0:\SYS\IOPRP23.IMG";
#else
const char iop_img_name[] = "cdrom0:\SYS\IOPRP211.IMG";
#endif

/*
 * @implemented
 */
void *
NuFileInitEx(int devid, long iop_reboot_flag)
{
	void *datafiles_ptr;
	long ret;

	nufile_deviceid = devid;
	if ((devid == 1) || (devid == 3)) {
		sceSifInitRpc(0);
		sceCdInit(0);
		if (iop_reboot_flag) {
			do {
				ret = sceSifRebootIop(iop_img_name);
			} while (ret == 0);
			do {
				ret = sceSifSyncIop();
			} while (ret == 0);

			sceSifInitRpc(0);
			sceCdInit(0);
		}

		if (nufile_deviceid == 1)
			sceCdMmode(1);
		else
			sceCdMmode(2);
		sceFsReset();
		sceCdDiskReady(0);
	}

	memset(&memfiles, 0, 400);
#if !defined(CRASH_PS2_E3)
	datfiles_ptr = memset(&datfiles, 0, 0x230);
#else
	datfiles_ptr = memset(&datfiles, 0, 400);
#endif
	return datfiles_ptr;
}

void *
NuFileInit(int devid)
{
	void *datafiles_ptr;
	long ret;

	nufile_deviceid = devid;
	if ((devid == 1) || (devid == 3)) {
		sceSifInitRpc(0);
		sceCdInit(0);
		do {
			ret = sceSifRebootIop(iop_img_name);
		} while (ret == 0);
		do {
			ret = sceSifSyncIop();
		} while (ret == 0);

		sceSifInitRpc(0);
		sceCdInit(0);

		if (nufile_deviceid == 1)
			sceCdMmode(1);
		else
			sceCdMmode(2);
		sceFsReset();
		sceCdDiskReady(0);
	}

	memset(&memfiles, 0, 400);
#if !defined(CRASH_PS2_E3)
	datfiles_ptr = memset(&datfiles, 0, 0x230);
#else
	datfiles_ptr = memset(&datfiles, 0, 400);
#endif
	return datfiles_ptr;
}
