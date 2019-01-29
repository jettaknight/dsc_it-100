#include "unity.h"
#include "dsc_protocol.h"
#include <string.h>

/*********************** mock **************************************/




/***************** SetUp and tearDown ******************************/



void setUp(void)
{

}

void tearDown(void)
{

}


/**************** The tests ****************************************/


void test_encode1(void)
{
    char string[100];
    struct dsc_struct message;

    message.command = 0;
    message.data_size = 0;

    dsc_encode(string, &message);

    TEST_ASSERT_EQUAL_STRING("00090\r\n", string);
}

void test_encode2(void)
{
    char string[100];
    struct dsc_struct message;

    message.command = 200;
    message.data_size = 6;
    memcpy(message.data, "123456", message.data_size);

    dsc_encode(string, &message);

    TEST_ASSERT_EQUAL_STRING("200123456C7\r\n", string);
}

void test_decode1(void)
{
    char string[] = "200123456C7\r\n";
    struct dsc_struct message;

    dsc_decode(string, &message);

    TEST_ASSERT_EQUAL(200, message.command);
    TEST_ASSERT_EQUAL(6, message.data_size);
    TEST_ASSERT_EQUAL_MEMORY("123456", message.data, message.data_size);
}

void test_decode_short_message(void)
{
    char string[] = "123\r\n";
    struct dsc_struct message;

    dsc_decode(string, &message);

    TEST_ASSERT_EQUAL(0xFFFF, message.command);
}

void test_decode_no_endings(void)
{
    char string[] = "200123456C7\r";
    struct dsc_struct message;

    dsc_decode(string, &message);

    TEST_ASSERT_EQUAL(0xFFFF, message.command);
}

void test_decode_bad_checksum(void)
{
    char string[] = "200123456C6\r\n";
    struct dsc_struct message;

    dsc_decode(string, &message);

    TEST_ASSERT_EQUAL(0xFFFF, message.command);
}










