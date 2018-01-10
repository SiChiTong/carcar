#ifndef SHARE_PTR_H
#define SHARE_PTR_H

#include "common.h"
#define __FILENAME__ (strrchr(__FILE__, '/') ? (strrchr(__FILE__, '/') + 1):__FILE__)
#define LOG(fmt) printf("%s:%s:%d::%s\n",__FILENAME__,__func__,__LINE__,fmt)

int TestScopePtr();

#endif