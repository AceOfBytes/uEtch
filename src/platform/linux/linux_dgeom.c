/**
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "../dgeom.h"
#include "linux_dgeom.h"
#include <sys/ioctl.h>
#include <linux/fs.h>
#include <fcntl.h>
#include <unistd.h>

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
