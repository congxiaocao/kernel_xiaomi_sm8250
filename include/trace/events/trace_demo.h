#undef TRACE_SYSTEM
#define TRACE_SYSTEM trace_demo

#if !defined(_TRACE_DEMO_H) || defined(TRACE_HEADER_MULTI_READ)
#define _TRACE_DEMO_H

#include <linux/tracepoint.h>

DECLARE_TRACE(trace_demo_hook,
 TP_PROTO(const char *content),
 TP_ARGS(content));

#endif

#include <trace/define_trace.h>