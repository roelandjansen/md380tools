rm -r call_db_test
gcc -std=c99 -Wall -O2 -DDMR_USERDB_NOT_IN_FLASH -I ../applet/src/ ../applet/src/call_db.c call_db_test.c -o call_db_test && ./call_db_test
