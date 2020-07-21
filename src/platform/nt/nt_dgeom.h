/**
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _NT_DGEOM_H_
#define _NT_DGEOM_H_
#include "../dgeom.h"
/**
 * Get the device physical block size
 * @param path device to run the ioctl on
 * @return the physical block device size
 */
size_t __pblksiz(char *path, int fd);
/**
 * Get the device block count in blocks pblksiz wide
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
#endif //_NT_DGEOM_H_
