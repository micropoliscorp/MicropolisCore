/* callback.cpp
 *
 * Micropolis, Unix Version.  This game was released for the Unix platform
 * in or about 1990 and has been modified for inclusion in the One Laptop
 * Per Child program.  Copyright (C) 1989 - 2007 Electronic Arts Inc.  If
 * you need assistance with this program, you may contact:
 *   http://wiki.laptop.org/go/Micropolis  or email  micropolis@laptop.org.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or (at
 * your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.  You should have received a
 * copy of the GNU General Public License along with this program.  If
 * not, see <http://www.gnu.org/licenses/>.
 *
 *             ADDITIONAL TERMS per GNU GPL Section 7
 *
 * No trademark or publicity rights are granted.  This license does NOT
 * give you any right, title or interest in the trademark SimCity or any
 * other Electronic Arts trademark.  You may not distribute any
 * modification of this program using the trademark SimCity or claim any
 * affliation or association with Electronic Arts Inc. or its employees.
 *
 * Any propagation or conveyance of this program must include this
 * copyright notice and these terms.
 *
 * If you convey this program (or any modifications of it) and assume
 * contractual liability for the program to recipients of it, you agree
 * to indemnify Electronic Arts for any liability that those contractual
 * assumptions impose on Electronic Arts.
 *
 * You may not misrepresent the origins of this program; modified
 * versions of the program must be marked as such and not identified as
 * the original program.
 *
 * This disclaimer supplements the one included in the General Public
 * License.  TO THE FULLEST EXTENT PERMISSIBLE UNDER APPLICABLE LAW, THIS
 * PROGRAM IS PROVIDED TO YOU "AS IS," WITH ALL FAULTS, WITHOUT WARRANTY
 * OF ANY KIND, AND YOUR USE IS AT YOUR SOLE RISK.  THE ENTIRE RISK OF
 * SATISFACTORY QUALITY AND PERFORMANCE RESIDES WITH YOU.  ELECTRONIC ARTS
 * DISCLAIMS ANY AND ALL EXPRESS, IMPLIED OR STATUTORY WARRANTIES,
 * INCLUDING IMPLIED WARRANTIES OF MERCHANTABILITY, SATISFACTORY QUALITY,
 * FITNESS FOR A PARTICULAR PURPOSE, NONINFRINGEMENT OF THIRD PARTY
 * RIGHTS, AND WARRANTIES (IF ANY) ARISING FROM A COURSE OF DEALING,
 * USAGE, OR TRADE PRACTICE.  ELECTRONIC ARTS DOES NOT WARRANT AGAINST
 * INTERFERENCE WITH YOUR ENJOYMENT OF THE PROGRAM; THAT THE PROGRAM WILL
 * MEET YOUR REQUIREMENTS; THAT OPERATION OF THE PROGRAM WILL BE
 * UNINTERRUPTED OR ERROR-FREE, OR THAT THE PROGRAM WILL BE COMPATIBLE
 * WITH THIRD PARTY SOFTWARE OR THAT ANY ERRORS IN THE PROGRAM WILL BE
 * CORRECTED.  NO ORAL OR WRITTEN ADVICE PROVIDED BY ELECTRONIC ARTS OR
 * ANY AUTHORIZED REPRESENTATIVE SHALL CREATE A WARRANTY.  SOME
 * JURISDICTIONS DO NOT ALLOW THE EXCLUSION OF OR LIMITATIONS ON IMPLIED
 * WARRANTIES OR THE LIMITATIONS ON THE APPLICABLE STATUTORY RIGHTS OF A
 * CONSUMER, SO SOME OR ALL OF THE ABOVE EXCLUSIONS AND LIMITATIONS MAY
 * NOT APPLY TO YOU.
 */

/** 
 * @file callback.cpp
 * @brief Implementation of the Callback interface for Micropolis game
 * engine.
 *
 * This file provides the implementation of the Callback class defined
 * in callback.h. It includes a series of methods that are called by
 * the Micropolis game engine to interact with the user interface.
 * These methods include functionalities like logging actions,
 * updating game states, and responding to user actions. The use of
 * EM_ASM macros indicates direct interaction with JavaScript, typical
 * in a web environment using Emscripten.
 */


////////////////////////////////////////////////////////////////////////


#include "micropolis.h"


class ConsoleCallback : Callback {

public:

    virtual ~ConsoleCallback() {
        EM_ASM({
            console.log('~ConsoleCallback destructor');
        });
    }

    virtual void autoGoto(Micropolis *micropolis, emscripten::val callbackVal, int x, int y, std::string message) override {
        EM_ASM_({
            console.log('autoGoto:', 'micropolis:', $0, 'callbackVal:', $1, 'x:', $2, 'y:', $3, 'message:', UTF8ToString($4));
        }, micropolis, callbackVal, x, y, message.c_str());
    }

    virtual void didGenerateMap(Micropolis *micropolis, emscripten::val callbackVal, int seed) override {
        EM_ASM_({
            console.log('didGenerateMap:', 'micropolis:', $0, 'callbackVal:', $1, 'seed:', $2);
        }, micropolis, callbackVal, seed);
    }

    virtual void didLoadCity(Micropolis *micropolis, emscripten::val callbackVal, std::string filename) override {
        EM_ASM_({
            console.log('didLoadCity:', 'micropolis:', $0, 'callbackVal:', $1, 'filename:', UTF8ToString($2));
        }, micropolis, callbackVal, filename.c_str());
    }

    virtual void didLoadScenario(Micropolis *micropolis, emscripten::val callbackVal, std::string name, std::string fname) override {
        EM_ASM_({
            console.log('didLoadScenario:', 'micropolis:', $0, 'callbackVal:', $1, 'name:', UTF8ToString($2), 'fname:', UTF8ToString($3));
        }, micropolis, callbackVal, name.c_str(), fname.c_str());
    }

    virtual void didLoseGame(Micropolis *micropolis, emscripten::val callbackVal) override {
        EM_ASM_({
            console.log('didLoseGame:', 'micropolis:', $0, 'callbackVal:', $1);
        }, micropolis, callbackVal);
    }

    virtual void didSaveCity(Micropolis *micropolis, emscripten::val callbackVal, std::string filename) override {
        EM_ASM_({
            console.log('didSaveCity:', 'micropolis:', $0, 'callbackVal:', $1, 'filename:', UTF8ToString($2));
        }, micropolis, callbackVal, filename.c_str());
    }

    virtual void didTool(Micropolis *micropolis, emscripten::val callbackVal, std::string name, int x, int y) override {
        EM_ASM_({
            console.log('didTool:', 'micropolis:', $0, 'callbackVal:', $1, 'name:', UTF8ToString($2), 'x:', $3, 'y:', $4);
        }, micropolis, callbackVal, name.c_str(), x, y);
    }

    virtual void didWinGame(Micropolis *micropolis, emscripten::val callbackVal) override {
        EM_ASM_({
            console.log('didWinGame:', 'micropolis:', $0, 'callbackVal:', $1);
        }, micropolis, callbackVal);
    }

    virtual void didntLoadCity(Micropolis *micropolis, emscripten::val callbackVal, std::string filename) override {
        EM_ASM_({
            console.log('didntLoadCity:', 'micropolis:', $0, 'callbackVal:', $1, 'filename:', UTF8ToString($2));
        }, micropolis, callbackVal, filename.c_str());
    }

    virtual void didntSaveCity(Micropolis *micropolis, emscripten::val callbackVal, std::string filename) override {
        EM_ASM_({
            console.log('didntSaveCity:', 'micropolis:', $0, 'callbackVal:', $1, 'filename:', UTF8ToString($2));
        }, micropolis, callbackVal, filename.c_str());
    }

    virtual void makeSound(Micropolis *micropolis, emscripten::val callbackVal, std::string channel, std::string sound, int x, int y) override {
        EM_ASM_({
            console.log('makeSound:', 'micropolis:', $0, 'callbackVal:', $1, 'channel:', UTF8ToString($2), 'sound:', UTF8ToString($3), 'x:', $4, 'y:', $5);
        }, micropolis, callbackVal, channel.c_str(), sound.c_str(), x, y);
    }

    virtual void newGame(Micropolis *micropolis, emscripten::val callbackVal) override {
        EM_ASM_({
            console.log('newGame:', 'micropolis:', $0, 'callbackVal:', $1);
        }, micropolis, callbackVal);
    }

    virtual void saveCityAs(Micropolis *micropolis, emscripten::val callbackVal, std::string filename) override {
        EM_ASM_({
            console.log('saveCityAs:', 'micropolis:', $0, 'callbackVal:', $1, 'filename:', UTF8ToString($2));
        }, micropolis, callbackVal, filename.c_str());
    }

    virtual void sendMessage(Micropolis *micropolis, emscripten::val callbackVal, int messageIndex, int x, int y, bool picture, bool important) override {
        EM_ASM_({
            console.log('sendMessage:', 'micropolis:', $0, 'callbackVal:', $1, 'messageIndex:', $2, 'x:', $3, 'y:', $4, 'picture:', $5, 'important:', $6);
        }, micropolis, callbackVal, messageIndex, x, y, picture, important);
    }

    virtual void showBudgetAndWait(Micropolis *micropolis, emscripten::val callbackVal) override {
        EM_ASM_({
            console.log('showBudgetAndWait:', 'micropolis:', $0, 'callbackVal:', $1);
        }, micropolis, callbackVal);
    }

    virtual void showZoneStatus(Micropolis *micropolis, emscripten::val callbackVal, int tileCategoryIndex, int populationDensityIndex, int landValueIndex, int crimeRateIndex, int pollutionIndex, int growthRateIndex, int x, int y) override {
        EM_ASM_({
            console.log('showZoneStatus:', 'micropolis:', $0, 'callbackVal:', $1, 'tileCategoryIndex:', $2, 'populationDensityIndex:', $3, 'landValueIndex:', $4, 'crimeRateIndex:', $5, 'pollutionIndex:', $6, 'growthRateIndex:', $7, 'x:', $8, 'y:', $9);
        }, micropolis, callbackVal, tileCategoryIndex, populationDensityIndex, landValueIndex, crimeRateIndex, pollutionIndex, growthRateIndex, x, y);
    }

    virtual void simulateRobots(Micropolis *micropolis, emscripten::val callbackVal) override {
        EM_ASM_({
            console.log('simulateRobots:', 'micropolis:', $0, 'callbackVal:', $1);
        }, micropolis, callbackVal);
    }

    virtual void simulateChurch(Micropolis *micropolis, emscripten::val callbackVal, int posX, int posY, int churchNumber) override {
        EM_ASM_({
            console.log('simulateChurch:', 'micropolis:', $0, 'callbackVal:', $1, 'posX:', $2, 'posY:', $3, 'churchNumber:', $4);
        }, micropolis, callbackVal, posX, posY, churchNumber);
    }

    virtual void startEarthquake(Micropolis *micropolis, emscripten::val callbackVal, int strength) override {
        EM_ASM_({
            console.log('startEarthquake:', 'micropolis:', $0, 'callbackVal:', $1, 'strength:', $2);
        }, micropolis, callbackVal, strength);
    }

    virtual void startGame(Micropolis *micropolis, emscripten::val callbackVal) override {
        EM_ASM_({
            console.log('startGame:', 'micropolis:', $0, 'callbackVal:', $1);
        }, micropolis, callbackVal);
    }

    virtual void startScenario(Micropolis *micropolis, emscripten::val callbackVal, int scenario) override {
        EM_ASM_({
            console.log('startScenario:', 'micropolis:', $0, 'callbackVal:', $1, 'scenario:', $2);
        }, micropolis, callbackVal, scenario);
    }

    virtual void updateBudget(Micropolis *micropolis, emscripten::val callbackVal) override {
        EM_ASM_({
            console.log('updateBudget:', 'micropolis:', $0, 'callbackVal:', $1);
        }, micropolis, callbackVal);
    }

    virtual void updateCityName(Micropolis *micropolis, emscripten::val callbackVal, std::string cityName) override {
        EM_ASM_({
            console.log('updateCityName:', 'micropolis:', $0, 'callbackVal:', $1, 'cityName:', UTF8ToString($2));
        }, micropolis, callbackVal, cityName.c_str());
    }

    virtual void updateDate(Micropolis *micropolis, emscripten::val callbackVal, int cityYear, int cityMonth) override {
        EM_ASM_({
            console.log('updateDate:', 'micropolis:', $0, 'callbackVal:', $1, 'cityYear:', $2, 'cityMonth:', $3);
        }, micropolis, callbackVal, cityYear, cityMonth);
    }

    virtual void updateDemand(Micropolis *micropolis, emscripten::val callbackVal, float r, float c, float i) override {
        EM_ASM_({
            console.log('updateDemand:', 'micropolis:', $0, 'callbackVal:', $1, 'r:', $2, 'c:', $3, 'i:', $4);
        }, micropolis, callbackVal, r, c, i);
    }

    virtual void updateEvaluation(Micropolis *micropolis, emscripten::val callbackVal) override {
        EM_ASM_({
            console.log('updateEvaluation:', 'micropolis:', $0, 'callbackVal:', $1);
        }, micropolis, callbackVal);
    }

    virtual void updateFunds(Micropolis *micropolis, emscripten::val callbackVal, int totalFunds) override {
        EM_ASM_({
            console.log('updateFunds:', 'micropolis:', $0, 'callbackVal:', $1, 'totalFunds:', $2);
        }, micropolis, callbackVal, totalFunds);
    }

    virtual void updateGameLevel(Micropolis *micropolis, emscripten::val callbackVal, int gameLevel) override {
        EM_ASM_({
            console.log('updateGameLevel:', 'micropolis:', $0, 'callbackVal:', $1, 'gameLevel:', $2);
        }, micropolis, callbackVal, gameLevel);
    }

    virtual void updateHistory(Micropolis *micropolis, emscripten::val callbackVal) override {
        EM_ASM_({
            console.log('updateHistory:', 'micropolis:', $0, 'callbackVal:', $1);
        }, micropolis, callbackVal);
    }

    virtual void updateMap(Micropolis *micropolis, emscripten::val callbackVal) override {
        EM_ASM_({
            console.log('updateMap:', 'micropolis:', $0, 'callbackVal:', $1);
        }, micropolis, callbackVal);
    }

    virtual void updateOptions(Micropolis *micropolis, emscripten::val callbackVal) override {
        EM_ASM_({
            console.log('updateOptions:', 'micropolis:', $0, 'callbackVal:', $1);
        }, micropolis, callbackVal);
    }

    virtual void updatePasses(Micropolis *micropolis, emscripten::val callbackVal, int passes) override {
        EM_ASM_({
            console.log('updatePasses:', 'micropolis:', $0, 'callbackVal:', $1, 'passes:', $2);
        }, micropolis, callbackVal, passes);
    }

    virtual void updatePaused(Micropolis *micropolis, emscripten::val callbackVal, bool simPaused) override {
        EM_ASM_({
            console.log('updatePaused:', 'micropolis:', $0, 'callbackVal:', $1, 'simPaused:', $2);
        }, micropolis, callbackVal, simPaused);
    }

    virtual void updateSpeed(Micropolis *micropolis, emscripten::val callbackVal, int speed) override {
        EM_ASM_({
            console.log('updateSpeed:', 'micropolis:', $0, 'callbackVal:', $1, 'speed:', $2);
        }, micropolis, callbackVal, speed);
    }

    virtual void updateTaxRate(Micropolis *micropolis, emscripten::val callbackVal, int cityTax) override {
        EM_ASM_({
            console.log('updateTaxRate:', 'micropolis:', $0, 'callbackVal:', $1, 'cityTax:', $2);
        }, micropolis, callbackVal, cityTax);
    }

};


////////////////////////////////////////////////////////////////////////
