#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_DATA 512
#define MAX_ROWS 100

struct Address {
    int id;
    int set;
    char name[MAX_DATA];
    char email[MAX_DATA];
};

struct Database {
    struct Address rows[MAX_ROWS];
};

struct Connection {
    FILE *file;
    struct Database *db;
};

// http://stackoverflow.com/a/9834194/617839
// const char* is a mutable pointer to an immutable character/string
void die(const char* message)
{
    if (errno) {
        // from <errno.h>
        // print message with addition info on why that failed
        // ex: MESSAGE: No such file or directory
        perror(message);
    } else {
        printf("ERROR: %s\n", message);
    }

    // https://www.gnu.org/software/libc/manual/html_node/Exit-Status.html
    // exit(1) - Failure || exit(EXIT_FAILURE)
    /* exit(EXIT_FAILURE); */
    exit(1);
};

void Address_print(struct Address *addr)
{
    printf("%d %s %s\n", addr->id, addr->name, addr->email);
}

void Database_load(struct Connection *conn)
{
    // size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);
    //
    // The function fread() reads nmemb items of data, each size bytes long,
    // from the stream pointed to by stream, storing them at the location given by ptr.
    //
    int rc = fread(conn->db, sizeof(struct Database), 1, conn->file);
    if (rc != 1) die("Failed to load database");
}

struct Connection *Database_open(const char *filename, char mode)
{
    struct Connection *conn = malloc(sizeof(struct Connection));
    if (!conn) die("Memory error");

    conn->db = malloc(sizeof(struct Database));
    if (!conn->db) die("Memory error");

    // http://man7.org/linux/man-pages/man3/fopen.3.html
    if (mode == 'c') {
        // w    Truncate file to zero length or create text file for writing.
        // The stream is positioned at the beginning of the file.
        conn->file = fopen(filename, "w");
    } else {
        // r+   Open for reading and writing.
        // The stream is positioned at the beginning of the file.
        conn->file = fopen(filename, "r+");

        if (conn->file) {
            Database_load(conn);
        }
    }

    if (!conn->file) die("Failed to open the file");

    return conn;
}

void Database_close(struct Connection *conn)
{
    if (conn) {
        if (conn->file) fclose(conn->file);
        if (conn->db) free(conn->db);
        free(conn);
    }
}

void Database_write(struct Connection *conn)
{
    // The rewind function sets the file position to the beginning of the file
    // for the stream pointed to by stream.
    // It also clears the error and end-of-file indicators for stream.
    rewind(conn->file);

    // size_t fwrite(void *ptr, size_t size, size_t nmemb, FILE *stream);
    //
    // The function fwrite() writes nmemb of data, each size bytes long,
    // to the stream pointed by stream, obtaining them from the location given by ptr.
    //
    int rc = fwrite(conn->db, sizeof(struct Database), 1, conn->file);
    if (rc != 1) die("Failed to write database.");

    // on fflush: http://stackoverflow.com/a/16781818/617839
    // alternative: http://www.techonthenet.com/c_language/standard_library_functions/stdio_h/setvbuf.php
    // For output streams, fflush() forces a write of all user-space buffered data
    // for the given output or update stream via the stream's underlying write function.
    rc = fflush(conn->file);
    // http://linux.die.net/man/3/fflush
    // Upon successful completion 0 is returned.
    // Otherwise, EOF is returned and errno is set to indicate the error.
    // EOF is defined in stdio.h normally as -1
    if (rc == -1) die("Cannot flush database");
}

void Database_create(struct Connection *conn)
{
    int i = 0;

    for (i = 0; i < MAX_ROWS; i++) {
        // make a prototype to initialize it
        struct Address addr = { .id = i, .set = 0 };
        // then just assign it
        conn->db->rows[i] = addr;
    }
}

void Database_set(struct Connection *conn, int id, const char *name, const char *email)
{
    struct Address *addr = &conn->db->rows[id];
    if (addr->set) die("Address set, delete it first");

    addr->set = 1;
    // WARNING: bug, read the "How To Break It" and fix this
    //
    // strncpy vs strdup
    // http://stackoverflow.com/a/14021039/617839
    char *res = strncpy(addr->name, name, MAX_DATA);
    // demonstrate the strncpy bug
    if (!res) die("Name copy failed");

    res = strncpy(addr->email, email, MAX_DATA);
    if (!res) die("Email copy failed");
}

void Database_get(struct Connection *conn, int id)
{
    struct Address *addr = &conn->db->rows[id];

    if (addr->set) {
        Address_print(addr);
    } else {
        die("ID is not set");
    }
}

void Database_delete(struct Connection *conn, int id)
{
    struct Address addr = { .id = id, .set = 0 };
    conn->db->rows[id] = addr;
}

void Database_list(struct Connection *conn)
{
    int i = 0;
    struct Database *db = conn->db;

    for (i = 0; i < MAX_ROWS; i++) {
        struct Address *current = &db->rows[i];

        if (current->set) {
            Address_print(current);
        }
    }
}

int main(int argc, char *argv[])
{
    // Step 1: checking Address_print
    /*
    struct Address addr = { .id = 0, .name = "Joe", .email = "Doe@Joe.ro" };
    Address_print(&addr);
    */

    // Step 2: checking Database_open && Database_close
    // valgrind ./ex17_alex
    /*
    struct Connection *conn = Database_open("foobar", 'c');
    Database_close(conn);
    */

    // Step 3: checking Database_create, Database_write and Database_open("foobar", 'r')
    /*
    struct Connection *conn = Database_open("foobar", 'c');
    Database_create(conn);
    Database_write(conn);
    Database_close(conn);
    // struct Connection *conn = Database_open("foobar", 'r');
    */

    // Step 4: Database_set && Database_list
    /*
    struct Connection *conn = Database_open("foobar", 'r');
    Database_set(conn, 99, "Alex", "my@mail.ro");
    Database_list(conn);
    Database_close(conn);
    */

    // Step 5: Database_get && Database_delete
    /*
    struct Connection *conn = Database_open("foobar", 'r');
    // Database_set(conn, 99, "Alex", "my@mail.ro");
    // Database_write(conn);
    Database_get(conn, 99);
    Database_delete(conn, 99);
    Database_write(conn);
    Database_get(conn, 99);
    Database_close(conn);
    */

    return 0;
}
