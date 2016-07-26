rm dmr_id_db_test
 gcc -std=c99 -Wall -O2 -DDMR_USERDB_NOT_IN_FLASH -I ../applet/src/ ../applet/src/dmr_id_db.c id_db_test.c -o dmr_id_db_test && ./dmr_id_db_test
