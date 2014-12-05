#ifndef _HELLOWORLD_H_
#define _HELLOWORLD_H_

#define HELLOWORLD_NAME "org.tli21.helloworld"

#include "android-IInterface.h"

enum {
        HW_HELLOTHERE=1,
};


class IHelloWorld: public android::IInterface {
public:
        DECLARE_META_INTERFACE(HelloWorld)   // no trailing ;

        virtual void hellothere(const char *str) = 0;
};

#endif
