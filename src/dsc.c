/**
 *  @mainpage
 *  This is a C software interface to the DSC IT-100 security alarm panel interface.
 *
 *  The highlevel requirements:
 *    - Send SMS (email) notifactions on events.
 *    - Present a webpage with status, or output data as a file for formatting
 *    - Received commands from a webpage (fifo or socket?)
 *
 *  Since there's two asynchronous inputs (serial port, fifo) we shoudl create
 *  a separate pthread for one -we'll choose the serial input. Now that serial
 *  port can be blocking.
 *
 *  The overall architecture is designed for unit testing with Unity.
 *
 *
 *
 *
 *  @author Chris Pflieger
 *  @date 2019-01-27
 *
 *  @copyright
 *  MIT License
 *
 * Copyright (c) 2019 Chris Pflieger
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <pthread.h>
#include "dsc_protocol.h"
#include "dsc_serial.h"
#include "dsc_handler.h"


static void *serial_task(void *arg);



void main(void)
{
    // create input task (it opens serial port)
    pthread_t thr;

    (void)pthread_create(&thr, NULL, serial_task, NULL);

    // I think we want the serial taks to run enough to set things up before we continue.
    sleep(1);

    // the rest of this loops and looks for inputs from the web user, or other input.
    while (1)
    {
        sleep(1);
    }
}



// This pends for a string, then decodes it, then sends it to the handler.
static void *serial_task(void *arg)
{
    (void)arg;

    // call serial init task, if this fails...
    serial_init();

    while (1)
    {
        char input[MAX_STRING_SIZE];
        struct dsc_struct message;

        serial_read(input);
        if (0 == dsc_decode(&message))
        {
            process_dsc_message(&message);
        }
    }
}
