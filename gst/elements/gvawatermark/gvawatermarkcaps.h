/*******************************************************************************
 * Copyright (C) 2018-2022 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 ******************************************************************************/

#include "gva_caps.h"

// Preferred format to use with VASurface and DMABuf
#define WATERMARK_PREFERRED_REMOTE_FORMAT "RGBA"

#define WATERMARK_SYSTEM_CAPS GST_VIDEO_CAPS_MAKE("{ BGRx, RGBA, BGRA, BGR, NV12, I420 }") "; "

#ifdef ENABLE_VAAPI
#define WATERMARK_VASURFACE_CAPS                                                                                       \
    GST_VIDEO_CAPS_MAKE_WITH_FEATURES(VASURFACE_FEATURE_STR, WATERMARK_PREFERRED_REMOTE_FORMAT) "; "
#define WATERMARK_DMA_BUFFER_CAPS                                                                                      \
    GST_VIDEO_CAPS_MAKE_WITH_FEATURES(DMABUF_FEATURE_STR, WATERMARK_PREFERRED_REMOTE_FORMAT) "; "
#else
#define WATERMARK_VASURFACE_CAPS
#define WATERMARK_DMA_BUFFER_CAPS
#endif

#define WATERMARK_ALL_CAPS WATERMARK_SYSTEM_CAPS WATERMARK_VASURFACE_CAPS WATERMARK_DMA_BUFFER_CAPS
