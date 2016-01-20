# Copyright 2013 The Android Open Source Project

LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_SRC_FILES := discharge.c

LOCAL_CFLAGS := -Werror

LOCAL_MODULE := discharge

#LOCAL_LDLIBS := -lpthread
LOCAL_FORCE_STATIC_EXECUTABLE := true
LOCAL_STATIC_LIBRARIES := libutils libcutils libc

#LOCAL_MODULE_PATH := $(TARGET_ROOT_OUT)
#LOCAL_UNSTRIPPED_PATH := $(TARGET_ROOT_OUT_UNSTRIPPED)

#LOCAL_ADDITIONAL_DEPENDENCIES += $(LOCAL_PATH)/Android.mk

# belowing are debug infomation
$(shell %date)
$(info this is discharger app:$(LOCAL_MODULE))
$(warning "hello world")
$(warning local cflags:$(LOCAL_CFLAGS))
#$(error "this is error test")

include $(BUILD_EXECUTABLE)
