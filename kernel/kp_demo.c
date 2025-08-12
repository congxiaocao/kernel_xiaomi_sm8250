#include <linux/kprobes.h>
#include <linux/module.h>

typedef unsigned long (*kallsyms_lookup_name_t)(const char *name); 
kallsyms_lookup_name_t addr_find_demo;
EXPORT_SYMBOL(addr_find_demo);

static int __init kp_demo_init(void) {
  static struct kprobe kp = {
    .symbol_name = "kallsyms_lookup_name"
  };

  register_kprobe(&kp);
  addr_find_demo = (kallsyms_lookup_name_t)kp.addr;
  pr_info("kp_demo: kallsyms_lookup_name's address: %p\n", addr_find_demo);
  unregister_kprobe(&kp);
  return 0;
}

static void __exit kp_demo_exit(void)
{

}

module_init(kp_demo_init);
module_exit(kp_demo_exit);

MODULE_LICENSE("GPL");

