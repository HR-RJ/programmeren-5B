// Copyright: GEATEC engineering, 2020
// License: Apache 2

/*
This program features 2 statemachines.
One has 2 states, the other 3.
They each run at their own pace.

Note that state machines don't have to cycle through a fixed sequence of states.
They can go through states in arbitrary, dynamically determined order.
Also state transitions do not need to be triggered by elapsed time intervals.
The may also be caused by external triggers, like sensor signals changing.
*/

#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>

namespace st = std;
namespace sc = st::chrono;

using namespace  st::literals::chrono_literals;

int main () {
    
    // ====== Define contiguous integer constants representing traffic light states

    enum {offBlinkState, onBlinkState};
    enum {greenPhaseState, yellowPhaseState, redPhaseState};
    
    // ====== Initialize yellow blinking traffic light
    
    auto const blinkTime = 3000;
    
    auto oldBlinkState = onBlinkState;
    auto blinkState = offBlinkState;
    
    auto yellowBlinkLightIsOn = false;
    
    // ====== Initialize green, yellow and red sequencing traffic light
    
    auto const phaseTime = 2000;
    
    auto oldPhaseState = redPhaseState;
    auto phaseState = greenPhaseState;
    
    auto greenPhaseLightIsOn = false;
    auto yellowPhaseLightIsOn = false;
    auto redPhaseLightIsOn = false;
    
    // ====== Initialize start times
    
    auto currentTime = sc::duration_cast <sc::milliseconds>(sc::system_clock::now () .time_since_epoch ()) .count ();
    auto startBlinkTime = currentTime;
    auto startPhaseTime = startBlinkTime;
    
    // ====== Filler for printing traffic light state
    
    auto filler = st::string (8, ' ');
    auto off = st::string (6, '.');
        
    // ====== Main control loop
    
    while (true) {
        
        // ====== Read out clock only once in the main loop, so there's only one unique time

        auto currentTime = sc::duration_cast <sc::milliseconds>(sc::system_clock::now () .time_since_epoch ()) .count ();
                
        // ====== Separate state machine for blinking traffic light, has 2 phases
        
        switch (blinkState) {
            case offBlinkState:
                if (blinkState != oldBlinkState) {
                    // This part only done once after state transition
                    oldBlinkState = blinkState;
                }
                
                // Transition condition continuously monitored
                if (currentTime - startBlinkTime > blinkTime) {
                    blinkState = onBlinkState;
                }
                
                break;
                
            case onBlinkState:
                if (blinkState != oldBlinkState) {
                    // This part only done once after state transition
                    oldBlinkState = blinkState;
                    yellowBlinkLightIsOn = true;
                }
                
                // Transition condition continuously monitored
                if (currentTime - startBlinkTime > 2 * blinkTime) {
                    blinkState = offBlinkState;
                    startBlinkTime = currentTime;             
                    yellowBlinkLightIsOn = false;
                }
                
                break;
        }
    
        // ====== Separate state machine for red, green, yellow phase traffic light, has 3 phases
        
        switch (phaseState) {
            case greenPhaseState:
                if (phaseState != oldPhaseState) {
                    // This part only done once after state transition   
                    oldPhaseState = phaseState;
                    greenPhaseLightIsOn = true;
                }
                
                // Transition condition continuously monitored
                if (currentTime - startPhaseTime > 2 * phaseTime) {
                    phaseState = yellowPhaseState;
                    greenPhaseLightIsOn = false;
                }
                
                break;
                
            case yellowPhaseState:
                if (phaseState != oldPhaseState) {
                    // This part only done once after state transition   
                    oldPhaseState = phaseState;
                    yellowPhaseLightIsOn = true;
                }
                
                // Transition condition continuously monitored
                if (currentTime - startPhaseTime > 3 * phaseTime) {
                    phaseState = redPhaseState;
                    yellowPhaseLightIsOn = false;
                }
                
                break;
                
            case redPhaseState:
                if (phaseState != oldPhaseState) {
                    // This part only done once after state transition   
                    oldPhaseState = phaseState;
                    redPhaseLightIsOn = true;
                }
                
                // Transition condition continuously monitored
                if (currentTime - startPhaseTime > 5 * phaseTime) {
                    phaseState = greenPhaseState;
                    startPhaseTime = currentTime;
                    redPhaseLightIsOn = false;
                }
                
                break;
        }
 
        if (currentTime % 1000 == 0) {  // Each second
            st::cout <<
                currentTime / 1000 << filler <<
                (yellowBlinkLightIsOn ? "Aan   " : off) << filler <<
                (greenPhaseLightIsOn ? "Groen " : off) << filler <<
                (yellowPhaseLightIsOn ? "Oranje" : off) << filler <<
                (redPhaseLightIsOn ? "Rood  " : off) << '\n';
        }
        
        st::this_thread::sleep_for (0.2ms);
    }
    
    return 0;
}