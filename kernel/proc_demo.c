#include <linux/module.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#define CREATE_TRACE_POINTS
#include <trace/events/trace_demo.h>
EXPORT_TRACEPOINT_SYMBOL_GPL(trace_demo_hook);

static int trace_demo_show(struct seq_file *m, void *v)
{
    const char *content = "Hello World";

    trace_trace_demo_hook(content);
    seq_printf(m, "%s\n", content);
    
    return 0;
}

static int __init trace_demo_init(void)
{
    proc_create_single("trace_demo", 0444, NULL, trace_demo_show);

    return 0;
}

static void __exit trace_demo_exit(void)
{
    remove_proc_entry("trace_demo", NULL);
}

module_init(trace_demo_init);
module_exit(trace_demo_exit);

MODULE_LICENSE("GPL");