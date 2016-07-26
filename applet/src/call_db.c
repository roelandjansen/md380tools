/*! \file usersdb.c
\brief There is the functionality
       which dmr id to the entry from the users.csv in flash reads
       the first line is the size im byte
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* All user database data is accessed through getdata.
 * This makes it easier to adapt to different kinds of sources.
 */

#ifdef DMR_USERDB_NOT_IN_FLASH

static char * getdata(char * dest, const char *  src, int count) {
    memcpy(dest, src, count);
    return dest;
}

#else /* user DB is in flash memory */

#include "md380.h"

/* All user database data is accessed through this function.
 * This makes it easier to adapt to different kinds of sources.
 */
static char * getdata(char * dest, const char * src, int count) {
    md380_spiflash_read(dest, (long) src, count);
    return dest;
}

#endif


/* parse number as text and return its numerical value
 */
static long getfirstnumber(const char * p) {
    char buffer[64];
    return (atol(getdata(buffer, p, 60)));
    }

/* copies a line of text starting at in[] that is terminated
 * with a linefeed '\n' or '\0' to out[]. At most outsize characters
 * are written to out[] (including null terminator). Lines that
 * don't fit into out[] are truncated. out[] will always be
 * null terminated if outsize > 0.
 */
static void readline(char *out, const char *in, int outsize) {
    if (outsize <= 0) return;
    char buff[64];
    const int blen = sizeof(buff);
    outsize -= 1; // for null terminator
    while (outsize > 0) {
        int chunk = outsize > blen ? blen : outsize;
        getdata(buff, in, chunk);
        for (int i = 0; i < chunk; ++i) {
            char c = buff[i];
            if (c == '\0' || c == '\n') {
                *out++ = '\0';
                return;
            }
            *out++ = c;
        }
        in += chunk;
        outsize -= chunk;
    }
    *out = '\0';
}

/* searches for a newline character starting at *p and returns
 * the pointer to the character following that newline
 */
static const char* next_line_ptr(const char* p) {
    char buffer[64];
    const int blen = sizeof(buffer);
    for (;;) {
        getdata(buffer, p, blen);
        int linefeedidx = 0;
        while (linefeedidx < blen && buffer[linefeedidx] != '\n') {
            ++linefeedidx;
        }
        if (linefeedidx < blen) {
            return p + linefeedidx + 1;
        }
        p += blen;
    }
}

/* parse call text
 */
static int getfirstcall (const char * p, char * out) {
  int i;
  for(i=0; p[i] != ','; i++) {
    out[i]=p[i];        
  }  
  out[i]='\0';
  return(0);
}

/* tries to locate and copy the line of text that starts with the
 * number dmr_search to the output buffer outstr. The return value
 * indicates whether the DMR ID was found (1) or not (0).
 */
static int find_call(char *outstr, char * call_search,
                    const char *dmr_begin, const char *dmr_end,
                    int outsize)
{
    char call[32];
    /* As long as there is at least one line of text between
       offsets dmr_begin and dmr_end... */
    while (dmr_begin != dmr_end) {
        const char* dmr_test = next_line_ptr(dmr_begin + (dmr_end - dmr_begin) / 2);
        if (dmr_test == dmr_end) { dmr_test = next_line_ptr(dmr_begin); }
        if (dmr_test == dmr_end) { dmr_test = dmr_begin; }
        
        getfirstcall(dmr_test, call);

        if(!strcmp(call_search, call)) {
            int i=0;
            int ii=0;
            readline(outstr, dmr_test, outsize);
            while(outstr[i++]!=',');
            while(outstr[i++]!=' ');
                        
            for(ii=0;outstr[i]!='\0';i++,ii++)
                outstr[ii]=outstr[i];
            outstr[ii]='\0';
            return 1;
        }
        if (strcmp(call_search, call) < 0) {
            dmr_end = dmr_test;
        } else {
            dmr_begin = next_line_ptr(dmr_test);
        }
    }
    return 0;
}

int find_call_id(char *outstr, char * call_search,
                  const char *data, int outsize)
{
    const long datasize = getfirstnumber(data);

    if (datasize == 0 || datasize > 3279629)  // filesize @ 20160420 is 2279629 byte
       return(0);

    const char *data_start = next_line_ptr(data);
    const char *data_end = data_start + datasize; // exclusive
    
    return find_call(outstr, call_search, data_start, data_end, outsize); 
}

