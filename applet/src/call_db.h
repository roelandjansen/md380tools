/**
 * lookup the a user given their ID (dmr_search) in the database.
 * The function returns 1 for success and 0 for "not found".
 * outsize refers to the size of the output buffer.
 */
extern int find_call_id(char *outstr, char * call_search,
                  const char *data, int outsize);
                  
