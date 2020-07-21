/**
 * SPDX-License-Identifier: BSD-3-Clause
 */


#include <platform/dgeom.h>

int uetch_dgeom(struct devgeom *dgeom, char *path)
{
#if defined(__linux__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wincompatible-pointer-types"
	return __linux_dgeom(dgeom, path);
#pragma clang diagnostic pop
#elif defined(_MSVC_FULL_VERSION)
#endif
}