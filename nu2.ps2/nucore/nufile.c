#include "nufile.h"

const char iop_img_name[] = "cdrom0:\SYS\IOPRP23.IMG";

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
	datfiles_ptr = memset(&datfiles, 0, 0x230);
	return datfiles_ptr;
}
