/** debug_logging.h
 * 
 **/

#ifndef __DEBUG_LOGGING_H__
#define __DEBUG_LOGGING_H__
 
#ifdef LOG_DEBUG
#include <stdio.h>
#define dbg_msg(string)         printf("DEBUG: %s\n", string);
#define dbg_val(val, format)    printf("DEBUG: %s = "format"\n", #val, val);
#else
#define dbg_msg(string)         __no_op__
#define dbg_val(val, format)    __no_op__
#endif
 
#ifdef LOG_INFO
#include <stdio.h>
#define info_msg(string)         printf("INFO: %s\n", string);
#define info_val(val, format)    printf("INFO: %s = "format"\n", #val, val);
#else
#define info_msg(string)         __no_op__
#define info_val(val, format)    __no_op__
#endif
 
#ifdef LOG_ERROR
#include <stdio.h>
#define error_msg(string)         printf("ERROR: %s\n", string);
#define error_val(val, format)    printf("ERROR: %s = "format"\n", #val, val);
#else
#define error_msg(string)         __no_op__
#define error_val(val, format)    __no_op__
#endif

#endif // __DEBUG_LOGGING_H__
