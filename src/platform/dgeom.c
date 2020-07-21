/**
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdlib.h>
#include <memory.h>
#include <fcntl.h>
#include <unistd.h>
#include "dgeom.h"

int uetch_dgeom(struct devgeom *dgeom, char *path)
{
	struct devgeom *_dgeom;
	int fd;

	if ((fd = open(path, O_RDONLY | O_NONBLOCK)) < 1)
		return 0;

	_dgeom = malloc(sizeof(struct devgeom));

	_dgeom->iomin = 0;
	_dgeom->blkct = 0;
	_dgeom->pblksiz = 0;

	if((_dgeom->iomin = __iomin(path, fd)) == 0)
		goto __devgeom_fail;

	if ((_dgeom->blkct = __blkct(path, fd)) == 0)
		goto __devgeom_fail;

	if((_dgeom->pblksiz = __pblksiz(path, fd)) == 0) {
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