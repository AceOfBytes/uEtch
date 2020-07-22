/**
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <windows.h>
#include <ioapiset.h>
#include <winioctl.h>
#include <platform/nt/nt_dgeom.h>
#include <stdlib.h>
#include <fileapi.h>
#include <handleapi.h>

BOOL nt_get_drive_geom(LPCSTR path, DISK_GEOMETRY_EX *geometry_ex)
{
	HANDLE h_device = INVALID_HANDLE_VALUE;
	BOOL io_ctl_res = FALSE;
	DWORD junk = 0;

	h_device = CreateFileA(path,
			       0,
			       FILE_SHARE_READ | FILE_SHARE_WRITE,
			       NULL,
			       OPEN_EXISTING,
			       0,
			       NULL);

	if (h_device == INVALID_HANDLE_VALUE)
		return (FALSE);

	io_ctl_res = DeviceIoControl(h_device,
				     IOCTL_DISK_GET_DRIVE_GEOMETRY_EX,
				     NULL, 0,
				     geometry_ex, sizeof(*geometry_ex),
				     &junk,
				     (LPOVERLAPPED) NULL);

	CloseHandle(h_device);

	return (io_ctl_res);
}

int __nt_dgeom(struct devgeom *dgeom, char *path)
{
	struct devgeom *_dgeom;
	DISK_GEOMETRY_EX geometry_ex = {0};
	size_t ds;

	if(!nt_get_drive_geom(path, &geometry_ex))
		return -1;

	_dgeom = malloc(sizeof(struct devgeom));

	_dgeom->io_min = 0;
	_dgeom->blk_ct = 0;
	_dgeom->p_blksiz = 0;
	_dgeom->max_rsect = 0;

	memmove(dgeom, _dgeom, sizeof(struct devgeom));
	return 0;
}
