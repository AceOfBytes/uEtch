/**
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <libuetch.h>
#include <stdio.h>
#include <stdlib.h>
#include <getcomp.h>
#include <errno.h>

int main(int argc, char **argv)
{
	struct devgeom dg;
	printf("%s\n", getcomp());

	if (argc <= 1) {
		printf("Need at least one argument!\n");
		return -1;
	}

	if(uetch_dgeom(&dg, argv[1]) != 0) {
		printf("%d\n", errno);
		return errno;
	}
	printf("block count: %lu\nio minimum size: %lu\nphysical block size: %lu\n", dg.blk_ct, dg.io_min, dg.p_blksiz);
	return 0;
}
