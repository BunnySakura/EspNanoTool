//
// Created by hello3rd on 24-1-11.
//

#ifndef ESPNANOTOOL_MAIN_DRIVER_LITTLEFS_INIT_H_
#define ESPNANOTOOL_MAIN_DRIVER_LITTLEFS_INIT_H_

#define DEFAULT_ROOT_PATH "/littlefs"

typedef struct DrvLittleFs DrvLittleFs;

DrvLittleFs *DrvLittleFsInit();

void DrvLittleFsDel(DrvLittleFs *this);

void DrvLittleFsMount(DrvLittleFs *this, const char *root, const char *partition);

void DrvLittleFsUnmount(DrvLittleFs *this);

#endif //ESPNANOTOOL_MAIN_DRIVER_LITTLEFS_INIT_H_
