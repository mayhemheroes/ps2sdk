#ifndef _PFS_OPT_H
#define _PFS_OPT_H

#define PFS_PRINTF(format,...)	printf(format, ##__VA_ARGS__)
#define PFS_DRV_NAME		"pfs"

// TODO: last sdk 3.1.0 has PFS module with significant changes.
// Check what was changed, and maybe port changes.
// Note: PFS version the same: 2.2
// CRC32: 98E62276
#define PFS_MAJOR	2
#define PFS_MINOR	2

#ifdef PFS_POSIX_VER
#define PFS_IOCTL2_INC_CHECKSUM 1
#define PFS_STAT_RETURN_INODE_LBA 1
#else
#ifdef PFS_XOSD_VER
#define PFS_OSD_VER		1
#define PFS_SUPPORT_BHDD	1
#endif

/*	Define PFS_OSD_VER in your Makefile to build an OSD version, which will:
	1. Enable the PIOCINVINODE IOCTL2 function.
	2. (Unofficial) Return the LBA of the inode in private_5 and sub number in private_4 fields of the stat structure (returned by getstat and dread). */
#ifdef PFS_OSD_VER
#define PFS_IOCTL2_INC_CHECKSUM		1
#define PFS_STAT_RETURN_INODE_LBA	1
#endif
#endif

#ifdef _IOP
#define PFS_ENTRYPOINT _start
#else
#define PFS_ENTRYPOINT pfs_start
#endif

#endif
