/** debug_logging.h
 * 
 **/

#ifndef __debug_logging_H__
#define __debug_logging_H__
 
#ifdef __DEBUG__
#include <stdio.h>
#define DBG_MSG(string)         printf("DEBUG: %s\n", string);
#define DBG_VAL(val, format)    printf("DEBUG: %s = "format"\n", #val, val);
#else
#define DBG_MSG(string)         __no_op__
#define DBG_VAL(val, format)    __no_op__
#endif
 
#endif // __debug_logging_H__

