#pragma once

#ifndef _WIN32
#    include <fcntl.h>
#    include <unistd.h>
static inline void Sleep(unsigned long ms) {
    usleep(ms * 1000); // 1ms = 1000us
}
#else
#    include <windows.h>
#endif
