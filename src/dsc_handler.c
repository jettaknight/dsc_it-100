/**
 *  @file
 */

#include <string.h>
#include "dsc_handler.h"

// include all the handlers here.



void handle_POLL(struct dsc_struct *message)
void handle_STATUS_REQUEST(struct dsc_struct *message) {  }
void handle_LABELS_REQUEST(struct dsc_struct *message) {  }
void handle_SET_TIME_DATE(struct dsc_struct *message) {  }
void handle_OUTPUT_CONTROL(struct dsc_struct *message) {  }
void handle_PARTITION_ARM_CONTROL_AWAY(struct dsc_struct *message) {  }
void handle_PARTITION_ARM_CONTROL_STAY(struct dsc_struct *message) {  }
void handle_PARTITION_ARM_CONTROL_ARMED(struct dsc_struct *message) {  }
void handle_PARTITION_ARM_CONTROL_WITH_CODE(struct dsc_struct *message) {  }
void handle_PARTITION_DISARM_CONTROL(struct dsc_struct *message) {  }
void handle_TIME_STAMP_CONTROL(struct dsc_struct *message) {  }
void handle_TIME_DATE_BCAST_CONTROL(struct dsc_struct *message) {  }
void handle_TEMPERATURE_BCAST_CONTROL(struct dsc_struct *message) {  }
void handle_VIRTUAL_KEYBOARD_CONTORL(struct dsc_struct *message) {  }
void handle_TRIGGER_PANIC_ALARM(struct dsc_struct *message) {  }
void handle_KEY_PRESSED(struct dsc_struct *message) {  }
void handle_SET_BAUD_RATE(struct dsc_struct *message) {  }
void handle_CODE_SEND(struct dsc_struct *message) {  }











typedef void (*dsc_handler_t)(struct dsc_struct *message);

struct handler_table_struct
{
    dsc_handler_t handler;
    uint16_t command;
};

struct handler_table_struct handler_table[] =
{
    { handle_POLL,                             DSC_COMMAND_POLL                            },
    { handle_STATUS_REQUEST,                   DSC_COMMAND_STATUS_REQUEST                  },
    { handle_LABELS_REQUEST,                   DSC_COMMAND_LABELS_REQUEST                  },
    { handle_SET_TIME_DATE,                    DSC_COMMAND_SET_TIME_DATE                   },
    { handle_OUTPUT_CONTROL,                   DSC_COMMAND_OUTPUT_CONTROL                  },
    { handle_PARTITION_ARM_CONTROL_AWAY,       DSC_COMMAND_PARTITION_ARM_CONTROL_AWAY      },
    { handle_PARTITION_ARM_CONTROL_STAY,       DSC_COMMAND_PARTITION_ARM_CONTROL_STAY      },
    { handle_PARTITION_ARM_CONTROL_ARMED,      DSC_COMMAND_PARTITION_ARM_CONTROL_ARMED     },
    { handle_PARTITION_ARM_CONTROL_WITH_CODE,  DSC_COMMAND_PARTITION_ARM_CONTROL_WITH_CODE },
    { handle_PARTITION_DISARM_CONTROL,         DSC_COMMAND_PARTITION_DISARM_CONTROL        },
    { handle_TIME_STAMP_CONTROL,               DSC_COMMAND_TIME_STAMP_CONTROL              },
    { handle_TIME_DATE_BCAST_CONTROL,          DSC_COMMAND_TIME_DATE_BCAST_CONTROL         },
    { handle_TEMPERATURE_BCAST_CONTROL,        DSC_COMMAND_TEMPERATURE_BCAST_CONTROL       },
    { handle_VIRTUAL_KEYBOARD_CONTORL,         DSC_COMMAND_VIRTUAL_KEYBOARD_CONTROL        },
    { handle_TRIGGER_PANIC_ALARM,              DSC_COMMAND_TRIGGER_PANIC_ALARM             },
    { handle_KEY_PRESSED,                      DSC_COMMAND_KEY_PRESSED                     },
    { handle_SET_BAUD_RATE,                    DSC_COMMAND_SET_BAUD_RATE                   },
    { handle_CODE_SEND,                        DSC_COMMAND_CODE_SEND                       }
};

static size_t handler_count = sizeof(handler_table) / sizeof(struct handler_table_struct);


void process_dsc_message(struct dsc_struct *message)
{
    size_t i;

    for (i = 0; i < handler_count; i++)
    {
        if (   (handler_table[i].command == message->command)
            && (NULL != handler_table[i].handler))
        {
            handler_table[i].handler(message);
        }
    }
}

