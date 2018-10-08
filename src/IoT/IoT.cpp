
/* ['Common headers' begin (DON'T REMOVE THIS LINE!)] */
#include "IoT.h"
/* ['Common headers' end (DON'T REMOVE THIS LINE!)] */

#ifdef CFG_USE_IOT
/* ['FuncMngr' begin (DON'T REMOVE THIS LINE!)] */
void FuncMngr(  )
{
    /* set initial state */
    static STATE_T state = ID_FUNCMNGR_INITIAL;

    switch( state )
    {
        /* State ID: ID_FUNCMNGR_INITIAL */
        case ID_FUNCMNGR_INITIAL:
        {
            /* Transition ID: ID_FUNCMNGR_TRANSITION_CONNECTION */
            /* Actions: */
            /* ['<global>::iot_init' begin] */
            dre.iot_go_online = true;
            
            dre.iot_go_offline = false;
            
            dre.iot_publish = false;
            /* ['<global>::iot_init' end] */
            state = ID_FUNCMNGR_INIT;
            break;
        }
        /* State ID: ID_FUNCMNGR_INIT */
        case ID_FUNCMNGR_INIT:
        {
            if( dre.iot_connected == true )
            {
                /* Transition ID: ID_FUNCMNGR_TRANSITION_CONNECTION */
                /* Actions: */
                /* ['<global>::iot_cmd_clear' begin] */
                dre.iot_go_online = false;
                
                dre.iot_go_offline = false;
                
                dre.iot_publish = false;
                /* ['<global>::iot_cmd_clear' end] */
                /* ['<global>::iot_publish' begin] */
                dre.iot_publish = true;
                /* ['<global>::iot_publish' end] */
                /* ['<global>::iot_pub_timer_rst' begin] */
                dre.iot_publish_timer = 0;
                /* ['<global>::iot_pub_timer_rst' end] */
                state = ID_FUNCMNGR_WORKING;
            }
            else if( dre.iot_connected == false )
            {
                /* Transition ID: ID_FUNCMNGR_TRANSITION_CONNECTION */
                /* Actions: */
                /* ['<global>::iot_dont_publish' begin] */
                dre.iot_publish = false;
                /* ['<global>::iot_dont_publish' end] */
            }
            break;
        }
        /* State ID: ID_FUNCMNGR_WORKING */
        case ID_FUNCMNGR_WORKING:
        {
            if( dre.iot_publish_timer >= CFG_PUBLISH_TIME )
            {
                /* Transition ID: ID_FUNCMNGR_TRANSITION_CONNECTION */
                /* Actions: */
                /* ['<global>::iot_publish' begin] */
                dre.iot_publish = true;
                /* ['<global>::iot_publish' end] */
                /* ['<global>::iot_pub_timer_rst' begin] */
                dre.iot_publish_timer = 0;
                /* ['<global>::iot_pub_timer_rst' end] */
            }
            else if( dre.iot_connected == false )
            {
                /* Transition ID: ID_FUNCMNGR_TRANSITION_CONNECTION */
                /* Actions: */
                /* ['<global>::iot_init' begin] */
                dre.iot_go_online = true;
                
                dre.iot_go_offline = false;
                
                dre.iot_publish = false;
                /* ['<global>::iot_init' end] */
                /* ['<global>::iot_dont_publish' begin] */
                dre.iot_publish = false;
                /* ['<global>::iot_dont_publish' end] */
                state = ID_FUNCMNGR_INIT;
            }
            else
            {
                /* Transition ID: ID_FUNCMNGR_TRANSITION_CONNECTION */
                /* Actions: */
                /* ['<global>::iot_pub_tim_incr' begin] */
                dre.iot_publish_timer++;
                /* ['<global>::iot_pub_tim_incr' end] */
                /* ['<global>::iot_dont_publish' begin] */
                dre.iot_publish = false;
                /* ['<global>::iot_dont_publish' end] */
            }
            break;
        }
    }
}
/* ['FuncMngr' end (DON'T REMOVE THIS LINE!)] */

/* ['IoTMng' begin (DON'T REMOVE THIS LINE!)] */
void IoTMng(  )
{
    /* set initial state */
    static STATE_T state = ID_IOTMNG_INITIAL;

    switch( state )
    {
        /* State ID: ID_IOTMNG_INITIAL */
        case ID_IOTMNG_INITIAL:
        {
            if( dre.iot_go_online == true )
            {
                /* Transition ID: ID_IOTMNG_TRANSITION_CONNECTION */
                /* Actions: */
                /* ['<global>::iot_connect' begin] */
                dre.iot_disconnect = false;
                
                dre.iot_connect = true;
                /* ['<global>::iot_connect' end] */
                state = ID_IOTMNG_CONNECTING;
            }
            break;
        }
        /* State ID: ID_IOTMNG_CONNECTING */
        case ID_IOTMNG_CONNECTING:
        {
            if( dre.iot_connected == false )
            {
                /* Transition ID: ID_IOTMNG_TRANSITION_CONNECTION_6 */
                /* Actions: */
                /* ['<global>::iot_connect' begin] */
                dre.iot_disconnect = false;
                
                dre.iot_connect = true;
                /* ['<global>::iot_connect' end] */
            }
            else if( dre.iot_connected == true )
            {
                /* Transition ID: ID_IOTMNG_TRANSITION_CONNECTION_2 */
                state = ID_IOTMNG_WORKINGONLINE;
            }
            break;
        }
        /* State ID: ID_IOTMNG_WORKINGONLINE */
        case ID_IOTMNG_WORKINGONLINE:
        {
            if( ( dre.iot_go_offline == true ) || ( dre.iot_connected == false ) )
            {
                /* Transition ID: ID_IOTMNG_OPTIMIZED_TRANSITION_1 */
                /* Actions: */
                /* ['<global>::iot_disconnect' begin] */
                dre.iot_connect = false;
                
                dre.iot_disconnect = true;
                /* ['<global>::iot_disconnect' end] */
                state = ID_IOTMNG_DISCONNECTING;
            }
            break;
        }
        /* State ID: ID_IOTMNG_DISCONNECTING */
        case ID_IOTMNG_DISCONNECTING:
        {
            if( dre.iot_connected == false )
            {
                /* Transition ID: ID_IOTMNG_TRANSITION_CONNECTION_5 */
                state = ID_IOTMNG_WORKINGOFFLINE;
            }
            break;
        }
        /* State ID: ID_IOTMNG_WORKINGOFFLINE */
        case ID_IOTMNG_WORKINGOFFLINE:
        {
            if( dre.iot_go_online == true )
            {
                /* Transition ID: ID_IOTMNG_TRANSITION_CONNECTION_7 */
                /* Actions: */
                /* ['<global>::iot_connect' begin] */
                dre.iot_disconnect = false;
                
                dre.iot_connect = true;
                /* ['<global>::iot_connect' end] */
                state = ID_IOTMNG_CONNECTING;
            }
            break;
        }
    }
}
/* ['IoTMng' end (DON'T REMOVE THIS LINE!)] */
#endif