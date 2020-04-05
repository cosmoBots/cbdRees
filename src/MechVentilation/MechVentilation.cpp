/* ['Common headers' begin (DON'T REMOVE THIS LINE!)] */
#include "MechVentilation.h"
/* ['Common headers' end (DON'T REMOVE THIS LINE!)] */

/* ['MechVentilation' begin (DON'T REMOVE THIS LINE!)] */
void MechVentilation(  )
{
    /* set initial state */
    static STATE_T state = ID_MECHVENTILATION_INITMV;

    switch( state )
    {
        /* State ID: ID_MECHVENTILATION_INITMV */
        case ID_MECHVENTILATION_INITMV:
        {
            /* Transition ID: ID_MECHVENTILATION_TRANSITION_CONNECTION */
            /* Actions: */
            /* ['<global>::InitMVvars' begin] */
                /* Init MechVentilator local vars */
                dre.mv.currentWaitTriggerTime = 0;
                dre.mv.currentStopInsufflationTime = 0;
                dre.mv.currentFlow = 0;
                /* Init MechVentilator FSM vars */
                dre.mv.running = false;
                dre.mv.enable = false;
                dre.mv.running = false;
                dre.mv.startWasTriggeredByPatient = false;
                dre.mv.currentPressure = 0.0;
                dre.mv.currentFlow = 0.0;
                dre.mv.currentVolume = 0.0;
            /* ['<global>::InitMVvars' end] */
            state = ID_MECHVENTILATION_DISABLED;
            break;
        }
        /* State ID: ID_MECHVENTILATION_DISABLED */
        case ID_MECHVENTILATION_DISABLED:
        {
            if( dre.mv.enable == true )
            {
                /* Transition ID: ID_MECHVENTILATION_TRANSITION_CONNECTION */
                /* Actions: */
                /* ['<global>::setRunning' begin] */
                dre.mv.running = true;
                /* ['<global>::setRunning' end] */
                /* ['<global>::openSolen' begin] */
                dre.misc.solenoid = SOLENOID_OPEN;
                /* ['<global>::openSolen' end] */
                state = ID_MECHVENTILATION_INIT_HOMING;
            }
            break;
        }
        /* State ID: ID_MECHVENTILATION_INIT_HOMING */
        case ID_MECHVENTILATION_INIT_HOMING:
        {
            if( dre.mv.sensor_error_detected == true )
            {
                /* Transition ID: ID_MECHVENTILATION_TRANSITION_CONNECTION */
                /* Actions: */
                /* ['<global>::stopMV' begin] */
                dre.mv.enable = false;
                /* ['<global>::stopMV' end] */
                /* ['<global>::notifSensErr' begin] */
                dre.fail.sensor = true;
                /* ['<global>::notifSensErr' end] */
                state = ID_MECHVENTILATION_STOP;
            }
            else if( dre.misc.endstop == true )
            {
                /* Transition ID: ID_MECHVENTILATION_TRANSITION_CONNECTION */
                /* Actions: */
                /* ['<global>::goHome' begin] */
                dre.mv.stp.homingError = false;
                dre.mv.stp.homingDone = false;
                dre.mv.stp.homingReq = true;
                /* ['<global>::goHome' end] */
                state = ID_MECHVENTILATION_FINISH_HOMING;
            }
            break;
        }
        /* State ID: ID_MECHVENTILATION_FINISH_HOMING */
        case ID_MECHVENTILATION_FINISH_HOMING:
        {
            if( dre.mv.stp.homingError == true )
            {
                /* Transition ID: ID_MECHVENTILATION_TRANSITION_CONNECTION */
                /* Actions: */
                /* ['<global>::stopMV' begin] */
                dre.mv.enable = false;
                /* ['<global>::stopMV' end] */
                /* ['<global>::notifHomErr' begin] */
                dre.fail.homing = true;
                /* ['<global>::notifHomErr' end] */
                state = ID_MECHVENTILATION_STOP;
            }
            else if( dre.mv.stp.homingDone == true )
            {
                /* Transition ID: ID_MECHVENTILATION_TRANSITION_CONNECTION */
                /* Actions: */
                /* ['<global>::openSolen' begin] */
                dre.misc.solenoid = SOLENOID_OPEN;
                /* ['<global>::openSolen' end] */
                /* ['<global>::launchExsufflation' begin] */
                dre.mv.totalCyclesInThisState = dre.mv.timeoutEsp / MV_TIME_BASE;
                dre.sensors->saveVolume();
                /* Stepper control*/
                dre.mv.stp.stepper->setSpeedInStepsPerSecond(dre.mv.stp.speed);
                dre.mv.stp.stepper->setAccelerationInStepsPerSecondPerSecond(
                    STEPPER_ACC_EXSUFFLATION);
                dre.mv.stp.stepper->setTargetPositionInSteps(
                    STEPPER_DIR * (STEPPER_LOWEST_POSITION));
                /* ['<global>::launchExsufflation' end] */
                /* ['<global>::rstTim' begin] */
                dre.mv.currentTime=0;
                /* ['<global>::rstTim' end] */
                state = ID_MECHVENTILATION_EXSUFFLATION;
            }
            break;
        }
        /* State ID: ID_MECHVENTILATION_EXSUFFLATION */
        case ID_MECHVENTILATION_EXSUFFLATION:
        {
            if( dre.mv.stp.stepper->motionComplete() && 
  (dre.mv.currentFlow < dre.mv.triggerThreshold && dre.mv.hasTrigger) )
            {
                /* Transition ID: ID_MECHVENTILATION_TRANSITION_CONNECTION */
                /* Actions: */
                /* ['<global>::setPatTrigFlag' begin] */
                dre.mv.startWasTriggeredByPatient = true;
                /* ['<global>::setPatTrigFlag' end] */
                state = ID_MECHVENTILATION_INSUFFLATION;
            }
            else if( (dre.mv.currentTime > dre.mv.totalCyclesInThisState) 
  &&  (!dre.mv.stp.stepper->motionComplete()) )
            {
                /* Transition ID: ID_MECHVENTILATION_TRANSITION_CONNECTION */
                /* Actions: */
                /* ['<global>::forceMotStop' begin] */
                dre.mv.stp.stepper->setTargetPositionInSteps(
                  dre.mv.stp.stepper->getCurrentPositionInSteps());
                /* ['<global>::forceMotStop' end] */
                /* ['<global>::rstTim' begin] */
                dre.mv.currentTime=0;
                /* ['<global>::rstTim' end] */
                /* ['<global>::clrPatTrigFlag' begin] */
                dre.mv.startWasTriggeredByPatient = false;
                /* ['<global>::clrPatTrigFlag' end] */
                state = ID_MECHVENTILATION_INSUFFLATION;
            }
            else if( (dre.mv.currentTime > dre.mv.totalCyclesInThisState) )
            {
                /* Transition ID: ID_MECHVENTILATION_TRANSITION_CONNECTION */
                /* Actions: */
                /* ['<global>::rstTim' begin] */
                dre.mv.currentTime=0;
                /* ['<global>::rstTim' end] */
                /* ['<global>::clrPatTrigFlag' begin] */
                dre.mv.startWasTriggeredByPatient = false;
                /* ['<global>::clrPatTrigFlag' end] */
                state = ID_MECHVENTILATION_INSUFFLATION;
            }
            else
            {
                /* Transition ID: ID_MECHVENTILATION_TRANSITION_CONNECTION */
                /* Actions: */
                /* ['<global>::setStepperExAction' begin] */
                dre.mv.currentPressure = dre.mv.pressures.pressure1;
                dre.mv.pid->run();
                
                dre.mv.stp.stepper->setSpeedInStepsPerSecond(abs(dre.mv.stp.speed));
                if (dre.mv.stp.speed >= 0)
                {
                    dre.mv.stp.stepper->setTargetPositionInSteps(STEPPER_HIGHEST_POSITION);
                }
                else
                {
                    dre.mv.stp.stepper->setTargetPositionInSteps(STEPPER_LOWEST_POSITION);
                }
                /* ['<global>::setStepperExAction' end] */
                /* ['<global>::incrTim' begin] */
                dre.mv.currentTime++;
                /* ['<global>::incrTim' end] */
            }
            break;
        }
        /* State ID: ID_MECHVENTILATION_INSUFFLATION */
        case ID_MECHVENTILATION_INSUFFLATION:
        {
            if( (dre.mv.currentTime > dre.mv.totalCyclesInThisState) 
  &&  (!dre.mv.stp.stepper->motionComplete()) )
            {
                /* Transition ID: ID_MECHVENTILATION_TRANSITION_CONNECTION */
                /* Actions: */
                /* ['<global>::forceMotStop' begin] */
                dre.mv.stp.stepper->setTargetPositionInSteps(
                  dre.mv.stp.stepper->getCurrentPositionInSteps());
                /* ['<global>::forceMotStop' end] */
                /* ['<global>::rstTim' begin] */
                dre.mv.currentTime=0;
                /* ['<global>::rstTim' end] */
                state = ID_MECHVENTILATION_EXSUFFLATION;
            }
            else if( (dre.mv.currentTime > dre.mv.totalCyclesInThisState) )
            {
                /* Transition ID: ID_MECHVENTILATION_TRANSITION_CONNECTION */
                /* Actions: */
                /* ['<global>::rstTim' begin] */
                dre.mv.currentTime=0;
                /* ['<global>::rstTim' end] */
                state = ID_MECHVENTILATION_EXSUFFLATION;
            }
            else
            {
                /* Transition ID: ID_MECHVENTILATION_TRANSITION_CONNECTION */
                /* Actions: */
                /* ['<global>::setStepperInAction' begin] */
                dre.mv.currentPressure = dre.mv.pressures.pressure1;
                dre.mv.pid->run();
                
                // TODO: if dre.mv.currentPressure > _pip + 5, trigger alarm
                dre.mv.stp.stepper->setSpeedInStepsPerSecond(abs(dre.mv.stp.speed));
                if (dre.mv.stp.speed >= 0)
                {
                    dre.mv.stp.stepper->setTargetPositionInSteps(STEPPER_HIGHEST_POSITION);
                }
                else
                {
                    dre.mv.stp.stepper->setTargetPositionInSteps(STEPPER_LOWEST_POSITION);
                }
                /* ['<global>::setStepperInAction' end] */
                /* ['<global>::incrTim' begin] */
                dre.mv.currentTime++;
                /* ['<global>::incrTim' end] */
            }
            break;
        }
        /* State ID: ID_MECHVENTILATION_STOP */
        case ID_MECHVENTILATION_STOP:
        {
            break;
        }
    }
}
/* ['MechVentilation' end (DON'T REMOVE THIS LINE!)] */
