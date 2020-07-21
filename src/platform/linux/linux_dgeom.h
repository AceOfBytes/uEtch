/**
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _LINUX_DGEOM_H_
#define _LINUX_DGEOM_H_
#include <platform/dgeom.h>
/**
 * Get the device physical block size
 * @param path device to run the ioctl on
 * @return the physical block device size
 */
size_t __pblksiz(char *path, int fd);
/**
 * Get the device block count in blocks p_blksiz wide
 * @param path device to run the ioctl on
 * @return the physical block device size
 */
size_t __blkct(char *path, int fd);
/**
 * Get the minimum io size of the device
 * @param path device to run the ioctl on
 * @return minimum io minimum size
 */
size_t __iomin(char *path, int fd);

/**
 * Platform specific abstraction for linux to retrieve the drive geometry
 * @param dgeom
 * @param path
 * @return
 */
size_t __linux_dgeom(struct devgeom *dgeom, char *path);

#endif //_LINUX_DGEOM_H_
