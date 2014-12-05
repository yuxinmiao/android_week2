#define LOG_TAG "HelloWorldService-JNI"

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
#include <binder/Parcel.h>

#include "helloworld.h"
#include "helloworldservice.h"
#include "utils/Log.h" 

#include <unistd.h>



class BpHelloWorld: public android::BpInterface<IHelloWorld>
{
public:
        BpHelloWorld(const android::sp<android::IBinder>& impl)
                : android::BpInterface<IHelloWorld>(impl)
        {
        }

                
        void hellothere(const char *str)
        {
                android::Parcel data, reply;
                data.writeInterfaceToken(IHelloWorld::getInterfaceDescriptor());
                data.writeCString(str);
                remote()->transact(HW_HELLOTHERE, data, &reply, android::IBinder::FLAG_ONEWAY);
        }

};

IMPLEMENT_META_INTERFACE(HelloWorld, HELLOWORLD_NAME);

android::status_t BnHelloWorld::onTransact(uint32_t code,
                                           const android::Parcel &data,
                                           android::Parcel *reply,
                                           uint32_t flags)
{
    ALOGE("OnTransact(%u,%u)", code, flags);
    switch(code) {
        case HW_HELLOTHERE: 
            {
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
