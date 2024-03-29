/*
 * HelloWorld Service driver.
 * Copyright (C) 2009 Michael Richardson <mcr@credil.org>
 *
 * Released under the terms of the file ../NOTICE
 */
#define LOG_TAG "HelloWorld/Service"

#include <sys/types.h>
#include <unistd.h>
#include <grp.h>

#include <binder/IPCThreadState.h>
#include <binder/ProcessState.h>
#include <binder/IServiceManager.h>
#include <utils/Log.h>

#include "helloworldservice.h"
#define LOGI ALOGI

int main(int argc, char *argv[])
{
	HelloWorldService::instantiate();
	android::ProcessState::self()->startThreadPool();
	LOGI("Hello Service is ready now ");

	android::IPCThreadState::self()->joinThreadPool();
	return(0);
}
