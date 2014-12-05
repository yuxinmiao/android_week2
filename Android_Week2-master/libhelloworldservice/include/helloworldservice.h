#ifndef _HELLOWORLDSERVICE_H_
#define _HELLOWORLDSERVICE_H_

#include <utils/KeyedVector.h>
#include <utils/RefBase.h>
#include <binder/IInterface.h>
#include <binder/Parcel.h>
#include <utils/String16.h>
#include <utils/threads.h>
#include <string.h>

#include <utils/Log.h>

#include "helloworld.h"


class BnHelloWorld : public android::BnInterface<IHelloWorld>
{
    android::status_t onTransact(uint32_t code,
                                 const android::Parcel &data,
                                 android::Parcel *reply,
                                 uint32_t flags);

};

class HelloWorldService : public BnHelloWorld
{

public:
    static  void                instantiate();


    HelloWorldService();
    virtual                 ~HelloWorldService();

    mutable     android::Mutex                       mLock;
    int32_t                     mNextConnId;
    virtual void hellothere(const char *str);

};


#endif
