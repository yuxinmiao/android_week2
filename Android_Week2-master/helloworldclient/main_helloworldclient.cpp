/*
 * HelloWorld Service driver.
 * Copyright (C) 2009 Michael Richardson <mcr@credil.org>
 *
 * Released under the terms of the file ../NOTICE
 */
#define LOG_TAG "HelloWorldClient"

#include <sys/types.h>
#include <unistd.h>
#include <grp.h>

#include <binder/IPCThreadState.h>
#include <binder/ProcessState.h>
#include <binder/IServiceManager.h>
#include <utils/Log.h>

#include "helloworld.h"
#define LOGE ALOGE
#define LOGW ALOGW
#define LOGI ALOGI

int main(int argc, char *argv[])
{
    LOGI("Hello client is starting now");

    android::sp<android::IServiceManager> sm = android::defaultServiceManager();
    android::sp<android::IBinder> binder;
    android::sp<IHelloWorld> shw;

    do {
        binder = sm->getService(android::String16(HELLOWORLD_NAME));
        if (binder != 0)
            break;
        LOGW("HelloWorld not published, waiting...");
        usleep(500000); // 0.5 s
    } while(true);

    LOGI("Hello client is trying now");
    shw = android::interface_cast<IHelloWorld>(binder);
    shw->hellothere("fun");
    LOGI("Hello client is exiting now ");
    return(0);
}
