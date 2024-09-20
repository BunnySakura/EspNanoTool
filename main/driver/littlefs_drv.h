//
// Created by hello3rd on 24-1-11.
//

#ifndef ESPNANOTOOL_MAIN_DRIVER_LITTLEFS_DRV_H_
#define ESPNANOTOOL_MAIN_DRIVER_LITTLEFS_DRV_H_

#define LFS_DEFAULT_ROOT_PATH "/lfs"

typedef struct LittleFs_ LittleFs;

LittleFs *LittleFsInit();

void LittleFsDel(LittleFs *this);

void LittleFsMount(LittleFs *this, const char *root, const char *partition);

void LittleFsUnmount(LittleFs *this);

#endif // ESPNANOTOOL_MAIN_DRIVER_LITTLEFS_DRV_H_
