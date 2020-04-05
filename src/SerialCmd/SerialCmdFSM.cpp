#include "SerialCmd.h"
/* ['Common headers' begin (DON'T REMOVE THIS LINE!)] */
#include "SerialCmdFSM.h"
#ifdef CFG_USE_SERIALCMD
/* ['Common headers' end (DON'T REMOVE THIS LINE!)] */
/* ['DispatchSysCmd' begin (DON'T REMOVE THIS LINE!)] */
void DispatchSysCmd(  )
{
    /* set initial state */
    static STATE_T state = ID_DISPATCHSYSCMD_INITIAL;

    switch( state )
    {
        /* State ID: ID_DISPATCHSYSCMD_INITIAL */
        case ID_DISPATCHSYSCMD_INITIAL:
        {
            /* Transition ID: ID_DISPATCHSYSCMD_TRANSITION_CONNECTION */
            /* Actions: */
            /* ['<global>::reset_cmd_storage' begin] */
            dre.cmd_base = 0;
            dre.cmd_counter = 0;
            /* ['<global>::reset_cmd_storage' end] */
            state = ID_DISPATCHSYSCMD_WAITING;
            break;
        }
        /* State ID: ID_DISPATCHSYSCMD_WAITING */
        case ID_DISPATCHSYSCMD_WAITING:
        {
            if( dre.cmd_counter != dre.cmd_base )
            {
                /* Transition ID: ID_DISPATCHSYSCMD_TRANSITION_CONNECTION */
                state = ID_DISPATCHSYSCMD_DECODECMD;
            }
            break;
        }
        /* State ID: ID_DISPATCHSYSCMD_DECODECMD */
        case ID_DISPATCHSYSCMD_DECODECMD:
        {
            if( (dre.cmd_storage[dre.cmd_base][0] == 'e') )
            {
                /* Transition ID: ID_DISPATCHSYSCMD_TRANSITION_CONNECTION */
                /* Actions: */
                /* ['<global>::process_emgcy_cmd' begin] */
                dre.emgcy_action = (dre.cmd_storage[dre.cmd_base][1] == '1');
                /* ['<global>::process_emgcy_cmd' end] */
                state = ID_DISPATCHSYSCMD_EMGCYCMD;
            }
            else if( dre.cmd_storage[dre.cmd_base][0] == 'l' )
            {
                /* Transition ID: ID_DISPATCHSYSCMD_TRANSITION_CONNECTION */
                /* Actions: */
                process_led_cmd();
                state = ID_DISPATCHSYSCMD_DIAGLEDCMD;
            }
            break;
        }
        /* State ID: ID_DISPATCHSYSCMD_EMGCYCMD */
        case ID_DISPATCHSYSCMD_EMGCYCMD:
        {
            if( true /* Instant command */ )
            {
                /* Transition ID: ID_DISPATCHSYSCMD_TRANSITION_CONNECTION */
                /* Actions: */
                /* ['<global>::jmp_next_cmd' begin] */
                dre.cmd_base = (dre.cmd_base + 1) % CFG_CMD_STORAGE_SIZE;
                /* ['<global>::jmp_next_cmd' end] */
                state = ID_DISPATCHSYSCMD_WAITING;
            }
            break;
        }
        /* State ID: ID_DISPATCHSYSCMD_DIAGLEDCMD */
        case ID_DISPATCHSYSCMD_DIAGLEDCMD:
        {
            if( true /* Instant command */ )
            {
                /* Transition ID: ID_DISPATCHSYSCMD_TRANSITION_CONNECTION */
                /* Actions: */
                /* ['<global>::jmp_next_cmd' begin] */
                dre.cmd_base = (dre.cmd_base + 1) % CFG_CMD_STORAGE_SIZE;
                /* ['<global>::jmp_next_cmd' end] */
                state = ID_DISPATCHSYSCMD_WAITING;
            }
            break;
        }
    }
}
/* ['DispatchSysCmd' end (DON'T REMOVE THIS LINE!)] */

/* ['ReceiveSysCmd' begin (DON'T REMOVE THIS LINE!)] */
void ReceiveSysCmd(  )
{
    /* set initial state */
    static STATE_T state = ID_RECEIVESYSCMD_INITIAL;

    /* State ID: ID_RECEIVESYSCMD_INITIAL */
    if( state==ID_RECEIVESYSCMD_INITIAL )
    {
        /* Transition ID: ID_RECEIVESYSCMD_TRANSITION_CONNECTION */
        /* Actions: */
        /* ['<global>::reset_serial_counter' begin] */
        dre.serial_counter = 0;
        /* ['<global>::reset_serial_counter' end] */
        state = ID_RECEIVESYSCMD_WAITING;
    }
    /* State ID: ID_RECEIVESYSCMD_WAITING */
    else if( state==ID_RECEIVESYSCMD_WAITING )
    {
        if( Serial.available() > 0 )
        {
            /* Transition ID: ID_RECEIVESYSCMD_TRANSITION_CONNECTION */
            /* Actions: */
            /* ['<global>::read_serial_byte' begin] */
            dre.incoming_bytes[dre.serial_counter++] = Serial.read();
            /* ['<global>::read_serial_byte' end] */
            state = ID_RECEIVESYSCMD_READCHAR;
        }
    }
    /* State ID: ID_RECEIVESYSCMD_READCHAR */
    else if( state==ID_RECEIVESYSCMD_READCHAR )
    {
        if( dre.incoming_bytes[dre.serial_counter-1] == '\n' )
        {
            /* Transition ID: ID_RECEIVESYSCMD_TRANSITION_CONNECTION */
            /* Actions: */
            /* ['<global>::store_received_command' begin] */
            process_received_command();
            /* ['<global>::store_received_command' end] */
            /* ['<global>::reset_serial_counter' begin] */
            dre.serial_counter = 0;
            /* ['<global>::reset_serial_counter' end] */
            state = ID_RECEIVESYSCMD_WAITING;
        }
        else
        {
            /* Transition ID: ID_RECEIVESYSCMD_TRANSITION_CONNECTION */
            state = ID_RECEIVESYSCMD_WAITING;
        }
    }
}
/* ['ReceiveSysCmd' end (DON'T REMOVE THIS LINE!)] */

/* ['Emergency' begin (DON'T REMOVE THIS LINE!)] */
void Emergency(  )
{
    /* set initial state */
    static STATE_T state = ID_EMERGENCY_INITIAL;

    switch( state )
    {
        /* State ID: ID_EMERGENCY_INITIAL */
        case ID_EMERGENCY_INITIAL:
        {
            /* Transition ID: ID_EMERGENCY_TRANSITION_CONNECTION */
            state = ID_EMERGENCY_NORMAL;
            break;
        }
        /* State ID: ID_EMERGENCY_NORMAL */
        case ID_EMERGENCY_NORMAL:
        {
            if( dre.emgcy_button == true )
            {
                /* Transition ID: ID_EMERGENCY_TRANSITION_CONNECTION */
                /* Actions: */
                /* ['<global>::emgcy_tim_rst' begin] */
                dre.emgcy_timer = 0;
                /* ['<global>::emgcy_tim_rst' end] */
                state = ID_EMERGENCY_WARNINGFILTER;
            }
            break;
        }
        /* State ID: ID_EMERGENCY_WARNINGFILTER */
        case ID_EMERGENCY_WARNINGFILTER:
        {
            if( (dre.emgcy_button == true) && (dre.emgcy_timer > CFG_EMGCY_QUALTIME) )
            {
                /* Transition ID: ID_EMERGENCY_TRANSITION_CONNECTION */
                /* Actions: */
                /* ['<global>::emgcy_action' begin] */
                dre.emgcy_action = true;
                /* ['<global>::emgcy_action' end] */
                /* ['<global>::emgcy_tim_rst' begin] */
                dre.emgcy_timer = 0;
                /* ['<global>::emgcy_tim_rst' end] */
                state = ID_EMERGENCY_EMERGENCY;
            }
            else if( dre.emgcy_button == true )
            {
                /* Transition ID: ID_EMERGENCY_TRANSITION_CONNECTION */
                /* Actions: */
                /* ['<global>::emgcy_tim_incr' begin] */
                dre.emgcy_timer++;
                /* ['<global>::emgcy_tim_incr' end] */
            }
            else
            {
                /* Transition ID: ID_EMERGENCY_TRANSITION_CONNECTION */
                state = ID_EMERGENCY_NORMAL;
            }
            break;
        }
        /* State ID: ID_EMERGENCY_EMERGENCY */
        case ID_EMERGENCY_EMERGENCY:
        {
            if( ! ( dre.emgcy_timer >= CFG_EMGCY_ACTTIME ) )
            {
                /* Transition ID: ID_EMERGENCY_TRANSITION_CONNECTION */
                /* Actions: */
                /* ['<global>::emgcy_tim_incr' begin] */
                dre.emgcy_timer++;
                /* ['<global>::emgcy_tim_incr' end] */
            }
            else
            {
                /* Transition ID: ID_EMERGENCY_TRANSITION_CONNECTION */
                state = ID_EMERGENCY_HEALING;
            }
            break;
        }
        /* State ID: ID_EMERGENCY_HEALING */
        case ID_EMERGENCY_HEALING:
        {
            if( ! ( dre.emgcy_button == true ) )
            {
                /* Transition ID: ID_EMERGENCY_TRANSITION_CONNECTION */
                /* Actions: */
                /* ['<global>::emgcy_healed' begin] */
                dre.emgcy_action = false;
                /* ['<global>::emgcy_healed' end] */
                state = ID_EMERGENCY_NORMAL;
            }
            else
            {
                /* Transition ID: ID_EMERGENCY_TRANSITION_CONNECTION */
            }
            break;
        }
    }
}
/* ['Emergency' end (DON'T REMOVE THIS LINE!)] */
#endif