#define LOG_TAG "HelloWorldService"

#include <utils/Log.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>

#include <string.h>
#include <cutils/atomic.h>
#include <utils/Errors.h>
#include <binder/IServiceManager.h>
#include <utils/String16.h>
#include <utils/String8.h>

#include "helloworldservice.h"
#include "utils/Log.h"

#include <unistd.h>


#define LOGE ALOGE
#define LOGW ALOGW

void HelloWorldService::instantiate() {
    android::defaultServiceManager()->addService(IHelloWorld::descriptor, new HelloWorldService());
}

HelloWorldService::HelloWorldService()
{
    LOGE("HelloWorldService created");
    mNextConnId = 1;
}

HelloWorldService::~HelloWorldService()
{
    LOGE("HelloWorldService destroyed");
}
/*
#define CHECK_INTERFACE(interface, data, reply) \
        do { if (!data.enforceInterface(interface::getInterfaceDescriptor())) { \
            LOGW("Call incorrectly routed to " #interface); \
            return android::PERMISSION_DENIED;              \
        } } while (0)
#define CHECK_INTERFACE(interface, data, reply)                         \
        if (!data.enforceInterface(interface::getInterfaceDescriptor())) { return android::PERMISSION_DENIED; }       \

android::status_t HelloWorldService::onTransact(uint32_t code,
                                                const android::Parcel &data,
                                                android::Parcel *reply,
                                                uint32_t flags)
{
        LOGE("OnTransact(%u,%u)", code, flags);
        
        switch(code) {
        case HW_HELLOTHERE: {
                                using namespace android;
                                const String8 interface(IHelloWorld::getInterfaceDescriptor());
                                printf("interface descriptor: %s\n", interface.string());
                                const String8 thiz(this->getInterfaceDescriptor());
                                printf("this binder descriptor: %s\n", thiz.string());
                                CHECK_INTERFACE(IHelloWorld, data, reply);
                                const char *str;
                                str = data.readCString();
                                hellothere(str);
                                return android::NO_ERROR;
        } break;
        default:
                return BBinder::onTransact(code, data, reply, flags);
        }

        return android::NO_ERROR;
}
*/
void HelloWorldService::hellothere(const char *str)
{
    printf("##### HelloWorld Service: %s #####\n", str);
}
    