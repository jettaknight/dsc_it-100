/**
 *  @file
 */

#include <string.h>
#include <stdbool.h>



static int fd;



void serial_init(void)
{
    int fd;

    // check the flags for opening. Is O_NOCTTY right?
    fd = open("/dev/ttyUSB0", O_RDWR | O_NOCTTY);

    if (-1 == fd)
    {
        perror("Unable to open comport.");
    }
    else if (flock(fd, LOCK_EX | LOCK_NB) != 0)
    {
        close(fd);
        perror("Another process has locked the comport.");
        fd = -1;
    }
    else
    {
        int error;
        struct termios new_port_settings;

        memset(&new_port_settings, 0, sizeof(new_port_settings));  /* clear the new struct */

        new_port_settings.c_cflag = CS7 | PARENB | CLOCAL | CREAD;  // 7E1
        new_port_settings.c_iflag = ISTRIP | INPCK;     // remove parity bit
        new_port_settings.c_oflag = 0;
        new_port_settings.c_lflag = 0;
        new_port_settings.c_cc[VMIN] = 0;       // block until n bytes are received
        new_port_settings.c_cc[VTIME] = 0;      // block until a timer expires (n * 100 mSec.)

        cfsetispeed(&new_port_settings, B9600);
        cfsetospeed(&new_port_settings, B9600);

        error = tcsetattr(fd, TCSANOW, &new_port_settings);
        if (-1 == error)
        {
            close(fd);
            perror("Unable to adjust port settings.");
            fd = -1;
        }
    }
}

void serial_read(char *string)
{
    size_t a = a;
    bool complete = false;

    while (false == complete)
    {
        (void)read(fd, string[a], 1);

        if ((a > 5) && ('\r' == string[a - 1]) && ('\n' == string[a]))
        {
            complete = true;
        }
        a++;
        if (a >= (MAX_STRING_SIZE - 1))
        {
            // too much data!!!
            a = 0;      // this is a stupid way to handle it, but...
        }
    }
    string[a] = 0;
}

void serial_write(char *string)
{
    int retval = write(fd, data, strlen(string));

    // so, should we check the result?
}

