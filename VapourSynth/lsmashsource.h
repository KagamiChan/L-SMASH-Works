/*****************************************************************************
 * lsmashsource.h
 *****************************************************************************
 * Copyright (C) 2013 L-SMASH Works project
 *
 * Authors: Yusuke Nakamura <muken.the.vfrmaniac@gmail.com>
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 *****************************************************************************/

/* This file is available under an ISC license.
 * However, when distributing its binary file, it will be under LGPL or GPL. */

#include "VapourSynth.h"

#include "../common/utils.h"

typedef struct
{
    VSMap          *out;
    VSFrameContext *frame_ctx;
    const VSAPI    *vsapi;
} vs_basic_handler_t;

void set_error
(
    lw_log_handler_t *lhp,
    lw_log_level      level,
    const char       *format,
    ...
);

static inline void set_option_int64( int64_t *opt, int64_t default_value, const char *arg, const VSMap *in, const VSAPI *vsapi )
{
    int e;
    *opt = vsapi->propGetInt( in, arg, 0, &e );
    if( e )
        *opt = default_value;
}

static inline void set_option_string( const char **opt, const char *default_value, const char *arg, const VSMap *in, const VSAPI *vsapi )
{
    int e;
    *opt = vsapi->propGetData( in, arg, 0, &e );
    if( e )
        *opt = default_value;
}
