#include <stdio.h>
#include <string.h>
#include <stdarg.h>

#include "nufile.h"
#include "nuerror.h"

/*
 * @implemented
 */
static void
NuDebugMsgFunction(const char *msg, ...)
{
	int fd;
	size_t len;
	char buf[1024];
	char buf2[1024];
	va_list va;

	if (err_msg_quiet == FALSE) {
		va_start(va, msg);
		NuDisableVBlankE();
		if (!initialised) {
			initialised = TRUE;
			fd = NuFileOpen("nu2.err", 1);
			if (fd != 0)
				NuFileClose(fd);
		}

		dbg_msg_cnt++;
		sprintf(buf2, "%05d NuDebugMsg - %s(%d) : ", dbg_msg_cnt, errfile, errline);
		vsprintf(buf, msg, va);
		strcat(buf2, buf);
		strcat(buf2, "\r\n");
		if (errmsg_to_file == FALSE) {
			if (allow_printf == TRUE)
				printf(buf2);
		} else {
			err_msg_quiet = TRUE;
			fd = NuFileOpen("nu2.err", 2);
			if (fd == 0)
				fd = NuFileOpen("nu2.err", 1);
			else
				NuFileSeek(fd, 0, 2);

			if (fd == 0)
				err_msg_quiet = FALSE;
			else {
				len = strlen(buf2);
				NuFileWrite(fd, buf2, len);
				NuFileClose(fd);
				err_msg_quiet = 0;
			}
		}
		NuEnableVBlankE();
	}
}

/*
 * @implemented
 */
void
(*NuDebugMsgProlog(char *filename, int lineno))(const char *, ...)
{
	char *c;

	errfilepath = filename;
	errline = lineno;
	c = strrchr(filename, '\\');
	errfile = filename;
	if (c != '\0')
		errfile = c + 1;

	return NuDebugMsgFunction;
}
