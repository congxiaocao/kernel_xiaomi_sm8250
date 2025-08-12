#include <linux/module.h>
#include <trace/events/trace_demo.h>

void trace_demo_callback(void *data, const char *content)
{
    pr_info("%s\n", content);
}

static int __init demo_init(void) 
{
    register_trace_trace_demo_hook(trace_demo_callback, NULL);
    return 0;
}

static void __exit demo_exit(void)
{  
    unregister_trace_trace_demo_hook(trace_demo_callback, NULL);
}

module_init(demo_init);
module_exit(demo_exit);

MODULE_LICENSE("GPL");