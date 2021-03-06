#include <Fsm.h>
#include <Keyboard.h>
#include <LCD.h>
#include <MotorActions.h>
#include <States/FSMMower.h>
#include <States/FSMSequences.h>
#include <States/FSMStates.h>
#include <States/StateParked.h>



// #define error1 String(STATE_EXIT_GARAGE) + String(STATE_FIND_WIRE_FORWARDS))

void read_error_keys() {
    Read_Membrane_Keys();
    if (StopKey_pressed == 0) {
        delay(250);
        beforeMenuFSMTransition = currentFSMTransition;
        TriggerFSM(STATE_ERROR, STATE_PARKED, currentFSMSequence);
        return;
    }
}

void error_on_enter() {
    RelaisOff();
}

void error() {
    lcd.setCursor(0, 0);
    lcd.print("ERROR...                ");
    lcd.setCursor(0, 1);

    // const int id1 = (String(STATE_EXIT_GARAGE) + String(STATE_FIND_WIRE_FORWARDS)).toInt();

    // constexpr int test = BAND_FIELD1(STATE_EXIT_GARAGE, STATE_EXIT_GARAGE); // (String(STATE_EXIT_GARAGE) + String(STATE_FIND_WIRE_FORWARDS));

    // switch (lastFSMTransition) {
    // case error1:
    //     // case FSMEVENT_EXIT_GARAGE__TO__FIND_WIRE_FORWARDS:
    //     // case FSMEVENT_ROTATE_TO_WIRE__TO__FIND_WIRE_FORWARDS:
    //     // case FSMEVENT_MOWING__TO__FIND_WIRE_FORWARDS:
    //     // case FSMEVENT_PARKED_MENU__TO__FIND_WIRE_FORWARDS:
    //     lcd.print("FIND WIRE FORWARDS                     ");
    //     break;
    //     // case FSMEVENT_EXIT_GARAGE__TO__FIND_WIRE_BACKWARDS:
    //     // case FSMEVENT_ROTATE_TO_WIRE__TO__FIND_WIRE_BACKWARDS:
    //     // case FSMEVENT_MOWING__TO__FIND_WIRE_BACKWARDS:
    //     // case FSMEVENT_PARKED_MENU__TO__FIND_WIRE_BACKWARDS:
    //     lcd.print("FIND WIRE BACKWARDS                    ");
    //     break;
    // default:
    //     lcd.print("UNKNOWN ERR " + String(lastFSMTransition) + "               ");
    //     break;
    // }
    read_error_keys();
}

void error_on_exit() {
    clearLCD();
}

State state_error(&error_on_enter, &error, &error_on_exit);
