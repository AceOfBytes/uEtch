/**
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _DGEOM_H_
#define _DGEOM_H_
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#if defined(__linux__)
#include <platform/linux/linux_dgeom.h>
#endif
#if defined(_WIN32) || defined(_WIN64)
#include <platform/nt/nt_dgeom.h>
#endif
struct devgeom {
    size_t blk_ct;
    size_t io_min;
    size_t p_blksiz;
    size_t max_rsect;
};
/**
 * This function abstracts over platform specifics and retrieves information about a drive geometry to dgeom
 * @param dgeom this struct will have it's values set to the relevant values if successful might be poison otherwise
 * @param path of device to retrive the geometry of
 * @return 0 or -1, on success and failure respectively
 */
int uetch_dgeom(struct devgeom *dgeom, char *path);

#endif //_DGEOM_H_
