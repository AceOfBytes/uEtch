/**
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <platform/linux/linux_dgeom.h>
#include <sys/ioctl.h>
#include <linux/fs.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <memory.h>

size_t __pblksiz(char *path, int fd)
{
	size_t blksiz = 0;

	if ((fd = open(path, O_RDONLY | O_NONBLOCK)) < 1)
		return 0;

	if (ioctl(fd, BLKPBSZGET, &blksiz) < 0)
		blksiz = 0;

	return blksiz;
}

size_t __blkct(char *path, int fd)
{
	size_t blkct = 0;

	if ((fd = open(path, O_RDONLY | O_NONBLOCK)) < 1)
		return 0;

	if (ioctl(fd, BLKGETSIZE, &blkct) < 0)
		blkct = 0;

	return blkct;
}

size_t __iomin(char *path, int fd)
{
	size_t iomin = 0;

	if (ioctl(fd, BLKIOMIN, &iomin) < 0)
		iomin = 0;

	return iomin;
}

int __linux_dgeom(struct devgeom *dgeom, char *path)
{
	struct devgeom *_dgeom;
	int fd;

	if ((fd = open(path, O_RDONLY | O_NONBLOCK)) < 1)
		return 0;

	_dgeom = malloc(sizeof(struct devgeom));

	_dgeom->io_min = 0;
	_dgeom->blk_ct = 0;
	_dgeom->p_blksiz = 0;
	_dgeom->max_rsect = 0;

	if((_dgeom->io_min = __iomin(path, fd)) == 0)
		goto __devgeom_fail;

	if ((_dgeom->blk_ct = __blkct(path, fd)) == 0)
		goto __devgeom_fail;

	if((_dgeom->p_blksiz = __pblksiz(path, fd)) == 0) {
		goto __devgeom_fail;
	}

	memmove(dgeom, _dgeom, sizeof(struct devgeom));
	close(fd);
	return 0;
    __devgeom_fail:
	close(fd);
	free(_dgeom);
	return -1;
}

