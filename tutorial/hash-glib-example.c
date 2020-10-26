#include <stdio.h>
#include <glib.h>

int main() {
    GHashTable *table=g_hash_table_new(g_str_hash, g_str_equal);
    g_hash_table_insert(table,"SOME_KEY","SOME_VALUE");
    gchar *value = (gchar *) g_hash_table_lookup(table,"SOME_KEY");
}

