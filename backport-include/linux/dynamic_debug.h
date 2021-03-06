#ifndef __BACKPORT_LINUX_DYNAMIC_DEBUG_H
#define __BACKPORT_LINUX_DYNAMIC_DEBUG_H
#include <linux/version.h>
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,30)
#include_next <linux/dynamic_debug.h>
#endif

#if LINUX_VERSION_CODE < KERNEL_VERSION(3,2,0)
/* backports 07613b0b */
#if defined(CONFIG_DYNAMIC_DEBUG)
#define DEFINE_DYNAMIC_DEBUG_METADATA(name, fmt)               \
	static struct _ddebug __used __aligned(8)               \
	__attribute__((section("__verbose"))) name = {          \
		.modname = KBUILD_MODNAME,                      \
		.function = __func__,                           \
		.filename = __FILE__,                           \
		.format = (fmt),                                \
		.lineno = __LINE__,                             \
		.flags =  _DPRINTK_FLAGS_DEFAULT,               \
		.enabled = false,                               \
	}
#endif /* defined(CONFIG_DYNAMIC_DEBUG) */
#endif /* < 3.2 */

#endif /* __BACKPORT_LINUX_DYNAMIC_DEBUG_H */
