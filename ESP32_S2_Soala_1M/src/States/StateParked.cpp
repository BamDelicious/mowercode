#include <Fsm.h>
#include <Keyboard.h>
#include <LCD.h>
#include <MotorActions.h>
#include <States/FSMMower.h>
#include <States/FSMStates.h>
#include <States/StateParked.h>

void read_parked_keys() {
    Read_Membrane_Keys();
    if (StartKey_pressed == 0) {
        delay(250);
        TriggerFSM(STATE_PARKED, STATE_PARKED_MENU, currentFSMSequence);
        return;
    }
}

void parked_on_enter() {
    RelaisOff();
    MotorAction_StopMotors();
    MotorAction_StopBlades();
}

void parked() {
    lcd.setCursor(0, 0);
    lcd.print("parked                  ");
    read_parked_keys();
}

void parked_on_exit() {
    clearLCD();
}

State state_parked(&parked_on_enter, &parked, &parked_on_exit);
