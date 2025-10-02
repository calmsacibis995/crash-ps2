#include <stddef.h>
#include <string.h>

#include "edui.h"
#include "numem.h"

edUiMenu *
eduiMenuCreate(int x, int y, int w, int h, int font, int callback, char *fmt)
{
	int len;
	edUiMenu *menu;
	size_t size;

	size = sizeof(struct edUiMenu);
	if (fmt != '\0') {
		len = NuStrLen(fmt);
		size = len + sizeof(struct edUiMenu) + 1;
	}
	menu = (edUiMenu *) NUMEM_ALLOC(size);
	if (menu != NULL) {
		memset(menu, 0, size);
		menu->x = x;
		menu->y = y;
		menu->w = w;
		menu->h = h;
		menu->font = font;
		menu->callback = callback;
		menu->label = (char *)(menu + 1);
		if (fmt != '\0')
			NuStrCpy(menu + 1, fmt);
	}

	return menu;
}
